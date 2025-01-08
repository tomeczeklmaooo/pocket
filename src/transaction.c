#include <stdio.h>

#include "include/transaction.h"
#include "include/file.h"

void transaction(char mode, float amount, char place[32])
{
	char line[512];
	snprintf(line, sizeof(line), "%c;DD/MM/YYYY;%.2f;%s\n", mode, amount, place);

	write_file("test.txt", line, 0);
}