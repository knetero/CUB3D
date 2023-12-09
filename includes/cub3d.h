#ifndef CUB3D_H
#define CUB3D_H

#include "stdio.h"
#include "stdlib.h"
#include <fcntl.h>
#include "../get_next_line/get_next_line.h"
#include "../Libft/libft.h"
#include "/Users/abazerou/Desktop/MLX42/include/MLX42/MLX42.h"

//****** PLAYER DIRECTION PATHS ******
typedef struct s_rgb
{
    int floor[3];
    int ceiling[3];
}t_rgb;

//******** PARSING STRUCT *****************
typedef struct s_var
{
    char **map;
    char **new_map;
    char *new_line;
    char **numbers;
    char *s;
    char *str[4];
    int fd;
    int fd1;
    int i;
    int j;
    int n;
    int x;
    int y;
    int index;
    int flag;
    int map_len;
    int map_pos;
    int player_pos;
    int flag_F;
    int flag_C;
    int start;
    size_t big_line;
    size_t len_s;
    t_rgb *rgb;
}t_var;

//****** PLAYER DIRECTION PATHS ******
typedef struct s_paths
{
    char *NO;
    char *SO;
    char *WE;
    char *EA;
}t_paths;

//******** MLX STRUCT *****************
typedef struct s_mlx
{
    mlx_t* mlx;
    mlx_image_t* image;
    int x;
    int y;
    t_var *v;

}t_mlx;

//************** PARSING *****************
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
void    count_id(t_var *v, int i, int j);
void    start_parser(t_var *v, int i, int j);
int     check_id(t_var *v);
void    get_player_pos(t_var *v);
int     is_comma(char **str, int i, int j);
int     check_digit(char **str, int i, int j);
int     check_after_d(char **str, int i, int j);
void    is_opened(char *s[]);
void    check_rgb_range(t_var *v, int i , int j);
void    is_range_valid(t_var *v, char **numbers);
void    is_rgb_valid(t_var *v);
void    check_id_help(t_var *v, int i, int n);
void    ft_free(char *s[]);


#endif