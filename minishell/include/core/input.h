#ifndef INPUT_H
# define INPUT_H

# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "define.h"

/**
 * 쉘을 입력 받습니다.
 * 
 * @param line 입력받은 문자열 저장할 주소
 * @return 성공하면 OK 실패하면 ERROR
 */
int input(char **line);

#endif