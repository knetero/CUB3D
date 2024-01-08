/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:27:36 by abazerou          #+#    #+#             */
/*   Updated: 2024/01/08 19:45:00 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	search_map(char **map, t_var *v)
{
	int	found;

	found = 0;
	while (map[v->i])
	{
		v->j = 0;
		while (map[v->i][v->j])
		{
			if (map[v->i][v->j] == ' ')
				v->j++;
			else if (map[v->i][v->j] == '1')
			{
				found = 1;
				v->j = 0;
				break ;
			}
			else
				break ;
		}
		if (found == 1)
			break ;
		v->i++;
	}
}

char	**join_space(char **map, t_var *v)
{
	size_t	j;

	j = 0;
	while (j < (v->big_line - v->len_s - 1))
	{
		v->new_line[j] = ' ';
		j++;
	}
	v->new_line[j] = '\0';
	map[v->i] = ft_strjoin(map[v->i], v->new_line);
	return (map);
}

int	get_biggest_line(char **str)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (ft_strlen(str[i]) > len)
			len = ft_strlen(str[i]);
		i++;
	}
	return (len);
}

void	get_map_len(t_var *v, char *str)
{
	v->fd1 = open(str, O_RDWR);
	v->s = get_next_line(v->fd1);
	while (v->s != NULL)
	{
		free(v->s);
		v->map_len++;
		v->s = get_next_line(v->fd1);
	}
	free(v->s);
	close(v->fd1);
	if (v->map_len == 0)
		ft_puterror("Error: the map is empty\n", 2);
}
