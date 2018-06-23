//
// Created by icebeetle on 18-6-22.
//

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int Just(int x) {
    for (int i = 2; i * i <= x; ++i)
        if (!x % 2)return 0;
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
    } else {
        printf("child_proc : %d\n", pid);
        wait(NULL);
    }
    return 0;
}