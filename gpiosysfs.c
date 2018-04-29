#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{

	int repeat = 10;
	char buffer[3];
	int fd;
	
		
	

		printf("started\n");

	
		fd = open("/sys/db410c_gpio_led/led", O_WRONLY);
	
		if(-1 == fd) {
		
			fprintf(stderr, "Failed to open gpio sysfs file for writing\n");
			return (-1);
	
		}

	do{
		//snprintf(buffer, 1, "%d", repeat%2);	
		if(1 != write(fd, "1", 1)) {
			fprintf(stderr, "Failed to write to led\n");
			return (-1);	
		}
		sleep(1);
		if(1 != write(fd, "0", 1)) {
			fprintf(stderr, "Failed to write to led\n");
			return (-1);
		}
		sleep(1);
	}while(repeat--);
	close(fd);
	return 0;	
}
