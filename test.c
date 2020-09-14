#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char buf[128] = {0};

int main(int argc, const char *argv[])
{
	int fd;
	if((fd = open("/dev/mycdev",O_RDWR)) < 0){
		perror("open");
		return -1;
	}

	read(fd,buf,sizeof(buf));
	printf("*****buf***** =%s ",buf);
	write(fd,buf,sizeof(buf));

	close(fd);
	return 0;
}
