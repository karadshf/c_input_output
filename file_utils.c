/*
Farid Karadsheh
September 22nd, 2017
CIS 343-01
Grand Valley State University

Purpose: Read the contents of a text file, and print out the contents in reverse.

Associated files: reverse.c, file_utils.h
*/

#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"	

int read_file( char* filename, char **buffer ) {

	FILE* ipf; // input file
	if (!(ipf = fopen(filename,"rt"))) { // Defines "file" and opens it while checking for errors
		fprintf(stderr, "Error opening the file. Does \"%s\" exsist?", filename );
		return -1;
	}

	fseek(ipf, 0L, SEEK_END);  // Moves to end of file
	long size = ftell(ipf);    // Records size of file
	rewind(ipf);			    // Returns to beginning

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
	while(!feof(ipf)) {
		c=fgetc(ipf);
		*((*buffer) + i) = (char)c; // (*buffer) -> int main's buffer // *((*buffer) + i) modifys its contents, i.e. (*buffer)[i]
		i++;
    }

	fclose(ipf);

    return i;
}

int write_file( char* filename, char *buffer, int size) {

	FILE* opf; // output file
	if (!(opf = fopen(filename, "w"))) { // Defines "output" and opens it while checking or errors
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
    	fputc( (buffer[i]), opf);
    }

    fclose(opf);

}