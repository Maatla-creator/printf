#include "holberton.h"

/**
 * _printf - sends formatted output to stdout
 * @format: string that contains text to be written to stdout
 * Return: formatted data.
 */

int _printf(const char *format, ...)
{
	unsigned int i;
	char *str;
	int count = 0;
	/* Initialize the argument list. */
	va_list a;

	va_start(a, format);

	while (*format)
	{
		if (*format == '%')
		{
			/*Fetch arguments and execute*/
			format++;
			switch (*format)
			{
				/*Fetch character*/
				case 'c':
					i = va_arg(a, int);
					putchar(i);
					format++;
					count++;
					break;

					/*Fetch string*/
				case 's':
					str = va_arg(a, char*);
					fputs(str, stdout);
					format++;
					count += strlen(str);
					break;

				case '%':
					putchar('%');
					format++;
					count++;
					break;

				case '\0':
					break;

				default:
					putchar('%');
					putchar(*format);
					format++;
					count += 2;
			}
		}
		else
		{
			putchar(*format);
			format++;
			count++;
		}
	}
	/*clean up*/
	va_end(a);

	return (count);
}

