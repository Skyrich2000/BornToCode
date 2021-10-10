#include "core/env.h"


int size_of_list(t_env *list)
{
	int size;
	t_env *node;

	node = list;
	size = 0;
	while (node)
	{
		++size;
		node = node->next;
	}
	return (size);
}

// 아웃풋 정상 출력되는지 확인 필요
void list_to_arr(t_env *list)
{
	char **output;
	int idx;

	output = malloc(sizeof(char *) * size_of_list(list));
	if (!output)
		exit(12);
	idx = -1;
	while (output[++idx])
	{
		output[idx] = strjoin(/* key  + `=` + value */);
	}
	return (output);
}

void run_execve(t_env *list)
{
	/* fork
	**  ㄴ parent :  자식 프로세스의 상태 확인 및 malloc 해준 변수를 free 해줌
	**  ㄴ child  : 실제로 명령어를 실행하는 프로세스
	*/
	fork()
	
	/*
	** envp list 를 char ** 로 바꿔야함!
	** execve의 세번째 인자.
	*/
	char ** env_arr = list_to_arr(list);
	
	/*
	** envp list에서 path를 찾아서 `:` 를 기준으로 스플릿해야함
	** execve의 첫번째 인자
	*/
	split_path(/* path */ , ':');


	if (/* parent */)
	{
		// wait child
		// free contents
		// error check
	}
	else
	{
		// 첫번째 인자가 패스면 인자를 패스자리에 넣기!
		while (/* 파싱된 path의 개수만큼 */)
		{
			// strjoin 두번써야함 free 해줘야함..
			strjoin(/* path + `/` + command */);
			execve(/* path + `/` + command */ , /* argument */, /* char ** environment value */);
		}
	}
}

void run_command()
{
	if (/* builtin */)
	{
		/* builtin function
		** argument의 command를 기준으로 비교
		** echo, cd, export, env, exit, pwd, unset
		*/
	}
	else
	{
		// run_execve()
	}
}

void excute(char **line)
{

	// 파이프로 나눠지는 명령어 개수를 찾아야함. 
	count_command()

	if (/* command 개수 1개 이상이면 */)
	{
		while (/* pipe 명령어 갯수만큼 */)
		{
			pipe();
			fork();
		}
	}


	if (/* command 개수 1개 이상 || 부모 프로세스 */)
	{
		// wait child
		// pipe fd close
	}
	else
	{
		run_command();
	}
}