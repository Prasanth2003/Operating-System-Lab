//Program to perform file operations using system calls
/*To copy the content from f1.txt to f2.txt*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
void main()
{
	int fd1,fd2;
	char arr[]="hello world";
	/*Creation*/
	fd1=open("f1.txt",O_RDWR|O_CREAT,S_IRWXU);
	write(fd1,arr,strlen(arr));
	close(fd1);
	fd1=open("f1.txt",O_RDONLY,S_IRWXU);
	fd2=open("f2.txt",O_RDWR|O_CREAT,S_IRWXU);
	char readarr[100];
	int n=read(fd1,readarr,strlen(arr));
	write(fd2,readarr,n);
	write(1,readarr,n);
	close(fd1);
	close(fd2);
}