#include <stdio.h>

#include "include/show.h"
#include "include/file.h"
#include "include/parse.h"

void show()
{
	read_file(global_file);
	for (int i = 0; i < get_line_count(global_file); i++)
	{
		parse_line(file_content[i]);

		switch (line_parsed[0][0])
		{
			case 'I':
				printf("[\033[0;32m+++\t");
				break;
			case 'E':
				printf("[\033[0;31m---\t");
				break;
		}
		printf(
			"\033[0m%s] %s - %s",
			line_parsed[1],
			line_parsed[2],
			line_parsed[3]
		);

		printf("\n"); // new line at end of each line
	}
}