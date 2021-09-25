#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// 쓰레드 함수
void *test(void *data)
{
    int i;
    int a = *(int *)data;
    for (i = 0; i < 10; i++)
    {
        usleep(1000 * 1000);
        printf("%d\n", i*a);
    }
    return (void *)(i * 100);
}

int main()
{
    int a[10];
    pthread_t thread_t;
    int *status;

    // 쓰레드를 생성한다. 
    if (pthread_create(&thread_t, NULL, test, (void *)&a) < 0)
    {
        perror("thread create error:");
        exit(0);
    }

    printf("Thread End %d\n", status);
    // how check..?
    return 0;
}