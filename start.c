/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctragula <ctragula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 22:56:39 by ctragula          #+#    #+#             */
/*   Updated: 2021/02/15 21:17:55 by ctragula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_screensize(void *mlx_ptr, t_point *resolution)
{
	int	sizex;
	int	sizey;

	mlx_get_screen_size(mlx_ptr, &sizex, &sizey);
	if (resolution->x > sizex)
		resolution->x = sizex;
	if (resolution->y > sizey)
		resolution->y = sizey;
}

static void	init_all(t_all *all, t_scheme *env)
{
	t_vars	*vars;
	t_data	*img;

	vars = malloc(sizeof(t_vars));
	img = malloc(sizeof(t_data));
	vars->mlx_ptr = mlx_init();
	init_screensize(vars->mlx_ptr, &env->resolution);
	vars->win_ptr = mlx_new_window(vars->mlx_ptr,
									env->resolution.x,
									env->resolution.y,
									"cub3d");
	img->img = mlx_new_image(vars->mlx_ptr,
							env->resolution.x,
							env->resolution.y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
								&img->line_length, &img->endian);
	all->vars = vars;
	all->env = env;
	all->img = img;
	all->wall_dist = ft_calloc(sizeof(double), env->resolution.x);
}

static int	my_loop(t_all *all)
{
	if (all->env->move_flag)
	{
		key_move(&all->env->player, all->env->move_flag, all->vars);
		draw_3d(all);
		mlx_put_image_to_window(all->vars->mlx_ptr,
			all->vars->win_ptr, all->img->img, 0, 0);
		mlx_do_sync(all->vars->mlx_ptr);
	}
	return (0);
}

void		start_cub3d(t_scheme *env)
{
	t_all	all;

	init_all(&all, env);
	get_textures(&all.tex, all.vars->mlx_ptr, all.env->texture);
	draw_3d(&all);
	draw_3d(&all);
	mlx_put_image_to_window(all.vars->mlx_ptr,
				all.vars->win_ptr, all.img->img, 0, 0);
	mlx_do_sync(all.vars->mlx_ptr);
	ft_controller(&all);
	mlx_loop_hook(all.vars->mlx_ptr, my_loop, &all);
	mlx_loop(all.vars->mlx_ptr);
}
