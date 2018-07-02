/*
 * @Date     : 2018/07/02
 * @Author   : IceCory (icecory520@gmail.com)
 * @Copyright(C): GPL 3.0
**/


#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int Just(int x) {
    for (int i = 2; i * i <= x; ++i)if (x % i == 0)return 0;
    return 1;
}

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork()");
        return -1;
    }
    if (pid == 0) {
        int sum = 0;
        for (int i = 2; i <= 100; ++i)
            sum += Just(i) ? i : 0;
        printf("%d\n", sum);
        printf("child_proc(%d, ppid=%d)\n", getpid(), getppid());
    } else wait(NULL);

    return 0;
}