/*
Farid Karadsheh
September 22nd, 2017
CIS 343-01
Grand Valley State University

Purpose: Read the contents of a text file, and print out the contents in reverse.

Associated files: file_utils.c, reverse.c
*/

#ifndef H_FILE_UTILS
#define H_FILE_UTILS

int read_file( char* filename, char **buffer );
int write_file( char* filename, char *buffer, int size);

#endif