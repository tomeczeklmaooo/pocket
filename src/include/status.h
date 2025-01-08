#ifndef STATUS_H
#define STATUS_H

typedef enum
{
	ST_NEGATIVE, // if expenses are larger than income
	ST_NODIFF, // if expenses are equal to income
	ST_POSITIVE // if expenses are lower than income
} Status;

void status();

#endif