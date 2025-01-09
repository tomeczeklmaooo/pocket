#include <stdio.h>
#include <string.h>

#include "include/file.h"

char file_content[MAX_FILE_LINE_AMT][MAX_FILE_LINE_LEN];

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

	if (fptr != NULL)
	{
		int i = 0;
		while (fgets(file_content[i], sizeof(file_content[i]), fptr))
		{
			// removing newline character, don't think this should be used tbh
			// file_content[i][strcspn(file_content[i], "\n")] = '\0';
			i++;

			if (i >= MAX_FILE_LINE_AMT)
			{
				printf("ERROR: Reached line limit of %d", MAX_FILE_LINE_AMT);
			}
		}
	}
	else
	{
		printf("ERROR: Unable to open file '%s'\n", filename);
	}

	fclose(fptr);
}

// it's literally the file reading function, but instead of writing to array, we're counting lines
int get_line_count(char* filename)
{
	FILE *fptr;
	int line_count = 0;
	char c;

	fptr = fopen(filename, "r");

	if (fptr != NULL)
	{
		while ((c = fgetc(fptr)) != EOF)
		{
			if (c == '\n')
			{
				line_count++;
			}
		}
	}
	else
	{
		printf("ERROR: Unable to open file '%s'\n", filename);
	}

	fclose(fptr);

	return line_count;
}