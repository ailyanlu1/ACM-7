/*
 * @Date     : 2018/07/02
 * @Author   : IceCory (icecory520@gmail.com)
 * @Copyright(C): GPL 3.0
**/

#include <stdio.h>
#include <stdlib.h>

void copy(char *src, char *tar) {
    FILE *fpRead, *fpWrite;

    if (!(fpRead = fopen(src, "rb"))) {
        perror("src not exist!");
        exit(-1);
    }
    if (!(fpWrite = fopen(tar, "wb"))) {
        perror("tar not exist!");
        exit(-1);
    }
    char *buf = (char *) malloc(BUFSIZ);
    size_t readCnt = 0;
    while ((readCnt = fread(buf, 1, BUFSIZ, fpRead)) > 0)
        fwrite(buf, readCnt, 1, fpWrite);
    free(buf);
    fclose(fpRead);
    fclose(fpWrite);
}

int main(int argc, char *argv[]) {
    if (argc == 3) copy(argv[1], argv[2]);
    return 0;
}