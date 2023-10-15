#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE  1
#define CONVERT_UNSINGED   2

/**
 *struct parameters - parameters struct
 * @unsign: flag if unsigned value
 *
 * @plus_flag: on if plus_flag specified
 * @minus_flag: on if minus_flag specified
 * @space_flag: on if _flag specified
 * @hashtag_flag: on if _flag specified
 * @zero_flag: on if _flag specified
 *
 * @width: field width specified
 * @precision:	field precision specified
 *
 * @h_modifier: on if h_modifier specified
 * @l_modifier: on if l_modifier specified
 */
typedef struct parameters
{
	unsigned int unsign		: 1;

	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} params_t;

/**
 * struct specifier - struct token
 *
 * @specifier: format token
 * @f: the function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/* print_function.c module */
int print_char(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);

/* number.c module */
char *convert(long int num, int base, int flags, params_t *params);

/* specifier.c module */
int (*get_specifier(char *s)) (va_list ap, params_t *params);

/* print_number.c module */
int print_number(char *str, params_t *params);

/* _printf.c module */
int _printf(const char *format, ...);

#endif
