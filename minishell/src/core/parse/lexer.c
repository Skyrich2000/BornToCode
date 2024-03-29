/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 22:43:25 by echung            #+#    #+#             */
/*   Updated: 2021/11/24 19:36:28 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/parse/parse.h"
#include "core/error.h"

static int	get_type(char *str);

/**
 * 앞에서 부터 순회하면서
 * tokens 에 type 추론해서 넣기
 * type을 구해서
 *      arg 이면
 *          token 에 문자열 추가
 *      pipe 이면
 *          token 에 0 추가
 *      redir 이면
 *          다음 문자열이 arg이면 token 추가
 *      아니라면 에러
 *
 * @example strings : ['echo', 'hello', '>', 'abc', '|', 'cat', '<<' ,'abc']
 * @example tokens : [
 *  {type: T_ARG, value: 'echo'},
 *  {type: T_ARG, value: 'hello'},
 *  {type: T_REDIR, value: 'abc'},
 *  {type: T_PIPE, value: null},
 *  {type: T_CMD, value: 'cat'},
 *  {type: T_REDIR, value: 'abc'},
 * ]
 */

int	lexer(char **strings, t_list *tokens)
{
	int		index;
	int		type;
	char	*value;

	index = -1;
	while (strings[++index])
	{
		type = get_type(strings[index]);
		if (type == T_PIPE)
		{
			if (index - 1 < 0 || get_type(strings[index - 1]) != T_ARG)
				return (ft_error(ERR_PARSE_SYNTAX, 0));
			value = 0;
		}
		else if (type == T_ARG)
			value = ft_strdup(strings[index]);
		else if (strings[index + 1] && get_type(strings[index + 1]) == T_ARG)
			value = ft_strdup(strings[index++ + 1]);
		else
			return (ft_error(ERR_PARSE_SYNTAX, 0));
		push_list(tokens, init_token(type, value));
	}
	return (OK);
}

static int	get_type(char *str)
{
	if (ft_strncmp(str, "|", 1) == 0)
		return (T_PIPE);
	else if (ft_strncmp(str, "<<", 2) == 0)
		return (T_LEFT_DOUBLE_REDIR);
	else if (ft_strncmp(str, ">>", 2) == 0)
		return (T_RIGHT_DOUBLE_REDIR);
	else if (ft_strncmp(str, "<", 1) == 0)
		return (T_LEFT_REDIR);
	else if (ft_strncmp(str, ">", 1) == 0)
		return (T_RIGHT_REDIR);
	return (T_ARG);
}
