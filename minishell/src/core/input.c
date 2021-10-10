#include "core/input.h"

int	input(char **line)
{
    char *str;

	str = readline("minishell$ ");
	if (str)
		*line = str;
	else
		return (ERROR);
	add_history(str);
    return(OK);
}