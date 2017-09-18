#include <stdio.h>
#include "file_utils.h"	

int read_file( char* filename, char **buffer ) {
	FILE *ifp =  fopen(filename, "r");
}

int write_file( char* filename, char *buffer, int size);