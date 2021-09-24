#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 쓰레드 함수

void *test1(void *data)
{
    int i;
    int a = *(int *)data;
    printf("data -> : %d\n", a);
    for (i = 0; ; i++)
    {
        usleep(1000 * 100);
        printf("1 : %d\n", i*a);
    }
    return (void *)(size_t)(i * 100);
}

void *test2(void *data)
{
    int i;
    int a = *(int *)data;
    printf("data -> : %d\n", a);
    for (i = 0; i < 20; i++)
    {
        usleep(1000 * 100);
        printf("2 : %d\n", i*a);
    }
    return (void *)(size_t)(i * 100);
}

int main()
{
    int a = 100;
    pthread_t thread_t1;
    pthread_t thread_t2;
    int status;

    // 쓰레드를 생성한다.
    if (pthread_create(&thread_t1, NULL, test1, (void *)&a) < 0)
    {
        perror("thread create error:");
        exit(0);
    }
    if (pthread_create(&thread_t2, NULL, test2, (void *)&a) < 0)
    {
        perror("thread create error:");
        exit(0);
    }
    pthread_detach(thread_t1);

    usleep(1000 * 1000);

    pthread_join(thread_t2, (void **)&status);
	
    printf("Thread End %d\n", status); 
    return 0;
}