#include "minishell.h"
#include "core/env.h"
#include "core/input.h"
#include "core/execute.h"
#include "utils/list.h"
#include "utils/utils.h"
#include "core/parse.h"

void    start(char **envp)
{
	t_env	*env;
	t_list	*cmds;
	char	*line;

	env = init_env(envp);
	while (input(&line) == OK)
	{
		cmds = init_list();
		if (parse(line, cmds) != OK)
		{
			printf("에러남 ㅠ \n");
			continue ;
		}
		free(line);
		free_list(cmds, ft_free);
	}
	free(env);
}

int main(int argc, char **argv, char **envp)
{
	(void)argv;
	(void)argc;
	start(envp);
	return (0);
}