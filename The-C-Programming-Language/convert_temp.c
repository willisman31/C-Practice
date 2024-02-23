#include <stdio.h>

int main(void) {
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 10;

	fahr = lower;
	while (fahr <= upper) {
		celsius = (fahr - 32) * 5.0 / 9.0;
		printf("%.2f\t%.2f\n", fahr, celsius);
		fahr += step;
	}

	return 0;
}

