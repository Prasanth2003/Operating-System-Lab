//Program to implement readdir and opendir
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
void main()
{
DIR *dir=opendir(".");
struct dirent *di;
if(dir==NULL)
{
printf("Not found\n");
exit(1);
}
else
{
while(di=readdir(dir))
{
printf("%s\n",di->d_name);
}
}
}
