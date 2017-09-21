#include <stdio.h>
#include "file_utils.h"

int main(int* argc, char** argv) {
	char* buffer = NULL;
	char* filename = "test.txt";

	read_file(filename, &buffer);

	return 0;
}