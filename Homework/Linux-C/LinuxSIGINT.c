//
// Created by icebeetle on 18-6-22.
//

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


void Kill(int signo) {
    int t = 10;
    while (t--)
        printf("will be killed %d sec after\n", t);
    _exit(0);
}

int main() {
    signal(SIGINT, Kill);
    while (1);
    return 0;
}