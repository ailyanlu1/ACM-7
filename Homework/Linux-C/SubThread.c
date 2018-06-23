//
// Created by icebeetle on 18-6-22.
//

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int Just(int x) {
    for (int i = 2; i * i <= x; ++i)
        if (!x % 2)return 0;
    return 1;
}

int ans;

void *go_thread(void *id) {
    int sum = 0;
    for (int i = 2; i <= 100; ++i)
        sum += Just(i) ? i : 0;
    ans = sum;
}

int main() {
    ans = 0;
    pthread_t tid = 0;
    pthread_create(&tid, NULL, go_thread, NULL);
    while (!ans)sleep(1);
    printf("%d\n", ans);
    pthread_exit(NULL);
    return 0;
}
//TARGET_LINK_LIBRARIES(ACM pthread)