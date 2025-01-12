#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "include/transaction.h"
#include "include/file.h"
#include "include/parse.h"

float income_table[16384];
float expense_table[16384];
int income_table_act_size = 0;
int expense_table_act_size = 0;

void transaction(char* filename, char mode, float amount, char place[32])
{
	char line[512];
	time_t t = time(NULL);
	struct tm *local_time = localtime(&t);
	snprintf(
		line,
		sizeof(line),
		"%c;%02d/%02d/%04d;%.2f;%s\n",
		mode,
		local_time->tm_mday,
		local_time->tm_mon + 1,
		local_time->tm_year + 1900,
		amount,
		place
	);

	write_file(filename, line, 0);
}

int get_values_from_array()
{
	read_file(global_file);
	int income_idx = 0;
	int expense_idx = 0;

	for (int i = 0; i < get_line_count(global_file); i++)
	{
		parse_line(file_content[i]);

		switch (line_parsed[0][0])
		{
			case 'I':
			{
				float income_val = strtof(line_parsed[2], NULL);
				income_table[income_idx++] = income_val;
				income_table_act_size++;
				break;
			}
			case 'E':
			{
				float expense_val = strtof(line_parsed[2], NULL);
				expense_table[expense_idx++] = expense_val;
				expense_table_act_size++;
				break;
			}
			default:
				printf(
					"\033[0;31mERROR \033[0m[%s()]: Invalid transaction type in file at line %d!\n",
					__func__,
					i + 1
				);
				printf("Expected 0 or 1, actual value: %c\n", line_parsed[0][0]);
				return 1;
		}
	}

	return 0;
}