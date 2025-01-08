#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/about.h"
#include "include/status.h"

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
		}
	}

	return 0;
}