/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:23:48 by abazerou          #+#    #+#             */
/*   Updated: 2023/12/09 17:24:17 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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