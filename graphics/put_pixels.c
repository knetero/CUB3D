/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:23:48 by abazerou          #+#    #+#             */
/*   Updated: 2023/12/26 20:03:03 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// int get_rgba(int r, int g, int b, int a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

// void    put_pixels(t_mlx *m, t_var *v)
// {
// 	// (void)*v;
// 	int	j;
// 	int	i;

// 	v->j = 0;
// 	// j = 0;
// 	m->mlx = mlx_init(WIDTH, HIGH, "CUB3D", true);
// 	if(!m->mlx)
// 		ft_puterror("Error : cant init mlx!", 2);
// 	m->image = mlx_new_image(m->mlx, 1500, 1500);
// 	// mlx_texture_t *text = mlx_load_png("./textures/kai.png");
// 	// if(!text)
// 	// 	ft_puterror("Error : cant load texture!", 2);
// 	// m->image = mlx_texture_to_image(m->mlx, text);
// 	// if(!m->image)
// 	// 	ft_puterror("Error : cant load texture!", 2);
// 	// bool flag = mlx_resize_image(m->image, WIDTH, HIGH);
// 	// if(!flag)
// 	// 	ft_puterror("Error : cant resize image!", 2);
// 	// int image_width = m->image->width;
// 	// int image_height = m->image->height;

// 	// int x = 0;
// 	// int y = 0;
	// while (y < image_height) 
	// {
	// 	int index = (y * image_width + x) * 4;

	// 	int red = m->image->pixels[index];
	// 	// printf(" RED : ------------------------------>%d\n", red);
	// 	int green = m->image->pixels[index + 1];
	// 	// printf(" GREEN : ------------------------------>%d\n", green);
	// 	int blue = m->image->pixels[index + 2];
	// 	// printf(" BLUE : ------------------------------>%d\n", blue);
	// 	int alpha = m->image->pixels[index + 3];
	// 	// printf(" ALPHA : ------------------------------>%d\n", alpha);

	// 	mlx_put_pixel(m->image, x, y, get_rgba(red, green, blue, alpha));
	// 	x++;
	// 	if (x >= image_width) 
	// 	{
	// 		x = 0;
	// 		y++;
	// 	}
// 	// mlx_image_to_window(m->mlx, m->image, 0, 0);

// 	// Display the modified image on the screen
	
// 	v->i = v->map_pos;
// 	while (v->new_map[v->i])
// 	{
// 		v->j = 0;
// 		while (v->new_map[v->i][v->j])
// 		{
// 			i = 0;
// 			while (i < 32)
// 			{
// 				j = 0;
// 				while (j < 32)
// 				{ 
// 					if (v->new_map[v->i][v->j] == '1')
// 						mlx_put_pixel(m->image, (v->j * 32) + j, (v->i - v->map_pos) * 32 + i, 0xCCFFE5);
// 					else if (v->new_map[v->i][v->j] == 'N'
// 						|| v->new_map[v->i][v->j] == 'S'
// 						|| v->new_map[v->i][v->j] == 'W'
// 						|| v->new_map[v->i][v->j] == 'E')
// 						mlx_put_pixel(m->image, (v->j * 32) + j, (v->i - v->map_pos) * 32 + i, 0xFF0000FF);
// 					else if (v->new_map[v->i][v->j] == '0')
// 						mlx_put_pixel(m->image, (v->j * 32) + j, (v->i - v->map_pos) * 32 + i, 0x000000FF);
// 					j++;
// 				}
// 				i++;
// 			}
// 			v->j++;
// 		}
// 		v->i++;
// 	}
// 	mlx_image_to_window(m->mlx, m->image, 0, 0);
// }
