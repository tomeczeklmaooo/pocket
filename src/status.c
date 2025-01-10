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

	printf("Total income sum: %.2f\n", income_sum);
	printf("Total expense sum: %.2f\n", expense_sum);

	float difference = income_sum - expense_sum;

	printf("Difference: %.2f\n", difference);
}