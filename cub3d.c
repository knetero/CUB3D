/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abazerou <abazerou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:28:55 by abazerou          #+#    #+#             */
/*   Updated: 2024/01/01 09:37:11 by abazerou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include <stdio.h>


int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void	my_mlx_pixel_put(t_img *img_data, int x, int y, int color)
{
	char	*dst;

	dst = (char *)img_data->addr + (y * img_data->line_length + x * (img_data->bitppixel / 8));
	*(unsigned int*)dst = color;
}

void	scaling_img(t_img *img_data, t_mlx *mlx_d)
{
	int x;
	int y;
	int index;
	int rowy;
	int colx;


	// if (img_data->width < SIZE || img_data->height < SIZE)
	// 	exit(1);
	y = 0;
	while (y < SIZE)
	{
		x = 0;
		rowy = ((float)img_data->height / SIZE) * y;
		while (x < SIZE)
		{
			colx = ((float)img_data->width / SIZE) * x;
			// rowy = (img_data->height / SIZE) * y;
			index = (rowy * img_data->width + colx);
			printf("index : %d\n", index);
			printf("colx : %d\n", colx);
			printf("rowy : %d\n", rowy);
			my_mlx_pixel_put(img_data, x, y, img_data->addr[index]);
			x++;
		}
	// puts("START");
		y++;
	}
	printf("%d\n", x);
	printf("%d\n", y);
	img_data->width = SIZE;
	img_data->height = SIZE;
	printf(" ---------------- %d\n", img_data->width);
	printf(" ---------------- %d\n", img_data->height);
	puts("DONE");
	mlx_put_image_to_window(mlx_d->mlx, mlx_d->mlx_win, img_data->img, 0, 0);
}

int	read_map(t_var *v)
{
	v->map = malloc(sizeof(char *) * (v->map_len + 1));
	if (!v->map)
		return (free(v->map), 1);
	while (v->j < v->map_len)
	{
		v->map[v->j] = get_next_line(v->fd);
		v->j++;
	}
	v->map[v->j] = NULL;
	v->big_line = get_biggest_line(v->map);
	v->new_map = malloc(sizeof(char *) * (v->map_len + 1));
	if (!v->new_map)
		return (free(v->new_map), 1);
	while (v->map[v->i])
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

int	main(int ac, char **av)
{
	t_var	v;
	t_mlx	mlx_d;
	t_img 	img_data;

	// atexit(f);
	mlx_d.v = &v;
	img_data.height = 0;
	img_data.width = 0;
	v.map_len = 0;
	v.big_line = 0;
	v.i = 0;
	v.j = 0;
	if (ac != 2)
		ft_puterror("Error in arguments!\n", 2);
	check_ex(av[1]);
	v.fd = open(av[1], O_RDWR);
	if (v.fd == -1)
		ft_puterror("Error in FILE\n!", 2);
	get_map_len(&v, av[1]);
	if (read_map(&v))
		return (1);
	v.i = 0;
	parsing(&v);
	v.i = 0;
	// while (v.new_map[v.i])
	// 	printf("%s\n", v.new_map[v.i++]);
	// put_pixels(&mlx_d, &v);
	// mlx_image_to_window(mlx_d.mlx, mlx_d.image, 0, 0);
	// mlx_d.mlx = mlx_init();
	// mlx_d.mlx_win = mlx_new_window(mlx_d.mlx, SIZE, SIZE, "CUB3D");
	// // printf("***********width : %d\n", img_data.width);
	// img_data.img = mlx_xpm_file_to_image(mlx_d.mlx, "textures/a.xpm", &img_data.width, &img_data.height);
	// // printf("--------------width : %d\n", img_data.width);
	// if (!img_data.img)
	// {
	// 	ft_puterror("Error : mlx_xpm_file_to_img FAILED\n", 2);
	// 	exit(0);
	// }
	// img_data.addr = (unsigned *)mlx_get_data_addr(img_data.img, &img_data.bitppixel, &img_data.line_length, &img_data.endian);
	// if (!img_data.addr)
	// {
	// 	ft_puterror("Error : mlx_get_data_addr FAILED \n", 2);
	// 	exit(0);
	// }
	// printf(" ---------------> %d\n", img_data.addr[0]);
	// printf(" ---------------> %d\n", img_data.addr[1]);
	// printf(" ---------------> %d\n", img_data.addr[2]);
	// scaling_img(&img_data, &mlx_d);
	// mlx_loop(mlx_d.mlx);
	free(v.map);
	ft_freetab(v.new_map);
}
