#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"	

int read_file( char* filename, char **buffer ) {

	FILE* file;
	file = fopen(filename,"rt"); // Seeks end of file
	fseek(file, 0L, SEEK_END); // Moves to end of file
	long size = ftell(file);  // Records size of file
	rewind(file);				  // Returns to beginning

	char c;
	int i = 0;

	
	//buffer = malloc(size * sizeof(char));
	
	while((c=fgetc(file))!=EOF){
		printf("%c",c);
		**(buffer + i) = (char)c;
		i++;
    }

    for(i; i >= 0; i--) {
    	printf("%c", *(buffer + i));
    }

	fclose(file);
    return 0;
}

int write_file( char* filename, char *buffer, int size) {

}