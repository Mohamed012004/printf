#include "main.h"

/**
 * get_specifier - find format func
 * @s: format string
 *
 * Return: the number of bytes printed
 */
int (*get_specifier(char *s)) (va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
			return (specifiers[i].f)
		i++;
	}
	return (NULL);
}
