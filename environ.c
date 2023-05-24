#include "shell.h"

/**
 * _myenv - a function that shows envir
 * @info: parameter for prototype function.
 * Return: success 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - receive value of para
 * @info: parameter
 * @name: name of_vr
 *
 * Return: d resul
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *_po;

	while (node)
	{
		_po = starts_with(node->str, name);
		if (_po && *_po)
			return (_po);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - a function
 * @info: argmt
 *  Return: success 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - a function that eleminate var
 * @info: arg
 * Return: success 0
 */
int _myunsetenv(info_t *info)
{
	int y;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (y = 1; y <= info->argc; y++)
		_unsetenv(info, info->argv[y]);

	return (0);
}

/**
 * populate_env_list - a function
 * @info: arg
 * Return: success 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
