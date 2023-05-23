#include "shell.h"

/**
 * _putchar_to_fd - Print a character to a specific file
 * descriptor
 *
 * @c: Character to print
 * @fd: Place to print the character
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 **/
int _putchar_to_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}


/**
 * print_to_fd - Print a string
 *
 * @msg: Strin to print in the fd specified
 * @fd: File descriptor to print
 *
 * Return: On success numbers of bytes printed.
 * On error, -1 is returned, and errno is set appropriately.
 **/
int print_to_fd(char *msg, int fd)
{
	int size;

	size = _strlen(msg);

	return (write(fd, msg, size));
}

/**
 * print_err - Print a message to STDERR
 *
 * @msg: Message to print
 *
 * Return: Number of bytes printed
 **/
int print_err(char *msg)
{
	return (print_to_fd(msg, STDERR));
}


/**
 * _putchar - Print a character to STDOUT
 *
 * @c: Character to print
 *
 * Return: On success 1
 * On error -1
 **/
int _putchar(char c)
{
	return (write(STDOUT, &c, 1));
}

/**
 * print - Print a message to STDOUT
 *
 * @msg: Message to print
 *
 * Return: On success number of bytes printed
 * On errror -1, and set the error
 **/
int print(char *msg)
{
	return (print_to_fd(msg, STDOUT));
}
