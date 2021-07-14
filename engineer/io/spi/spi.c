#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#define ARRAY_SIZE(array) sizeof(array)/sizeof(array[0])


int main(int argc, char **argv) 
{
	int i,fd;
	char wr_buf[]={0xff,0x00,0x1f,0x0f};
	char rd_buf[10];;

	if (argc<2) {
		printf("Usage:\n%s [device]\n", argv[0]);
		exit(1);
	}
   	
	fd = open(argv[1], O_RDWR);
	if (fd<=0) { 
		printf("%s: Device %s not found\n", argv[0], argv[1]);
		exit(1);
	}
	
	if (write(fd, wr_buf, ARRAY_SIZE(wr_buf)) != ARRAY_SIZE(wr_buf))
		perror("Write Error");
	if (read(fd, rd_buf, ARRAY_SIZE(rd_buf)) != ARRAY_SIZE(rd_buf))
		perror("Read Error");
	else
		for (i=0;i<ARRAY_SIZE(rd_buf);i++) {
		printf("0x%02X ", rd_buf[i]);
		if (i%2)
			printf("\n");
	}

	close(fd);
	return 0;
}