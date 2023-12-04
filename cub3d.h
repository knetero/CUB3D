#ifndef CUB3D_H
#define CUB3D_H

#include "stdio.h"
#include "stdlib.h"
#include <fcntl.h>
#include "get_next_line/get_next_line.h"



typedef struct s_var
{
    char **map;
    char **new_map;
    char *new_line;
    char *s;
    int fd;
    int fd1;
    int i;
    int j;
    int flag;
    int map_len;
    int map_pos;
    int player_pos;
    size_t big_line;
    size_t len_s;
}t_var;


void    parsing(t_var *v);
void	ft_puterror(char *s, int fd);
void    check_ex(char *s);
int     get_biggest_line(char **str);
void	parse_path(char **map, t_var *v);
int     check_right(char *map, int i);
int     check_left(char *map, int i);
int     check_up(char **map, int i, int j);
int     check_down(char **map, int i, int j, t_var *v);
char    **join_space(char **map, t_var *v);
int     count_directions(char **map, t_var *v);
void    ft_freetab(char **map);
void    get_map_len(t_var *v, char *str);
int     read_map(t_var *v);
char    **fill_empty(char **map, t_var *v);
void    check_valid_chars(char **map, t_var *v);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int	    ft_strcmp(char *s1, char *s2);
void    search_map(char **map, t_var *v);
int     check_digit(char **str, int i, int j);
int	    ft_isdigit(int c);
char	**ft_split(char const *s, char c);
int	    ft_atoi(const char *str);


#endif