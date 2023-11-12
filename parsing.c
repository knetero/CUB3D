#include "stdio.h"
#include "stdlib.h"
#include <fcntl.h>
#include "get_next_line.h"


char **fill_empty(char **map)
{
    
}

int get_biggest_line(char **str)
{
    int i = 0;
    size_t len = 0;
    while(str[i])
    {
        if(ft_strlen(str[i]) > len)
            len = ft_strlen(str[i]);
        i++;
    }
    return (len);
}

void    ft_freetab(char **map)
{
    int i = 0;
    while(map[i])
        free(map[i++]);
    free(map);
}

void f(){
    system("leaks a.out");
}

int main()
{
    // atexit(f);
    int fd = open("map.txt", O_RDWR);
    if(fd == -1)
        puts("ERROR IN FILE");
    
    int len = 0;
    int big_line = 0;
    int i = 0;
    int fd1 = open("map.txt", O_RDWR);
    while(get_next_line(fd1))
        len++;
    close(fd1);
    char **map = malloc(sizeof(char **) * len + 1);
    if(!map){
        return(1);
    }
    map[i] = get_next_line(fd);
    while(map[i++])
    {
        map[i] = get_next_line(fd);
    }
    map[i] = NULL;
    i = 0;
    // while(str[i]){
    //     printf("%s", str[i++]);
    // }
    big_line = get_biggest_line(map);
    char **new_map = malloc(sizeof(char **) * big_line + 1);
    while(map[i])
    {
        new_map[i] = map[i];
        i++;
    }
    new_map[i] = NULL;
    i = 0;
    while(new_map[i])
    {
        printf("%s", new_map[i++]);
    }
    // new_map = fill_empty(new_map);
    ft_freetab(map);
    // ft_freetab(new_map);

    // while (1);
}