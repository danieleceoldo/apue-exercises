#include "stdio.h"
#include "stdlib.h"
#include "sys/types.h"
#include "unistd.h"

int		glob = 6;		/* external variable in initialized data */

#define STR "HELLO WORLD!\n"
int
main(void)
{
	int		var;		/* automatic variable on the stack */
	pid_t	pid;

	var = 88;
	printf("before vfork\n");	/* we don't flush stdio */
	if ((pid = fork()) < 0) {
		perror("vfork error");
	} else if (pid == 0) {		/* child */
		glob++;					/* modify parent's variables */
		var++;
        fclose(stdout);
		exit(0);				/* child terminates */
	}

	/*
	 * Parent continues here.
	 */
	return printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
}
