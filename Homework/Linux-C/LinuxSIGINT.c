/*
 * @Date     : 2018/07/02
 * @Author   : IceCory (icecory520@gmail.com)
 * @Copyright(C): GPL 3.0
**/

#include <stdio.h>
#include <unistd.h> //sleep
#include <signal.h>

void Kill(int signo) {
    printf("ctrl+c will not work");
}

int main() {
    signal(SIGINT, Kill);
    sleep(100);
    return 0;
}