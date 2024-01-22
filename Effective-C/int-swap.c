#include <stdio.h>
#include <stdlib.h>

// void swap(int int);

int main(void) {
	int a = 21;
	int b = 17;

	swap(&a, &b);
	if (printf("main: a = %d, b = %d\n", a, b) > 0) {
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

/*
 * Here we could either swap by value or by pointer; in this example we swap by
 * pointer.  In effect, we can either swap the values or swap the pointers.
 */
void swap(int *pa, int *pb) {
	int t = *pa;
	*pa = *pb;
	*pb = t;
}

