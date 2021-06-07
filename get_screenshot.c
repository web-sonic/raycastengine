/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screenshot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctragula <ctragula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 14:26:00 by ctragula          #+#    #+#             */
/*   Updated: 2021/02/15 21:18:48 by ctragula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	itoc(unsigned char *one_byte, int value)
{
	one_byte[0] = (unsigned char)value;
	one_byte[1] = (unsigned char)(value >> 8);
	one_byte[2] = (unsigned char)(value >> 16);
	one_byte[3] = (unsigned char)(value >> 24);
}

static void	write_bitmap_header(int fd, t_point res)
{
	unsigned char	*bmpfileheader;

	bmpfileheader = ft_calloc(SIZE_BP_HEADER, sizeof(unsigned char));
	bmpfileheader[0] = 0x42;
	bmpfileheader[1] = 0x4D;
	itoc(bmpfileheader + 2, res.x * res.y * 4 + SIZE_BP_HEADER);
	bmpfileheader[10] = (unsigned char)SIZE_BP_HEADER;
	bmpfileheader[14] = (unsigned char)SIZE_BP_INFO;
	itoc(bmpfileheader + 18, res.x);
	itoc(bmpfileheader + 22, res.y * (-1));
	bmpfileheader[26] = (unsigned char)1;
	bmpfileheader[28] = (unsigned char)(32);
	if (write(fd, bmpfileheader, SIZE_BP_HEADER) < 0)
		ft_error(strerror(errno), "");
	free(bmpfileheader);
}

static void	write_image(int fd, t_point res, t_data img)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (i < res.y)
	{
		j = 0;
		while (j < res.x)
		{
			img.start_x = j;
			img.start_y = i;
			color = get_pixel_color(img);
			if (write(fd, &color, 4) < 0)
				ft_error(strerror(errno), "");
			j++;
		}
		i++;
	}
}

void		get_screenshot(t_scheme *env)
{
	t_all	all;
	t_vars	vars;
	int		fd;
	t_data	img;

	ft_putendl_fd("screenshot saving...", 1);
	vars.mlx_ptr = mlx_init();
	img.img = mlx_new_image(vars.mlx_ptr, env->resolution.x, env->resolution.y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
				&img.line_length, &img.endian);
	all.img = &img;
	all.env = env;
	all.vars = &vars;
	all.wall_dist = ft_calloc(env->resolution.x, sizeof(double));
	get_textures(&all.tex, vars.mlx_ptr, all.env->texture);
	draw_3d(&all);
	draw_3d(&all);
	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT, 0777
		| O_TRUNC | O_APPEND)) < 0)
		ft_error(strerror(errno), "");
	write_bitmap_header(fd, env->resolution);
	write_image(fd, env->resolution, img);
	free_all(&all);
	close(fd);
}
