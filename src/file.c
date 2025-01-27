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

void generate_filename(char* prefix, char* suffix)
{
	time_t t = time(NULL);
	struct tm *local_time = localtime(&t);
	
	uid_t uid = getuid();
	struct passwd *pw = getpwuid(uid);

	if (pw == NULL)
	{
		printf(
			"\033[0;31mERROR \033[0m[%s()]: getpwuid() failed to fetch home directory\n",
			__func__
		);
		return;
	}

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

char** file_content = NULL;
int lines_limit = 16;

// write to a file
void write_file(char* filename, char* content, int overwrite_content)
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
			return;
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
			return;
	}

	if (fptr == NULL)
	{
		printf(
			"\033[0;31mERROR \033[0m[%s()]: Unable to open file '%s'\n",
			__func__,
			filename
		);
		return;
	}

	fprintf(fptr, "%s", content);

	fclose(fptr);
}

// read from a file
// this should probably write each line to a dynamically sized array
// and then parse each line to write on screen (maybe idk)
void read_file(char* filename)
{
	FILE *fptr;

	fptr = fopen(filename, "r");

	if (fptr == NULL)
	{
		printf(
			"\033[0;31mERROR \033[0m[%s()]: Unable to open file '%s'\n",
			__func__,
			filename
		);
	}

	int i = 0;

	file_content = malloc(lines_limit * sizeof(char*));
	if (!file_content)
	{
		printf(
			"\033[0;31mERROR \033[0m[%s()]: Failed to allocate memory for file_content\n",
			__func__
		);
		fclose(fptr);
		return;
	}

	char line_buffer[128];

	while(fgets(line_buffer, sizeof(line_buffer), fptr))
	{
		if (i >= lines_limit)
		{
			lines_limit *= 2;
			char **temp = realloc(file_content, lines_limit * sizeof(char*));
			if (!temp)
			{
				printf(
					"\033[0;31mERROR \033[0m[%s()]: Failed to reallocate memory for file_content\n",
					__func__
				);
				return;
			}
			file_content = temp;
		}

		file_content[i] = malloc((strlen(line_buffer) + 1) * sizeof(char));
		if (!file_content[i])
		{
			printf(
				"\033[0;31mERROR \033[0m[%s()]: Failed to allocate memory for line in file_content\n",
				__func__
			);
			return;
		}

		strcpy(file_content[i], line_buffer);
		i++;
	}

	fclose(fptr);
}

// it's literally the file reading function, but instead of writing to array, we're counting lines
int get_line_count(char* filename)
{
	FILE *fptr;
	int line_count = 0;
	int c;

	fptr = fopen(filename, "r");

	if (fptr == NULL)
	{
		printf(
			"\033[0;31mERROR \033[0m[%s()]: Unable to open file '%s'\n",
			__func__,
			filename
		);
		return 0;
	}

	while ((c = fgetc(fptr)) != EOF)
	{
		if (c == '\n')
		{
			line_count++;
		}
	}

	fclose(fptr);

	return line_count;
}