#include <stdio.h>

#include "include/status.h"
#include "include/transaction.h"

void status()
{
	float income_sum = 0.0f;
	float expense_sum = 0.0f;

	for (int i = 0; i < income_table_act_size; i++)
	{
		income_sum += income_table[i];
	}
	for (int i = 0; i < expense_table_act_size; i++)
	{
		expense_sum += expense_table[i];
	}

	printf(
		"Total income sum: %.2f (in %d entries)\n",
		income_sum,
		income_table_act_size
	);
	printf(
		"Total expense sum: %.2f (in %d entries)\n",
		expense_sum,
		expense_table_act_size
	);

	float difference = income_sum - expense_sum;

	printf("Difference: ");
	if (difference < 0.0f)
	{
		printf("\033[0;31m%.2f\033[0m\n", difference);
	}
	else if (difference > 0.0f)
	{
		printf("\033[0;32m%.2f\033[0m\n", difference);
	}
}