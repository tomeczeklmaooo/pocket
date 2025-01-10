#ifndef TRANSACTION_H
#define TRANSACTION_H

extern float income_table[16384];
extern float expense_table[16384];
extern int income_table_act_size;
extern int expense_table_act_size;

void transaction(char* filename, char mode, float amount, char place[32]);
int get_values_from_array();

#endif