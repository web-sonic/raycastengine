/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctragula <ctragula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:16:46 by ctragula          #+#    #+#             */
/*   Updated: 2021/01/20 18:59:47 by ctragula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_data_map(t_data_map *map)
{
	map->color = 0;
	map->coord.x = 0;
	map->coord.y = 0;
}

static void	draw_square(t_data *img, int step, t_data_map map)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = map.coord.x;
	x = step + map.coord.x;
	while (++i < x)
	{
		j = map.coord.y;
		y = step + map.coord.y;
		while (++j < y)
			my_mlx_pixel_put(img, i, j, map.color);
	}
}

static int	get_color(char elem)
{
	if (elem == '1')
		return (MAP_WALL_COLOR);
	if (elem == '0')
		return (MAP_FLOOR_COLOR);
	if (elem == '2')
		return (MAP_SPRITE_COLOR);
	if (elem == ' ')
		return (0);
	return (MAP_PLAYER_COLOR);
}

void		draw_map(char **map, t_data *img, t_vars *vars)
{
	t_data_map		data_map;
	int				i;
	int				j;
	int				step;

	step = 15;
	i = 0;
	init_data_map(&(data_map));
	while (map[i])
	{
		j = 0;
		ft_putendl_fd(map[i], 1);
		data_map.coord.x = 0;
		while (map[i][j])
		{
			data_map.color = get_color(map[i][j]);
			draw_square(img, step, data_map);
			data_map.coord.x += step;
			j++;
		}
		data_map.coord.y += step;
		i++;
	}
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, img->img, 0, 0);
}
