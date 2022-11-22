#include "main.h"

/**
 * _printf - Printf function
 * @format: format
 * Return: chars printed
 */
int _printf(const char *format, ...)
{
	int a = 0, b = 0, buff_count = 0, prev_buff_count = 0;
	char buffer[2000];
	va_list arg;
	call_t container[] = {
		{'c', parse_char}, {'s', parse_str}, {'i', parse_int}, {'d', parse_int},
		{'%', parse_perc}, {'b', parse_bin}, {'o', parse_oct}, {'x', parse_hex},
		{'X', parse_X}, {'u', parse_uint}, {'R', parse_R13}, {'r', parse_rev},
		{'\0', NULL}
	};

	if (!format)
		return (-1);
	va_start(arg, format);
	while (format && format[a] != '\0')
	{
		if (format[a] == '%')
		{
			a++, prev_buff_count = buff_count;
			for (b = 0; container[b].t != '\0'; b++)
			{
				if (format[a] == '\0')
					break;
				if (format[a] == container[b].t)
				{
					buff_count = container[b].f(buffer, arg, buff_count);
					break;
				}
			}
			if (buff_count == prev_buff_count && format[a])
				a--, buffer[buff_count] = format[a], buff_count++;
		}
		else
			buffer[buff_count] = format[a], buff_count++;
		a++;
	}
	va_end(arg);
	buffer[buff_count] = '\0';
	print_buff(buffer, buff_count);
	return (buff_count);
}
