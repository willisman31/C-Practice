#include "dbg.h"
#include <stdlib.h>
#include <stdio.h>

void test_debug() {
	debug("I have brown hair");
	debug("I am %d years old", 24);
}

void test_log_err() {
	log_err("I believe everything is broken");
	log_err("There are %d problems in %s", 0, "space");
}

void test_log_warn() {
	log_warn("This can be ignored");
	log_warn("THIS CANNOT");
}

void test_log_info() {
	log_info("Some information");
	log_info("info %d pieces of %s %s", 3, "useless", "data");
}

int test_check(char *file_name) {
	FILE *input = NULL;
	char *block = NULL;
	block = malloc(100);
	check_mem(block);

	input = fopen(file_name, "r");
	check(input, "Failed to %s", file_name);

	free(block);
	fclose(input);
	return 0;

	error:
		if (block) free(block);
		if (input) fclose(input);
		return -1;
}

int test_sentinel(int code) {
	char *temp = malloc(100);
	check_mem(temp);

	switch(code) {
		case 1:
			log_info("Success");
			break;
		default:
			sentinel("I should not be running");
	}

	free(temp);
	return 0;

	error:
		if (temp) free(temp);
		return -1;
}

int test_check_mem() {
	char *test = NULL;
	check_mem(test);
	free(test);
	return 1;
	error:
		return -1;
}

int test_check_debug() {
	int i = 0;
	check_debug(i != 0, "Oops, i was zero");
	return 0;
	error:
		return -1;
}

int main(int argc, char *argv[]) {
	check(argc == 2, "Need one argument");

	test_debug();
	test_log_err();
	test_log_warn();
	test_log_info();

	check(test_check("ex19.c") == 0, "Failed with ex19.c");
	check(test_check(argv[1]) == -1, "Failed with args");
	check(test_sentinel(1) == 0, "test_sentinel failed");
	check(test_sentinel(100) == -1, "test_sentinel failed");
	check(test_check_mem() == -1, "test_check_mem failed");
	check(test_check_debug() == -1, "text_check_debug failed");

	return 0;

	error:
		return -1;
}

