/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctragula <ctragula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 14:31:14 by ctragula          #+#    #+#             */
/*   Updated: 2021/02/15 13:50:29 by ctragula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_calc
	y_wall(char **map, t_player pl, t_ray ray)
{
	t_calc	data;

	data.len = 0;
	data.wall.y = (ray.step.y == 1) ? (int)pl.pos.y + 1 : (int)pl.pos.y - DELTA;
	data.wall.x =
		pl.pos.x + ray.step.x * fabs(pl.pos.y - data.wall.y) / tan(ray.angle);
	ray.step.x = ray.step.x / (tan(ray.angle));
	while (data.wall.y < ft_wordtab_count(map) && data.wall.y > 0
			&& data.wall.x > 0 && data.wall.x < ft_strlen(map[(int)data.wall.y])
			&& map[(int)data.wall.y][(int)data.wall.x] != '1')
	{
		data.wall.y = data.wall.y + ray.step.y;
		data.wall.x = data.wall.x + ray.step.x;
	}
	if (data.wall.y < ft_wordtab_count(map) && data.wall.y >= 0 &&
		data.wall.x >= 0 && data.wall.x < ft_strlen(map[(int)data.wall.y]))
		data.len = fabs(pl.pos.x - data.wall.x) * cos(pl.dir)
			+ fabs(pl.pos.y - data.wall.y) * sin(pl.dir);
	return (data);
}

static t_calc
	x_wall(char **map, t_player pl, t_ray ray)
{
	t_calc	data;

	data.len = 0;
	data.wall.x = (ray.step.x == 1) ? (int)pl.pos.x + 1 : (int)pl.pos.x - DELTA;
	data.wall.y =
		pl.pos.y + ray.step.y * fabs(pl.pos.x - data.wall.x) * tan(ray.angle);
	ray.step.y = ray.step.y * tan(ray.angle);
	while (data.wall.y < ft_wordtab_count(map) && data.wall.y > 0
			&& data.wall.x > 0 && data.wall.x < ft_strlen(map[(int)data.wall.y])
			&& map[(int)data.wall.y][(int)data.wall.x] != '1')
	{
		data.wall.y = data.wall.y + ray.step.y;
		data.wall.x = data.wall.x + ray.step.x;
	}
	if (data.wall.y < ft_wordtab_count(map) && data.wall.y >= 0 &&
		data.wall.x >= 0 && data.wall.x < ft_strlen(map[(int)data.wall.y]))
		data.len = fabs(pl.pos.x - data.wall.x) * cos(pl.dir)
			+ fabs(pl.pos.y - data.wall.y) * sin(pl.dir);
	if (ray.step.x < 0)
		data.wall.x = round(data.wall.x);
	return (data);
}

static t_calc
	cast_fourth_ray(t_player pl, char **map, t_ray ray)
{
	t_calc	data_x;
	t_calc	data_y;

	data_x = x_wall(map, pl, ray);
	data_y = y_wall(map, pl, ray);
	if (data_y.len == 0)
	{
		data_x.len = -data_x.len;
		return (data_x);
	}
	if (data_x.len == 0)
		return (data_y);
	if (data_x.len < data_y.len && data_x.len > 0 && data_y.len > 0)
	{
		data_x.len = (data_x.len > 0) ? -data_x.len : data_x.len;
		return (data_x);
	}
	if (data_x.len > data_y.len && data_x.len < 0 && data_y.len < 0)
	{
		data_x.len = (data_x.len > 0) ? -data_x.len : data_x.len;
		return (data_x);
	}
	data_y.len = (data_y.len > 0) ? data_y.len : -data_y.len;
	return (data_y);
}

t_calc
	cast_ray(t_player player, char **map, t_ray ray)
{
	t_calc	data;

	ray.step.x = (ray.angle >= NORTH && ray.angle < SOUTH) ? -1 : 1;
	ray.step.y = (ray.angle < WEST) ? -1 : 1;
	ray.angle = ray.angle;
	if (ray.angle > SOUTH)
	{
		ray.angle = 2 * M_PI - ray.angle;
		player.dir = 2 * M_PI - player.dir;
	}
	else if (ray.angle > WEST)
	{
		ray.angle = ray.angle - M_PI;
		player.dir = player.dir - M_PI;
	}
	else if (ray.angle > NORTH)
	{
		ray.angle = M_PI - ray.angle;
		player.dir = M_PI - player.dir;
	}
	data = cast_fourth_ray(player, map, ray);
	return (data);
}
