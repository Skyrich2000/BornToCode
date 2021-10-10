#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
    void            *data;
    struct s_list   *next;
}   t_list;

/**
 * 연결 리스트를 초기화합니다.
 *
 * @return 리스트 주소
 */
t_list  *init_list();

/**
 * 리스트의 마지막에 값을 추가합니다.
 *
 * @param list 리스트
 * @param data 값 (null 일 수 있다.)
 */
void    push_list(t_list *list, void *data);

// /**
//  * 리스트를 순서대로 순회하면서 주어진 함수를 호출합니다.
//  * 동시에 리스크의 크기를 잽니다.
//  *
//  * @param list 리스트
//  * @param f 순회하면서 호출될 함수 (NULL 일경우 호출안함)
//  * @param arg 호출될 함수로 넘기고 싶은 값 (없으면 NULL)
//  * @return 리스트 크기
//  */
// int iter_list(t_list *list, void f(void *data, void *arg), void *arg);

/**
 * 리스트의 메모리를 해제합니다.
 *
 * @param list 리스트
 * @param del 삭제시 호출될 함수
 */
void    free_list(t_list *list, void (*del)(void *data));

#endif
