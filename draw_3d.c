/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctragula <ctragula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:48:41 by ctragula          #+#    #+#             */
/*   Updated: 2021/02/15 15:12:30 by ctragula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		calculate_tex(t_data *tex, t_calc data, int wall_len, t_point y)
{
	double	x;
	double	c;

	x = data.wall.x - (int)data.wall.x;
	if (x == 0)
		x = data.wall.y;
	else
		x = data.wall.x;
	x = x * (y.x * 1.0 / (y.y * 1.0));
	x = modf(x, &c);
	tex->start_x = (int)round(x * tex->x);
	if (tex->start_x == tex->x)
		tex->start_x = 0;
	tex->scale = (wall_len * 1.0) / (tex->y * 1.0);
	tex->start_y = 0;
}

static void		draw_col(t_all *all, t_calc data,
				int x, t_data tex)
{
	int	wall_len;
	int	ceil_len;
	int i;

	i = 0;
	data.len = fabs(data.len);
	wall_len = ceil(all->env->resolution.y * 1.0 / data.len);
	ceil_len = ((all->env->resolution.y - wall_len) % 2 == 1) ?
		((all->env->resolution.y - wall_len) / 2 + 1) :
		((all->env->resolution.y - wall_len) / 2);
	calculate_tex(&tex, data, wall_len, all->env->resolution);
	if (ceil_len > 0)
		i = ceil_len;
	while (i < ceil_len + wall_len && i < all->env->resolution.y)
	{
		tex.start_y = round(i - ceil_len) / tex.scale;
		my_mlx_pixel_put(all->img, x, i++, get_pixel_color(tex));
	}
}

static void		draw_floor_ceil(t_data *img, t_scheme *env)
{
	int	i;
	int	j;
	int	ceil_len;

	ceil_len = (env->resolution.y % 2) ? env->resolution.y / 2 + 1 :
										env->resolution.y / 2;
	i = 0;
	while (i < env->resolution.x)
	{
		j = 0;
		while (j < ceil_len)
			my_mlx_pixel_put(img, i, j++, env->colors.ceil);
		while (j < env->resolution.y)
			my_mlx_pixel_put(img, i, j++, env->colors.floor);
		i++;
	}
}

static void		draw_walls(t_all *all, double **arr)
{
	double	step;
	t_ray	ray;
	t_calc	data;
	t_point	res;

	res = all->env->resolution;
	ray.angle = all->env->player.dir + ANGLE / 2;
	step = ANGLE / all->env->resolution.x;
	ray.num = -1;
	while (ray.num++ < all->env->resolution.x - 1)
	{
		data = cast_ray(all->env->player, all->env->map, ray);
		if (data.len < 0 && (data.len * (-1)))
			(ray.angle > NORTH && ray.angle <= SOUTH) ?
			draw_col(all, data, ray.num, all->tex.ea_tex) :
			draw_col(all, data, ray.num, all->tex.we_tex);
		else if (data.len != 0)
			(ray.angle < WEST) ?
			draw_col(all, data, ray.num, all->tex.no_tex) :
			draw_col(all, data, ray.num, all->tex.so_tex);
		ray.angle = ray.angle - step;
		ray.angle = (ray.angle >= 2 * M_PI) ? ray.angle - 2 * M_PI : ray.angle;
		ray.angle = (ray.angle < 0) ? ray.angle + 2 * M_PI : ray.angle;
		(*arr)[ray.num] = fabs(data.len);
	}
}

int				draw_3d(t_all *all)
{
	draw_floor_ceil(all->img, all->env);
	draw_walls(all, &all->wall_dist);
	draw_sprites(&all->env->sprites, all->wall_dist, all);
	return (0);
}
