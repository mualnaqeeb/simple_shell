#include "shell.h"
/**
 * replacement - searches directories in PATH variable for command
 * @info: general information
 * @index: index of PATH variable
 * @string: string to replace
 * Return: string with replaced variables
 */
char *replacement(general_t *info, int *index, char *string)
{
	char *tmp;
	char symbol;

	(void) index;

	symbol = *string;
	if (symbol != '?' && symbol != '$')
	{
		tmp = replace_env(info, string);
		return (tmp);
	}

	tmp = (symbol == '$') ? to_string(info->pid) :
		to_string(info->status_code);

	return (tmp);
}

/**
 * replace_env - replaces environment variables in string
 * @info: general information
 * @environment: environment variable
 * Return: string with replaced variables
*/
char *replace_env(general_t *info, char *environment)
{
	char *env;

	(void) info;

	env = _getenv(environment);
	if (env != NULL)
		return (env);

	return (NULL);
}
