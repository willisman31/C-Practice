#include <gnu/libc-version.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	printf("V %s\n", gnu_get_libc_version());
	printf("R %s\n", gnu_get_libc_release());
	return(EXIT_SUCCESS);
}

