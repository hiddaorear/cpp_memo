//
// Created by Wang Yifeng on 2019-05-10.
//

#include "csapp.h"
void *thread(void *vargp);

int main()
{
    pthread_t tid;
    Pthread_create(&tid, NULL, thread, NULL);
    Pthread_join(tid, NULL);
    exit(0);
}

void *thread(void *vargp)
{
    printf("Hello, World!\n");
    return NULL;
}