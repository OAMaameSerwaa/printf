#ifndef MAIN_H
#define MAIN_H
#define INT_BITS (4 * 8)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

/**
 * struct call - struct call
 * @t: t - flag for data type
 * @fn: function - assocated function
 */
typedef struct call
{
	char t;
	int (*fn)(char *, va_list, int);
} call_t;

int _printf(const char *format, ...);
int parse_R13(char *buff_dest, va_list arg, int buff_count);
int buff_append(char *buff_dest, va_list arg, int buff_count, char type);
int parse_rev(char *buff_dest, va_list arg, int buff_count);
int print_buff(char *buff, unsigned int nbuff);
int parse_uint(char *buff_dest, va_list arg, int buff_count);
int str_len(char *s);
int parse_X(char *buff_dest, va_list arg, int buff_count);
char *_strcpy(char *dest, char *src);
int parse_hex(char *buff_dest, va_list arg, int buff_count);
int parse_char(char *buff_dest, va_list arg, int buff_count);
int parse_oct(char *buff_dest, va_list arg, int buff_count);
int parse_str(char *buff_dest, va_list arg, int buff_count);
int parse_bin(char *buff_dest, va_list arg, int buff_count);
int parse_perc(char *buff_dest, va_list arg, int buff_count);
int parse_int(char *buff_dest, va_list list, int buff_count);

#endif
