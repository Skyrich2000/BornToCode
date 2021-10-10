#ifndef EXECUTE_H
# define EXECUTE_H

# define IN 0
# define OUT 1

# include "utils/list.h"

typedef struct s_proc
{
    char    *command;
    char    **arg;
    char    **envp;
    t_list  *fd_in;
    t_list  *fd_out;
}   t_proc;

/**
 * 명령어에 경로가 포함되어있는지 확인합니다.
 * 
 * @param command 명령어
 * @return 경로가 포함되면 TRUE, 아니면 FALSE
 */
int is_command_path(char *command);

/**
 * 명령어를 실행합니다.
 * 
 * @param cmd 명령어 구조체
 * @return 잘 실행하면 OK, 실패하면 ERR 번호
 */
int execute(t_list *cmds);

#endif