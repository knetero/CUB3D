/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:28:26 by abazerou          #+#    #+#             */
/*   Updated: 2024/01/01 10:16:26 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_path(t_var *v, char *s[])
{
	int		index;
	int		i;

	v->paths = malloc(sizeof(t_paths));
	if(!v->paths)
		ft_puterror("Error : Failed to allocate Path struct", 2);
	v->paths->no = NULL;
    v->paths->so = NULL;
    v->paths->we = NULL;
    v->paths->ea = NULL;
	index = 0;
	i = 0;
	while (index < 4)
	{
		i = 0;
		while (s[index][i])
		{
			if (s[index][i] == 'N' && s[index][i + 1] == 'O')
				v->paths->no = s[index];
			else if (s[index][i] == 'S' && s[index][i + 1] == 'O')
				v->paths->so = s[index];
			else if (s[index][i] == 'W' && s[index][i + 1] == 'E')
				v->paths->we = s[index];
			else if (s[index][i] == 'E' && s[index][i + 1] == 'A')
				v->paths->ea = s[index];
			i++;
		}
		index++;
	}
	printf("-------------> PATH : %s\n", v->paths->ea);
	printf("-------------> PATH : %s\n", v->paths->no);
	printf("-------------> PATH : %s\n", v->paths->we);
	printf("-------------> PATH : %s\n", v->paths->so);
}

void	p_validation_help(t_var *v, int i)
{
	while (v->new_map[i][v->n] && v->new_map[i][v->n] != ' ')
	{
		v->n++;
		v->x++;
	}
	while (v->new_map[i][v->n])
	{
		if (v->new_map[i][v->n] != ' ')
			ft_puterror("Error: in path\n", 2);
		v->n++;
	}
}

void	get_path(t_var *v, int i, int j)
{
	while (v->new_map[i][j] && v->new_map[i][j] != '/')
		j++;
	j++;
	v->n = j;
	p_validation_help(v, i);
	v->str[v->index] = ft_substr(v->new_map[i], j, v->x);
	if (v->index == 3)
	{
		v->flag = 1;
		return ;
	}
}

void	is_path_valid(t_var *v)
{
	v->v = 0;
	v->index = 0;
	v->flag = 0;
	while (v->v < v->i)
	{
		v->y = 0;
		v->n = 0;
		v->x = 0;
		while (v->new_map[v->v][v->y] && (v->new_map[v->v][v->y] == ' '
			|| v->new_map[v->v][v->y] == '\t'))
			v->y++;
		if (v->new_map[v->v][v->y] != '\0')
		{
			v->y = 0;
			get_path(v, v->v, v->y);
			if (v->flag == 1)
				break ;
			v->index++;
		}
		v->v++;
	}
	v->index++;
	v->str[v->index] = NULL;
	is_opened(v->str);
	init_path(v, v->str);
	ft_free(v->str);
}

int	check_id(t_var *v)
{
	v->x = 0;
	v->i = 0;
	v->flag = 0;
	search_map(v->new_map, v);
	while (v->x < v->i)
	{
		v->y = 0;
		v->n = 0;
		while (v->new_map[v->x][v->y] && (v->new_map[v->x][v->y] == ' '
			|| v->new_map[v->x][v->y] == '\t'))
			v->y++;
		if (v->new_map[v->x][v->y] != '\0')
		{
			while (v->new_map[v->x][v->y] && v->new_map[v->x][v->y] != '.')
				v->y++;
			while (v->new_map[v->x][v->n] && v->new_map[v->x][v->n] != ' ')
				v->n++;
			check_id_help(v, v->x, v->n);
		}
		v->x++;
	}
	if (v->flag < 6)
		return (ft_puterror("Error: identifier is missing!\n", 2), 1);
	is_path_valid(v);
	is_rgb_valid(v);
	return (0);
}
