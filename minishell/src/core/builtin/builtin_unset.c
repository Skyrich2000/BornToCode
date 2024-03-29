/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:26:55 by echung            #+#    #+#             */
/*   Updated: 2021/11/26 20:06:13 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/builtin.h"
#include "core/env/env.h"
#include "core/error.h"

static int	builtin_unset_with_value(char **argv, t_env *env)
{
	char	*key;
	char	*value;
	int		i;
	int		flag;

	i = 1;
	flag = 0;
	while (argv[i])
	{
		ft_get_key_and_value(argv[i], &key, &value);
		if (!ft_is_valid_key(key) || value)
		{
			error_message_for_unset(key, value);
			flag = 1;
		}
		else
			remove_env(env, key);
		free(key);
		free(value);
		i++;
	}
	return (flag);
}

int	builtin_unset(int argc, char **argv, t_env *env, int fd)
{
	int		exit_code;

	(void)fd;
	if (argc == 1)
		return (0);
	exit_code = builtin_unset_with_value(argv, env);
	return (exit_code);
}
