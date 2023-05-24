#include "shell.h"

/**
 * interactive - true if inter
 * @info: addr of str
 * Return: if intr 1 else 0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - it make sure wheather d char isdeli
 * @c: the variable that would be cheched
 * @delim: d strg
 * Return: for true 1 and 4false 0
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabetic character it checks c
 * @c: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int x, _si = 1, _fl = 0, _out;
	unsigned int _re = 0;

	for (x = 0; s[i] != '\0' && _fl != 2; x++)
	{
		if (s[i] == '-')
			_si *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			_fl = 1;
			_re *= 10;
			_re += (s[i] - '0');
		}
		else if (_fl == 1)
			_fl = 2;
	}

	if (_si == -1)
		_out = -_re;
	else
		_out = _re;

	return (_out);
}
