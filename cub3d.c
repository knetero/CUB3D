/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:28:55 by abazerou          #+#    #+#             */
/*   Updated: 2023/12/09 16:20:45 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int    read_map(t_var *v)
{
    v->map = malloc(sizeof(char *) * (v->map_len + 1));
    if(!v->map)
        return(free(v->map), 1);
    while(v->j < v->map_len)
    {
        v->map[v->j] = get_next_line(v->fd);
        v->j++;
    }
    v->map[v->j] = NULL;
    v->big_line = get_biggest_line(v->map);
    v->new_map = malloc(sizeof(char *) * (v->map_len + 1));
    if(!v->new_map)
        return(free(v->new_map), 1);
    while(v->map[v->i])
    {
        v->new_map[v->i] = v->map[v->i];
        v->i++;
    }
    v->new_map[v->i] = NULL;
    return (0);
}
void f(){
    system("leaks CUB3D");
}

void    put_pixels(t_mlx *mlx_d, t_var *v)
{
    v->j = 0;
    int j = 0;
    mlx_d->mlx = mlx_init(1500, 1500, "CUB3D", true);
    mlx_d->image = mlx_new_image(mlx_d->mlx, 1500, 1500);
    v->i = v->map_pos;
    while (v->new_map[v->i])
    {
        v->j = 0;
        while (v->new_map[v->i][v->j])
        {
            int i = 0;
            while (i < 32)
            {
                j = 0;
                while (j < 32)
                {
                    if (v->new_map[v->i][v->j] == '1')
                        mlx_put_pixel(mlx_d->image,(v->j * 32) + j, (v->i - v->map_pos) * 32 + i,0xCCFFE5);
                    else if (v->new_map[v->i][v->j] == 'N' || v->new_map[v->i][v->j] == 'S' 
                        || v->new_map[v->i][v->j] == 'W' || v->new_map[v->i][v->j] == 'E')
                            mlx_put_pixel(mlx_d->image,(v->j * 32) + j,(v->i - v->map_pos) * 32 + i,0xFF0000FF);
                    else if (v->new_map[v->i][v->j] == '0')
                        mlx_put_pixel(mlx_d->image,  (v->j * 32) + j,(v->i - v->map_pos) * 32 + i,0x000000FF);
                    j++;
                }
                i++;
            }
            v->j++;
        }
        v->i++;
    }
    mlx_image_to_window(mlx_d->mlx , mlx_d->image, 0, 0);
}

int main(int ac, char **av)
{
    // atexit(f);
    t_var v;
    t_mlx mlx_d;
    t_rgb rgb;
    
    mlx_d.v = &v;
    v.rgb = &rgb;
    v.map_len = 0;
    v.big_line = 0;
    v.i = 0;
    v.j = 0;
    if (ac != 2)
       ft_puterror("Error in arguments!\n", 2);
    check_ex(av[1]);
    v.fd = open(av[1], O_RDWR);
    if(v.fd == -1)
        ft_puterror("Error in FILE\n!", 2);
    get_map_len(&v, av[1]);
    if (read_map(&v))
        return (1);
    v.i = 0;
    parsing(&v);
    v.i = 0;
    while(v.new_map[v.i])
    {
        printf("%s\n", v.new_map[v.i++]);
    }
    // put_pixels(&mlx_d, &v);
    // mlx_loop(mlx_d.mlx);
    free(v.map);
    ft_freetab(v.new_map);
}
