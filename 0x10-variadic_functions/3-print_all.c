#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - prints anything
 * @format: list of types of arguments
 * Return: void
 */

void print_all(const char * const format, ...)
{
	int i = 0, check;
	char *str;
	va_list list;

	va_start(list, format);
	while (format != NULL && format[i] != '\0')
	{
		switch (format[i])
		{
			case 'c':
				printf("%c", va_arg(list, int));
				check = 0;
				break;
			case 'i':
				printf("%d", va_arg(list, int));
				check = 0;
				break;
			case 'f':
				printf("%f", va_arg(list, double));
				check = 0;
				break;
			case 's':
				str = va_arg(list, char *);
				if (str == NULL)
					str = "(nil)";
				printf("%s", str);
				check = 0;
				break;
			default:
				check = 1;
				break;
		}
		if (format[i + 1] != '\0' && check == 0)
			printf(",");
		i++;
	}
	printf("\n");
	va_end(list);
}
