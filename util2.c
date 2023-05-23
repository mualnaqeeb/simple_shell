#include "shell.h"

/**
 * is_numerical - Check if is a digit
 *
 * @n: Number
 *
 * Return: If is a number, return 1 else return 0
 */
int is_numerical(unsigned int n)
{
	return (n >= '0' && n <= '9');
}

/**
 * _atoi - Convert a string to a number
 *
 * @s: String to convert
 *
 * Return: Return the number
 */
int _atoi(char *s)
{
	unsigned int number, i;
	int sign;

	sign = 1;
	number = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (is_numerical(s[i]))
		{
			number = (s[i] - 48)	+ number * 10;

			if (s[i + 1] == ' ')
				break;
		}
		else if (s[i] == '-')
		{
			sign *= -1;
		}

	}

	return (number * sign);
}

/**
 * contains_letter - Search non-digits in a string
 *
 * @s: String for search
 *
 * Return: If a non-digits was found, return _TRUE
 * if not, return _FALSE
 **/
int contains_letter(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (is_numerical(s[i]) == _FALSE)
			return (_TRUE);
	}

	return (_FALSE);
}
