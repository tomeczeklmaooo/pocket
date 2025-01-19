#ifndef FILE_H
#define FILE_H

extern char global_file[128];

void generate_filename(char* prefix, char* suffix);

extern char** file_content;
extern int lines_limit;

void write_file(char* filename, char* content, int overwrite_content);
void read_file(char* filename);
int get_line_count(char* filename);

#endif