#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_data
{
	int num;
	char chr;;
}   t_data;


// 쓰레드 함수
void *test(void *data)
{
	t_data** datas = data;

	printf("thread start\n");

	usleep(1000 * 1000 * 2);
	printf("sleep end\n");

	(*datas)[3].num = 10;
	(*datas)[8].chr = 'a';
	(*datas)[5].num = 10;
	(*datas)[1].chr = 'a';

	printf("thread end\n");

	return (void *)(100);
}

int main()
{
	t_data* datas;
	pthread_t thread_t;
	int *status;


	datas = malloc(1);
	
	for (int i = 0; i < 10; i ++)
	{
		if (pthread_create(&thread_t, NULL, test, (void *)&datas) < 0)
		{
			perror("thread create error:");
			exit(0);
		}
	}
	pthread_detach(thread_t);
	usleep(1000 * 1000 * 1);

	free(datas);
	datas = 0;
	

	printf("freed\n");

	usleep(1000 * 1000 * 3);
	printf("End %d\n", status);
	return 0;
}
