#include "main.h"
/**
 * _printf - print a formatted string to the standard output
 * @format: the format
 * Return: 0 on succes
 */
int _printf(const char *format, ...)
{
	unsigned int i, count = 0, s_count;
	va_list args;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			myputchar(format[i]);
		}
		else if (format[i + 1] == 'c')
		{
			myputchar(va_arg(args, int));
			i++;
		}
		else if (format[i + 1] == 's')
		{
			s_count = myputs(va_arg(args, char*));
			i++;
			count += (s_count - 1);
		}
		else if (format[i + 1] == '%')
		{
			myputchar('%');
			i++;
		}
		else if ((format[i + 1] == 'd') || (format[i + 1] == 'i'))
		{
			count += get_int(va_arg(args, int));
			i++;
		}
		count += 1;
	}
	va_end(args);
	return (count);
}
