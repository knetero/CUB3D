/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:41:31 by abazerou          #+#    #+#             */
/*   Updated: 2023/12/09 16:19:17 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    is_rgb_valid(t_var *v)
{
    int i;
    int j;

    i = 0;
    j = 0;
    v->flag = 0;
    v->flag_F = 0;
    v->flag_C = 0;
    while (i < v->i)
    {
        j = 0;
        while (v->new_map[i][j])
        {
            if (v->new_map[i][j] == 'C' || v->new_map[i][j] == 'F')
                start_parser(v, i, j);
            j++;
        }
        i++;
    }
    if (v->flag_C < 1 || v->flag_F < 1 )
        ft_puterror("Error: rgb identifiers is missing\n", 2);
}

void    is_range_valid(t_var *v, char **numbers)
{
    int i;
    int id_number;

    i = 0;
    id_number = 0;
    while (numbers[i])
    {
        id_number = ft_atoi(numbers[i]);
        if (id_number < 0 || id_number > 255)
        {
            ft_freetab(numbers);
            ft_puterror("Error: in rgb numbers\n", 2);
        }
        i++;
    }
    i = 0;
    while (i < 3)
    {
        id_number = ft_atoi(numbers[i]);
        if (v->flag != 1)
            v->rgb->floor[i] = id_number;
        else
            v->rgb->ceiling[i] = id_number;
        i++;
    }
    v->flag = 1;
}

void    check_rgb_range(t_var *v, int i , int j)
{
    int n;

    v->start = j;
    n = 0;
    while (v->new_map[i][j] && v->new_map[i][j] != ' ')
        j++;
    v->s = ft_substr(v->new_map[i], v->start, j);
    v->numbers = ft_split(v->s, ',');
    free(v->s);
    while(v->numbers[n])
    {
        if (ft_strcmp(v->numbers[n], "  ") == 0)
        {
            ft_freetab(v->numbers);
            ft_puterror("Error: in rgb numbers\n", 2);
        }
        n++;
    }
    if (n != 3)
    {
        ft_freetab(v->numbers);
        ft_puterror("Error: in rgb numbers\n", 2);
    }
    is_range_valid(v, v->numbers);
    ft_freetab(v->numbers);
}
void    start_parser(t_var *v, int i, int j)
{
    int start;

    start = 0;
    count_id(v, i, j);
    if (is_comma(v->new_map, i, j) == 1)
        ft_puterror("Error: in rgb numbers\n", 2);
    j++;
    while(v->new_map[i][j] && v->new_map[i][j] == ' ')
        j++;
    start = j;
    if  (check_after_d(v->new_map, i, j) == 1)
        ft_puterror("Error: in rgb numbers\n", 2);
    while (v->new_map[i][j] && v->new_map[i][j] != ' ')
    {
        if (check_digit(v->new_map, i, j) == 1)
            ft_puterror("Error: in rgb numbers\n", 2);
        j++;
    }
    check_rgb_range(v, i, start);
}
