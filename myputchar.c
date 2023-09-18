#include <unistd.h>
#include "main.h"

/**
 * myputchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success
 * On error, -1 is returned, and errno is set appropriately.
 */
int myputchar(char c)
{
	return (write(1, &c, 1));
}
