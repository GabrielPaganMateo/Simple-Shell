#include "header.h"
/**
 * _printf - Produce output to stdout
 * @format: string that specifies how subsequent arguments
 * are converted for output
 * Return: the amount of characters printed
 */
int _printf(const char *format, ...)
{
	va_list a;
	int i = 0, char_count = 0;

	if (format == NULL)
		return (-1);
	va_start(a, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			while (format[++i] == ' ')
			;
			switch (format[i])
			{
				case 'c':
				char_count += print_char(va_arg(a, int));
				break;
				case 's':
				char_count += print_string(va_arg(a, char*));
				break;
				case 'd': case 'i':
				char_count += print_int(va_arg(a, int));
				break;
				case '%':
				char_count += print_percent();
				break;
				case '\0':
				return (-1);
				default:
				char_count += print_default(format[i]);
			}
		}
		else
		{
			char_count += print_char(format[i]);
		}
		i++;
	}
	va_end(a);
	return (char_count);
}

