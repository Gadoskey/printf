#include "main.h"
/**
 * myputs - prints a string
 * @str: string
 * Return: count
 */
int myputs(char *str)
{
	int count = 0, len = 0;

	if (str)
	{
		while (str[count] != '\0')
		{
			myputchar(str[count]);
			len += 1;
			count++;
		}
	}
	return (len);
}

