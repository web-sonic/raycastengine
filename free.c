/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctragula <ctragula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:39:10 by ctragula          #+#    #+#             */
/*   Updated: 2021/02/15 15:18:06 by ctragula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_sprite(void *content)
{
	free(content);
}

void	free_all(t_all *all)
{
	free(all->wall_dist);
	mlx_destroy_image(all->vars->mlx_ptr, all->tex.ea_tex.img);
	mlx_destroy_image(all->vars->mlx_ptr, all->tex.no_tex.img);
	mlx_destroy_image(all->vars->mlx_ptr, all->tex.we_tex.img);
	mlx_destroy_image(all->vars->mlx_ptr, all->tex.so_tex.img);
	mlx_destroy_image(all->vars->mlx_ptr, all->tex.sp_tex.img);
	mlx_destroy_image(all->vars->mlx_ptr, all->img->img);
	ft_wordtab_clear(all->env->map);
	ft_lstclear(&all->env->sprites, free_sprite);
	free(all->env->texture.ea);
	free(all->env->texture.no);
	free(all->env->texture.so);
	free(all->env->texture.we);
	free(all->env->texture.sprite);
	free(all->vars->mlx_ptr);
	ft_putendl_fd("bye", 1);
}
