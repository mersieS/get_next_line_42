#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    char **line = (char **)malloc(sizeof(char *) * 16);

    int i = 0;

    while(i < 16)
    {
        line[i] = (char *)malloc(sizeof(char) * 100);
        i++;
    }

    i = 0;
    int fd = open("test.txt", O_RDONLY);
    while(i < 16){
        line[i] = get_next_line(fd);
        i++;
    }

    i = 15;
    while(i >= 0)
    {
        printf("%s", line[i]);
        i--;
    }
    free(line);
    close(fd);
}