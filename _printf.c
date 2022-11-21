#include "main.h"

/**
 * _printf - Printf function
 * @format: format
 * Return: chars printed
 */
int _printf(const char *format, ...)
{
	int a = 0, b = 0, buff_ct = 0, prev_buff_ct = 0;
	char buffer[2000];
	va_list list;
	call_t container[] = {
		{'c', parse_char}, {'s', parse_str}, {'i', parse_int}, {'d', parse_int},
		{'%', parse_perc}, {'b', parse_bin}, {'o', parse_oct}, {'x', parse_hex},
		{'X', parse_X}, {'u', parse_uint}, {'R', parse_R13}, {'r', parse_rev},
		{'\0', NULL}
	};

	if (!format)
		return (-1);
	va_start(list, format);
	while (format && format[a] != '\0')
	{
		if (format[a] == '%')
		{
			a++, prev_buff_ct = buff_ct;
			for (b = 0; container[b].t != '\0'; b++)
			{
				if (format[a] == '\0')
					break;
				if (format[a] == container[b].t)
				{
					buff_ct = container[b].f(buffer, list, buff_ct);
					break;
				}
			}
			if (buff_ct == prev_buff_ct && format[a])
				a--, buffer[buff_ct] = format[a], buff_ct++;
		}
		else
			buffer[buff_ct] = format[a], buff_ct++;
		a++;
	}
	va_end(list);
	buffer[buff_ct] = '\0';
	print_buff(buffer, buff_ct);
	return (buff_ct);
}
