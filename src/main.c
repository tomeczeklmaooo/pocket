#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "include/about.h"
#include "include/status.h"
#include "include/transaction.h"
#include "include/file.h"
#include "include/show.h"

int main(int argc, char **argv)
{
	// functions to run always
	generate_filename("", "_list");

	// args
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
				get_values_from_array(); // reading float values from the file
				status();
			}
			else if (strcmp(argv[i], "add-inc") == 0)
			{
				for (int j = 0; j < (int)strlen(argv[i + 1]); j++)
				{
					if (isalpha(argv[i + 1][j]))
					{
						printf(
							"\033[0;31mERROR \033[0m[%s(): %s]: Character '%c' at position %d is not numeric!\n",
							__func__,
							argv[i],
							argv[i + 1][j],
							j
						);
						return 1;
					}
				}
				transaction(global_file, 'I', strtof(argv[i + 1], NULL), argv[i + 2]);
			}
			else if (strcmp(argv[i], "add-exp") == 0)
			{
				for (int j = 0; j < (int)strlen(argv[i + 1]); j++)
				{
					if (isalpha(argv[i + 1][j]))
					{
						printf(
							"\033[0;31mERROR \033[0m[%s(): %s]: Character '%c' at position %d is not numeric!\n",
							__func__,
							argv[i],
							argv[i + 1][j],
							j
						);
						return 1;
					}
				}
				transaction(global_file, 'E', strtof(argv[i + 1], NULL), argv[i + 2]);
			}
			else if (strcmp(argv[i], "show") == 0)
			{
				show();
			}
		}
	}

	return 0;
}