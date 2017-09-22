/*
Farid Karadsheh
September 22nd, 2017
CIS 343-01
Grand Valley State University

Purpose: Read the contents of a text file, and print out the contents in reverse.

Associated files: file_utils.c, file_utils.h
*/

#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"

int main(int argc, char* argv[]) {

	if (argc < 3) {
		fprintf( stderr, "Too few arguments. " );
		fprintf( stderr, "Please format like so:\n./reverse INPUT_FILENAME OUTPUT_FILENAME" );
		return -1;
	}

	if (argc > 3) {
		fprintf( stderr, "Too many arguments. " );
		fprintf( stderr, "Please format like so:\n./reverse INPUT_FILENAME OUTPUT_FILENAME" );
		return -1;
	}
	

	char* buffer = NULL;
	char* ipf = argv[1];
	char* opf = argv[2];
	int size;

	size = read_file(ipf, &buffer);
	write_file(opf, buffer, size);

	free(buffer);

	return 0;
}