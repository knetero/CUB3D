#include "cub3d.h"

int check_down(char **map, int i, int j, t_var *v)
{
    while (i < v->map_len && map[i][j] != '1' && map[i][j] != ' ')
        i++;
    if (i < v->map_len && map[i][j] == '1')
        return (0);
    return(1);
}

int check_up(char **map, int i, int j)
{
    if (i == 0)
        return(1);
    while (map[i][j] && map[i][j] != '1' && map[i][j] != ' ')
        i--;
    if (map[i][j] == '1')
        return (0);
    return(1);
}

int check_left(char *map, int i)
{
    while (i > 0 && map[i] && map[i] != '1' && map[i] != ' ')
        i--;
    if (map[i] == '1')
        return (0);
    return(1);
}

int check_right(char *map, int i)
{

    while (map[i] && map[i] != '1' && map[i] != ' ')
        i++;
    if (map[i] == '1')
        return (0);
    return(1);
}

void	parse_path(char **map, t_var *v)
{
	int i = 0;
	int j = 0;
    // printf("%d\n", v->map_pos);
    i = v->map_pos;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
        {
            if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
            {
                if (check_right(map[i], j) == 1 || check_left(map[i], j) == 1)
                    ft_puterror("Error: the map is not closed\n", 2);
                if (check_up(map, i, j) == 1 || check_down(map, i, j, v) == 1)
                    ft_puterror("Error: the map is not closed\n", 2);
            }
			j++;
        }
		i++;
	}
}
