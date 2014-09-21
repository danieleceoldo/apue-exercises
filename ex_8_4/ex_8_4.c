#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int
main(void)
{
	pid_t	pid;

	if ((pid = fork()) < 0) {
		perror("fork error");
	} else if (pid == 0) {			/* child */
//		if (execlp("/home/daniele/Documents/development/c/apue-exercises/ex_8_4/testinterp",
		if (execlp("testinterp",
				  "testinterp", "myarg1", "MY ARG2", (char *)0) < 0)
			perror("execl error");
	}
	if (waitpid(pid, NULL, 0) < 0)	/* parent */
		perror("waitpid error");
	exit(0);
}
