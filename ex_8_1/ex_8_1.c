#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int		glob = 6;		/* external variable in initialized data */

int
main(void)
{
	int		var;		/* automatic variable on the stack */
	pid_t	pid;
    int i;
    char buf[BUFSIZ];

	var = 88;
	printf("before vfork\n");	/* we don't flush stdio */
	if ((pid = vfork()) < 0) {
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
	i = printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
    snprintf(buf, sizeof(buf), "%d\n", i);
    write(STDOUT_FILENO, buf, strlen(buf));

    exit(EXIT_SUCCESS);
}
