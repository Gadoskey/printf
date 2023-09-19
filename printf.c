#include "main.h"
/**
 * _printf - print a formatted string to the standard output
 * @format: the format
 * Return: 0 on succes
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
	{
		return (-1);
	}
	va_start(args, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
			{
				 write(1, buffer, buff_ind);
				 buff_ind = 0;
			}
			printed_chars++;
		}
		else
		{
			write(1, buffer, buff_ind);
			buff_ind = 0;
			flags = get_flags(format, &i);
			width = get_width(format, &i, args);
			precision = get_precision(format, &i, args);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, args, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	write(1, buffer, buff_ind);
	va_end(args);
	return (printed_chars);
}
