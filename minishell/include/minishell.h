/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 16:26:07 by echung            #+#    #+#             */
/*   Updated: 2021/09/12 16:31:50 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "define.h"
# include "utils/list.h"
# include "utils/utils.h"
# include "core/signal.h"
# include "core/parse/parse.h"
# include "core/execute/execute.h"

/**
 * 쉘을 입력 받습니다.
 *
 * @param line 입력받은 문자열 저장할 주소
 * @return 성공하면 OK 실패하면 ERROR
 */
int	input(char **line);

#endif
