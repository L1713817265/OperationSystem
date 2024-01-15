#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

/*todo*/
#define BUFFER_SIZE 5
int main(int argc, const char *argv)
{
    /* 如果命令行参数个数不为3, 就报错 */
    if(argc != 3)
    {
        printf("argc param must be 3\n");
        return 0;
    }

    /* 源文件 */
    int fd1 = open(argv[1], O_RDWR);
    if (fd1 == -1)
    {
        perror("open error");
    }

    /* 目标文件 */
    int fd2 = open(argv[2], O_RDWR | O_CREAT);
    if (fd2 == -1)
    {
        perror("open error");
    }
    /*读取文件，缓冲区*/
    char buffer[BUFFER_SIZE]; 
    memset(buffer, 0, sizeof(buffer));
    /*文件打开 那文件指针默认在文件开头*/
    int readLen = 0;
    while (1)
    {
        readLen = read(fd1, buffer, sizeof(buffer) - 1);
        if(readLen == 0)
        {
            break;
        }
        write(fd2, buffer, readLen);
        if (readLen < BUFFER_SIZE || readLen == 0)
        {
            break;
        }
    }
    close(fd1);
    close(fd2);

    return 0;
}