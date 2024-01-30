#include <stdio.h>

int main (int argc, char* argv[]) {

	int i = 0;

	if (argc == 1) {
		printf("You have only one argument. You suck");
	} else if (argc > 1 && argc < 5) {
		printf("Here are your arguments: \n");
		for (i = 1; i < argc; i++) {
			printf("%s\n", argv[i]);
		}
	} else {
		printf("You have too many arguments.  You suck");
	}

	return 0;
}

