#include "shell.h"

/**
 * _eputs - a function that accept str
 * @str: variable 2b printed
 * Return: no value returned
 */
void _eputs(char *str)
{
	int itr = 0;

	if (!str)
		return;
	while (str[itr] != '\0')
	{
		_eputchar(str[itr]);
		itr++;
	}
}

/**
 * _eputchar - a function that print chr
 * @c: printed chr
 * Return: 1 4success else -1
 */
int _eputchar(char c)
{
	static int itr;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || itr >= WRITE_BUF_SIZE)
	{
		write(2, buf, itr);
		itr = 0;
	}
	if (c != BUF_FLUSH)
		buf[itr++] = c;
	return (1);
}

/**
 * _putfd - a function that accept fd as input
 * @c: the variable vlut 2bprinted
 * @fd: description 
 * Return: 1 for success else -1
 */
int _putfd(char c, int fd)
{
	static int itr;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || itr >= WRITE_BUF_SIZE)
	{
		write(fd, buf, itr);
		itr = 0;
	}
	if (c != BUF_FLUSH)
		buf[itr++] = c;
	return (1);
}

/**
 * _putsfd - a function that print input
 * @str: variable 2bprinted
 * @fd: description
 * Return: the amout of char
 */
int _putsfd(char *str, int fd)
{
	int itr = 0;

	if (!str)
		return (0);
	while (*str)
	{
		itr += _putfd(*str++, fd);
	}
	return (itr);
}
