#ifndef FILE_H
#define FILE_H

#define MAX_FILE_LINE_AMT 16384
#define MAX_FILE_LINE_LEN 128

// size is hardcoded because idk how to dynamically size arrays lol
extern char file_content[MAX_FILE_LINE_AMT][MAX_FILE_LINE_LEN];

int write_file(char* filename, char* content, int overwrite_content);
void read_file(char* filename);

#endif