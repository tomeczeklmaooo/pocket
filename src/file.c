#include <stdio.h>

#include "include/file.h"

// write to a file
int write_file(char* filename, char* content, int overwrite_content)
{
	FILE *fptr;

	switch (overwrite_content)
	{
		case 0:
			fptr = fopen(filename, "a");
			break;
		case 1:
			fptr = fopen(filename, "w");
			break;
		default:
			printf("ERROR: Invalid write_file() overwrite_content argument value!\n");
			printf("Expected 0 or 1, actual value: %d\n", overwrite_content);
			return 1;
	}

	fprintf(fptr, content);

	fclose(fptr);
	return 0;
}

// read from a file
// this should probably write each line to a dynamically sized array
// and then parse each line to write on screen (maybe idk)
void read_file(char* filename)
{
	FILE *fptr;

	fptr = fopen(filename, "r");

	char line_content[128];

	if (fptr != NULL)
	{
		while (fgets(line_content, sizeof(line_content), fptr))
		{
			printf("%s", line_content);
		}
	}
	else
	{
		printf("ERROR: Unable to open file '%s'\n", filename);
	}

	fclose(fptr);
}