#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"	

int read_file( char* filename, char **buffer ) {

	FILE* file;
	if (!(file = fopen(filename,"rt"))) { // Defines "file" and opens it while checking for errors
		fprintf(stderr, "Error opening the file. Does \"%s\" exsist?", filename );
		return -1;
	}

	fseek(file, 0L, SEEK_END);  // Moves to end of file
	long size = ftell(file);    // Records size of file
	rewind(file);			    // Returns to beginning

	int c;						// Placeholder for character reading
	int i = 0;					// Counter

	*buffer = malloc(1.67 * size * sizeof(char));

	if (*buffer == NULL) {
		fprintf(stderr, "Error allocating memory to buffer.\n");
		return -1;
	}
	
	/*
		Loops until the end of the file is reached
		Adds a single character to the buffer through each iteration.
	*/
	while(!feof(file)) {
		c=fgetc(file);
		*((*buffer) + i) = (char)c;
		i++;
    }

	fclose(file);

    return i;
}

int write_file( char* filename, char *buffer, int size) {

	FILE* output;
	if (!(output = fopen(filename, "w"))) { // Defines "output" and opens it while checking or errors
		fprintf( stderr, "Error creating output file.\n");
		return -1;
	}

	/*
		Prints the buffer in reverse, i.e. the text file in reverse.
		Substracting 2 is a hack that prevents the printing of two unwanted characters.
	*/
	int i = size - 2;
    for(i; i >= 0; i--) {
    	//printf("%c", (buffer[i]));
    	fputc( (buffer[i]), output);
    }

}