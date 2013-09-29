#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <errno.h>
#include <error.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>

int main(void)
{
	ssize_t n;
	off_t p;
	int fd;
	char buff[] = "string test";
	char buff2[] = "STRING TEST";

	if( (fd = open("test.txt", O_RDWR | O_APPEND)) < 0)
		error_at_line(EXIT_FAILURE, errno, __FILE__, __LINE__, "FATAL ERROR");

	if( ((p = lseek(fd, 0, SEEK_CUR)) == -1) && (errno!=0) )
		error_at_line(EXIT_FAILURE, errno, __FILE__, __LINE__, "FATAL ERROR");
	printf("Inital position: %d\n", p);

	if( ((p = lseek(fd, 0, SEEK_SET)) == -1) && (errno!=0) )
		error_at_line(EXIT_FAILURE, errno, __FILE__, __LINE__, "FATAL ERROR");
	printf("Position after positioning: %d\n", p);

	if( (n = read(fd, buff, sizeof(buff))) < 0)
		error_at_line(EXIT_FAILURE, errno, __FILE__, __LINE__, "FATAL ERROR");
	printf("Bytes read: %d, String read: %s\n", n, buff);

	if( ((p = lseek(fd, 0, SEEK_SET)) == -1) && (errno!=0) )
		error_at_line(EXIT_FAILURE, errno, __FILE__, __LINE__, "FATAL ERROR");
	printf("Position after positioning: %d\n", p);

	if( (n = write(fd, buff2, sizeof(buff2))) < 0)
		error_at_line(EXIT_FAILURE, errno, __FILE__, __LINE__, "FATAL ERROR");
	printf("Bytes written: %d\n", n);

	if( ((p = lseek(fd, 0, SEEK_CUR)) == -1) && (errno!=0) )
		error_at_line(EXIT_FAILURE, errno, __FILE__, __LINE__, "FATAL ERROR");
	printf("Final position: %d\n", p);
		
	exit(EXIT_SUCCESS);
}
