#include "shell.h"

/**
 * _strlen - Return the length of a string
 *
 * @msg: String to calculate length
 *
 * Return: Length of the string
 **/
int _strlen(char *msg)
{
	int i;

	for (i = 0; msg[i] != '\0'; i++)
		;

	return (i);
}

/**
 * _strcat - Concatenates two strings
 *
 * @dest: String concatenate
 * @src: Source string
 *
 * Return: A string concatenate
 */
char *_strcat(char *dest, char *src)
{
	int l_dest, i;

	l_dest = _strlen(dest);

	for (i = 0; src[i] != '\0'; i++, l_dest++)
		dest[l_dest] = src[i];

	dest[l_dest] = '\0';

	return (dest);
}

/**
 * _strcpy - Copy a string to another
 *
 * @dest: Destination copy
 * @src: Source for copy
 *
 * Return: Return the value of dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}


/**
 * _strdup - Pointer to a newly allocated space in memory
 *
 * @str: String to copy
 *
 * Return: String copied
 **/
char *_strdup(char *str)
{
	int size, i;
	char *dest;

	if (str == NULL)
		return (NULL);

	size = _strlen(str) + 1;
	dest = malloc(size * sizeof(char));
	if (dest == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		*(dest + i) = *(str + i);

	/* (dest + i) = 0; */

	return (dest);
}

/**
 * _strcmp - Compare two strings
 *
 * @s1: String 1
 * @s2: String 2
 *
 * Return: Integer
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}

	return (0);
}


/**
 * digits - Cout the numbe of digits of a number
 *
 * @n: Number
 *
 * Return: Digits
 **/
int digits(int n)
{
	int i;

	for (i = 0; n != 0; i++, n /= 10)
		;

	return (i);
}

/**
 * to_string - Conver @number to string
 *
 * @number: Number to convert
 *
 * Return: Number as string
 **/
char *to_string(int number)
{
	int n_digits, i;
	char *_number;

	n_digits = digits(number);
	_number = malloc(n_digits * sizeof(char) + 2);
	if (number == 0)
	{
		_number[0] = '0';
		_number[1] = '\0';
		return (_number);
	}
	/* Check NULL */

	_number[n_digits] = '\0';
	for (i = n_digits - 1; number != 0; number /= 10, i--)
		_number[i] = (number % 10) + '0';

	return (_number);
}


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
