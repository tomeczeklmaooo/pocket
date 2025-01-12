#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "include/file.h"

// change to whatever
char global_file[128];

int generate_filename(char* prefix, char* suffix)
{
	time_t t = time(NULL);
	struct tm *local_time = localtime(&t);
	
	uid_t uid = getuid();
	struct passwd *pw = getpwuid(uid);

	if (pw != NULL)
	{
		snprintf(
			global_file,
			sizeof(global_file),
			"%s/pocket_data/%s%04d%s.txt",
			pw->pw_dir,
			prefix,
			local_time->tm_year + 1900,
			suffix
		);
	}
	else
	{
		printf(
			"\033[0;31mERROR \033[0m[%s()]: getpwuid() failed to fetch home directory\n",
			__func__
		);
		return 1;
	}

	return 0;
}

char file_content[MAX_FILE_LINE_AMT][MAX_FILE_LINE_LEN];

// write to a file
int write_file(char* filename, char* content, int overwrite_content)
{
	FILE *fptr;

	uid_t uid = getuid();
	struct passwd *pw = getpwuid(uid);

	struct stat st;
	char path[256];

	snprintf(
		path,
		sizeof(path),
		"%s/pocket_data",
		pw->pw_dir
	);

	if (stat(path, &st) == -1)
	{
		if (mkdir(path, 0755) == -1)
		{
			printf(
				"\033[0;31mERROR \033[0m[%s()]: Failed to create directory '%s'\n",
				__func__,
				path
			);
			return 1;
		}
	}

	switch (overwrite_content)
	{
		case 0:
			fptr = fopen(filename, "a");
			break;
		case 1:
			fptr = fopen(filename, "w");
			break;
		default:
			printf(
				"\033[0;31mERROR \033[0m[%s()]: Invalid overwrite_content argument value\n",
				__func__
			);
			printf("Expected 0 or 1, actual value: %d\n", overwrite_content);
			return 1;
	}

	if (fptr != NULL)
	{
		fprintf(fptr, content);
	}
	else
	{
		printf(
			"\033[0;31mERROR \033[0m[%s()]: Unable to open file '%s'\n",
			__func__,
			filename
		);
	}

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
				printf(
					"\033[0;31mERROR \033[0m[%s()]: Reached line limit of %d",
					__func__,
					MAX_FILE_LINE_AMT
				);
			}
		}
	}
	else
	{
		printf(
			"\033[0;31mERROR \033[0m[%s()]: Unable to open file '%s'\n",
			__func__,
			filename
		);
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
		printf(
			"\033[0;31mERROR \033[0m[%s()]: Unable to open file '%s'\n",
			__func__,
			filename
		);
	}

	fclose(fptr);

	return line_count;
}