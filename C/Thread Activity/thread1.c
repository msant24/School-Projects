#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char *argv[])
{
   if(!(argc==2 || argc==4))
   {
       printf("Error....");
       exit(0);
   }
   else if(argc==2)
   {
       int fd=open(argv[1],O_CREAT | O_WRONLY,0666);
       char buffer[]="Logging info....";
       while(1)
       {
           write(fd,buffer,sizeof(buffer));
           sleep(1);
       }
       close(fd);
   }
   else
   {
       if(strcmp(argv[1],"-l")==0)
       {
           int fd=open(argv[3],O_CREAT | O_WRONLY,0666);
           while(1)
           {
               write(fd,argv[2],sizeof(argv[2])+1);
               sleep(1);
           }
           close(fd);
       }
       else
       {
           printf("Error....");
           exit(0);
       }
   }
}