#include "main.h"

/**
 * parse_R13 - substitute %R with argument number in rot13
 * @buff_dest: the string to change
 * @arg: char to change
 * @buff_count: index of dst where the R of %R is
 * Return: New index
 */
int parse_R13(char *buff_dest, va_list arg, int buff_count)
{
	char *s;
	char *keys = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *new = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	int i, j = 0;

	s = va_arg(arg, char *);
	while (s[j])
	{
		for (i = 0; keys[i]; i++)
		{
			if (s[j] == keys[i])
			{
				buff_dest[buff_count] = new[i];
				break;
			}
			buff_dest[buff_count] = s[j];
		}
		j++, buff_count++;
	}
	return (buff_count);
}
