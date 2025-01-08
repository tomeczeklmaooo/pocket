#ifndef FILE_H
#define FILE_H

int write_file(char* filename, char* content, int overwrite_content);
char* read_file(char* filename);

#endif