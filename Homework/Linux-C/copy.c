//
// Created by icebeetle on 18-6-22.
//

#include <stdio.h>
#include <stdlib.h>

int copy(char *src, char *tar) {
    FILE *fpRead, *fpWrite;

    if (!(fpRead = fopen(src, "rb"))) {
        perror("src not exist!");
        return -1;
    }
    if (!(fpWrite = fopen(tar, "wb"))) {
        perror("tar not exist!");
        return -1;
    }
    char *buf = (char *) malloc(BUFSIZ);
    size_t readCnt = 0;
    while ((readCnt = fread(buf, 1, BUFSIZ, fpRead)) > 0)
        fwrite(buf, readCnt, 1, fpWrite);
    free(buf);
    fclose(fpRead);
    fclose(fpWrite);
    return 0;
}

int main(int argc, char *argv[]) {

    copy("/home/icebeetle/Documents/tt1", "/home/icebeetle/Documents/tt2");

    return 0;
}