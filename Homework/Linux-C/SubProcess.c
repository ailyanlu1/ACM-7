/*
 * @Date     : 2018/07/02
 * @Author   : IceCory (icecory520@gmail.com)
 * @Copyright(C): GPL 3.0
**/


#include <stdio.h>
#include <unistd.h>

int Just(int x) {
    for (int i = 2; i * i <= x; ++i)if (x % i == 0)return 0;
    return 1;
}

int main() {
    int fd[2], sum = 0;
    pid_t pid;
    pipe(fd);

    if ((pid = fork()) < 0) {
        perror("fork()");
        return -1;
    } else if (pid == 0) { // getpid(), getppid()
        close(fd[0]);
        for (int i = 2; i <= 100; ++i)
            sum += Just(i) ? i : 0;
        write(fd[1], (void *) &sum, 4);
    } else {
        close(fd[1]);
        read(fd[0], (void *) &sum, 4);
        printf("%d\n", sum);
    }

    return 0;
}