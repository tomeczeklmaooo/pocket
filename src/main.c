#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/about.h"
#include "include/status.h"
#include "include/transaction.h"
#include "include/file.h"
#include "include/parse.h"

// change to whatever
char* global_file = "test.txt";

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("No arguments: exiting...\n");
		return 0;
	}
	else
	{
		for (int i = 0; i < argc; i++)
		{
			if (strcmp(argv[i], "about") == 0)
			{
				about();
			}
			else if (strcmp(argv[i], "status") == 0)
			{
				status();
			}
			else if (strcmp(argv[i], "add-inc") == 0)
			{
				transaction(global_file, 'I', strtof(argv[i + 1], NULL), argv[i + 2]);
			}
			else if (strcmp(argv[i], "add-exp") == 0)
			{
				transaction(global_file, 'E', strtof(argv[i + 1], NULL), argv[i + 2]);
			}
			else if (strcmp(argv[i], "show") == 0)
			{
				read_file(global_file);
				for (int i = 0; i < get_line_count(global_file); i++)
				{
					parse_line(file_content[i]);

					for (int j = 0; j < 4; j++)
					{
						printf("%s ", line_parsed[j]);
					}

					printf("\n"); // new line at end of each line
				}
			}
		}
	}

	return 0;
}