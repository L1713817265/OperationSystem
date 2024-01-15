#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 10

int main(int argc, const char *argv[])
{
    /* 如果命令行参数个数不为3, 就报错 */
    if(argc != 3)
    {
        printf("argc param must be 3\n");
        return 0;
    }

    /* 源文件 */
    int fd = open(argv[1], O_RDWR);
    if (fd == -1)
    {
        perror("open error");
    }

    /* 目标文件 */
    int fdCopy = open(argv[2], O_RDWR | O_CREAT);
    if (fdCopy == -1)
    {
        perror("open error");
    }

    /* 读取文件，缓冲区 */
    char buffer[BUFFER_SIZE]; 
    memset(buffer, 0, sizeof(buffer));

    /* 文件打开 那文件指针默认在文件开头 */
    int readLen = 0;
    while (1)
    {
        readLen = read(fd, buffer, BUFFER_SIZE - 1);
        if(readLen == 0)
        {
            /* 说明文件读完了 */
            break;
        }
        write(fdCopy, buffer, readLen);
        if (readLen < BUFFER_SIZE - 1)
        {
            break;
        }
    }

    /* 关闭文件 */
    close(fd);
    close(fdCopy);

    return 0;
}