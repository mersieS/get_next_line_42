#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    char **line;
    int fd;
    int c;
    int i;

    fd = open("test.txt", O_RDONLY);
    i = 0;
    while(get_next_line(fd) != NULL)
        i++;
    close(fd);
    fd = open("test.txt", O_RDONLY);
    line = malloc(i * sizeof(char *));
    c = 0;
    while(i > 0)
    {
        *line[c] = get_next_line(fd);
        c++;
        i--;
        free(line[c]);
    }
    while (i > 8)
        printf("%s", *line[i--]);
    free(line);
}