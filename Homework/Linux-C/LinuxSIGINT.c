/*
 * @Date     : 2018/07/02
 * @Author   : IceCory (icecory520@gmail.com)
 * @Copyright(C): GPL 3.0
**/

#include <stdio.h>
#include <signal.h>

void Kill(int signo) {
    printf("ctrl+c will not work\n");
    signal(SIGINT, SIG_DFL);
}

int main() {
    signal(SIGINT, Kill);
    while (1);
    return 0;
}