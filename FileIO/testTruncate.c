#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int ret = truncate("./heiheihei.c", 10);
    if(ret == -1)
    {
        perror("truncate error");
        return 0;
    }

    return 0;
}