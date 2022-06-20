#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
  
for(int i=0;i<5;i++)
{
if(fork() == 0)
{
for(int j=1;j<=6;j++)
{
printf("I am child %d and this is my %d message\n",getpid(),j);
sleep(3);
}
exit(0);
}
else
{
pid_t cpid;
cpid = wait(NULL);
printf("Exited Child pid = %d\n", cpid);
}
}
  
}
