/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:28:47 by abazerou          #+#    #+#             */
/*   Updated: 2023/12/09 17:21:20 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    parsing(t_var *v)
{
    t_rgb rgb;

    v->rgb = &rgb;
    v->new_map = fill_empty(v->new_map, v);
    check_id(v);
    check_valid_chars(v->new_map, v);
	parse_path(v->new_map, v);
    get_player_pos(v);
}

int count_directions(char **map, t_var *v)
{
    int counter = 0;
    while (map[v->i])
    {
		v->j = 0;
		while (map[v->i][v->j])
		{
			if (map[v->i][v->j] == 'N' || map[v->i][v->j] == 'S' || map[v->i][v->j] == 'E' || map[v->i][v->j] == 'W')
				counter++;
			v->j++;
		}
		v->i++;
    }
	if (counter == 0 || counter > 1)
        return(1);
    return (0);
}

void    check_valid_chars(char **map, t_var *v)
{
    v->i = 0;
    v->j = 0;
    int found = 0;
    v->map_pos = 0;

    search_map(map, v);
    v->map_pos = v->i;
    while (map[v->i])
    {
        if (found == 1)
		    v->j = 0;
		while (map[v->i][v->j])
		{
			if (map[v->i][v->j] != '1' && map[v->i][v->j] != '0' && map[v->i][v->j] != 'N'
				&& map[v->i][v->j] != 'S' && map[v->i][v->j] != 'E' && map[v->i][v->j] != 'W' && map[v->i][v->j] != ' ')
					ft_puterror("Error: Invalid map\n", 2);
			v->j++;  
		}
        found = 1;
		v->i++;
    }
	v->i = v->map_pos;
    if (count_directions(map, v))
		ft_puterror("Error: Invalid map\n", 2);
}

void    check_ex(char *s)
{   
    int i = 0;
    i = ft_strlen(s);
    if(s[i - 4] == '.' && s[i - 3] == 'c' && s[i - 2] == 'u' && s[i - 1] == 'b')
        return ;
    else
        ft_puterror("Error in map extention!\n", 2);
}

char **fill_empty(char **map, t_var *v)
{
    v->i = 0;
    size_t j = 0;
    v->len_s = 0;
    while(v->i < v->map_len)
    {
        if(ft_strlen(map[v->i]) <= v->big_line)
        {
            j = 0;
            while(map[v->i][j] && map[v->i][j] != '\n')
                j++;
            map[v->i][j] = '\0';
            v->len_s = j;
            v->new_line = malloc(sizeof(char) * (v->big_line - j));
            if(!v->new_line)
                return(NULL);
            j = 0;
            map = join_space(map, v);
            free(v->new_line);
            v->new_line = NULL;
        }
        v->i++;
    }
    map[v->i] = NULL;
    return (map);
}
