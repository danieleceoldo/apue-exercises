#include <stdio.h>
#include <shadow.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    struct spwd *spwdp;

    if ((spwdp = getspnam(argv[1])) == NULL) {
        printf("Shadow password not found for name: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("Shadow password: %s\n", spwdp->sp_pwdp);
    exit(EXIT_SUCCESS);
}
