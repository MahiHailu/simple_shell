#include "shell.h"

/**
 * _myhistory - displays to history list, one command by line, preceded
 *              with line num, starting at 0.
 * @info:  struct containing potential argu.for constant function prototype.
 *  Return: always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - Sets alias in to string
 * @info: parameter struct
 * @str:  String alias
 *
 * Return: if success 0,  error 1.
 */
int unset_alias(info_t *info, char *str)
{
	char *q, s;
	int ret;

	q = _strchr(str, '=');
	if (!q)
		return (1);

	s = *q;
	*q = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*q = s;
	return (ret);
}

/**
 * set_alias - the code  sets alias in to string
 * @info: the parameter structure
 * @str: String alias
 *
 * Return: success 0, error 1
 */
int set_alias(info_t *info, char *str)
{
	char *q;

	p = _strchr(str, '=');
	if (!q)
		return (1);
	if (!*++q)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias -Prints an alias string in the code
 * @node: alias node
 *
 * Return: success 0, 1 error
 */
int print_alias(list_t *node)
{
	char *q = NULL, *b = NULL;

	if (node)
	{
		q = _strchr(node->str, '=');
		for (b = node->str; b <e= q; b++)
		_putchar(*b);
		_putchar('\'');
		_puts(q + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - Mimics to alias builtin
 * @info: struct containing argu. maintain function prototype.
 *  Return: always 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *q = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		q = _strchr(info->argv[i], '=');
		if (q)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
