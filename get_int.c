#include "main.h"
/**
 * get_int - print a formatted string to the standard output
 * @num: the format
 * Return: 0 on succes
 */
int get_int(int num)
{
	int rval= 0;

	if (num < 0)
	{
		myputchar('-');
		num = -num;
		rval++;
	}
	if (num == 0)
	{
		return (0);
	}
	else
	{
		rval += get_int(num / 10);
		myputchar(num % 10 + '0');
		rval ++;
	}
	return (rval);
}
