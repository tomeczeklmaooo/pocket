#include <stdio.h>
#include <string.h>

#include "include/parse.h"
#include "include/file.h"

char* line_parsed[4];

void parse_line(char* line)
{
	char* ch;
	int i = 0;
	ch = strtok(line, "\n;");
	
	while (ch != NULL)
	{
		line_parsed[i++] = ch;
		ch = strtok(NULL, "\n;");
	}
}