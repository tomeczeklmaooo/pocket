#include <stdio.h>
#include <time.h>

#include "include/transaction.h"
#include "include/file.h"

void transaction(char mode, float amount, char place[32])
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
		place);

	write_file("test.txt", line, 0);
}