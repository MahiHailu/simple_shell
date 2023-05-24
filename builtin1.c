#include "shell.h"

/**
 * _myhistory - it shows the history from 0
 * @info: argmnt dat maintain const func_prototype
 *  Return: success 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - it set another name
 * @info: argument
 * @str: d set of character
 * Return: 1 for unsuccess else 0
 */
int unset_alias(info_t *info, char *str)
{
	char *_po, _ch;
	int _re;

	_po = _strchr(str, '=');
	if (!_po)
		return (1);
	_ch = *_po;
	*_po = 0;
	_re = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*_po = _ch;
	return (_re);
}

/**
 * set_alias - give another name
 * @info: argument
 * @str: a set of char
 * Return: 1 for false and 0 for true
 */
int set_alias(info_t *info, char *str)
{
	char *_po;

	_po = _strchr(str, '=');
	if (!_po)
		return (1);
	if (!*++_po)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - display  set of character
 * @node: d node variable
 * Return: 0 on succs, 1 on er
 */
int print_alias(list_t *node)
{
	char *_po = NULL, *_al = NULL;

	if (node)
	{
		_po = _strchr(node->str, '=');
		for (_al = node->str; _al <= _po; _al++)
		_putchar(*_al);
		_putchar('\'');
		_puts(_po + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - my alias function
 * @info: arguments.
 * Return: if success 0
 */
int _myalias(info_t *info)
{
	int y = 0;
	char *_po = NULL;
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
	for (y = 1; info->argv[y]; y++)
	{
		_po = _strchr(info->argv[y], '=');
		if (p)
			set_alias(info, info->argv[y]);
		else
			print_alias(node_starts_with(info->alias, info->argv[y], '='));
	}

	return (0);
}
