/*
 * @Date     : 2018/07/02
 * @Author   : IceCory (icecory520@gmail.com)
 * @Copyright(C): GPL 3.0
**/


#include <stdio.h>
#include <pthread.h>

int Just(int x) {
    for (int i = 2; i * i <= x; ++i)if (x % i == 0)return 0;
    return 1;
}

void *go_thread(void *sum) {
    for (int i = 2; i <= 100; ++i)
        *(int *) sum += Just(i) ? i : 0;
}

int main() {
    int ans = 0;
    pthread_t tid = 0;
    pthread_create(&tid, NULL, go_thread, (void *) &ans);
    pthread_join(tid, NULL);
    printf("%d\n", ans);
    return 0;
}
//TARGET_LINK_LIBRARIES(ACM pthread)