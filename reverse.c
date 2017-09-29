/*
Farid Karadsheh
September 22nd, 2017
CIS 343-01
Grand Valley State University

Purpose: Read the contents of a text file, and print out the contents in reverse.

Associated files: file_utils.c, file_utils.h

errno.h
error.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_utils.h"

int main(int argc, char* argv[]) {
	// Two additional arguments are necessary for the program
	// Thus, argc must == 3
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

	int len = strlen(ipf); // length of the input file's name
	
	char ext[3];		   // 3 characters used to check the extension is .txt
	int i = len - 3;	   // Counter for ipf[]
	int j = 0;			   // Counter for ext[]
	for(i; i < len; i++) { // fills in the ext[] with the possible extension
		ext[j] = ipf[i];
		j++;
	}
	// Compares the extension of the file to what is expected.
	if(strcmp(ext, "txt") != 0) {
		fprintf( stderr, "Error: This program is intended to be used with \".txt\" files\n");
		return -1;
	}

	size = read_file(ipf, &buffer);
	write_file(opf, buffer, size);

	free(buffer);
	

	return 0;
}