/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctragula <ctragula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 20:26:13 by ctragula          #+#    #+#             */
/*   Updated: 2021/02/15 20:51:31 by ctragula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int
	cmp_dist(t_sprite *first, t_sprite *second)
{
	if (first->dist - second->dist < 0)
		return (1);
	return (0);
}

static void
	draw_pix_sprite(t_point point, t_sprite *sprite, t_data *img, t_data tex)
{
	double	step;
	int		color;

	step = sprite->size * 1.0 / tex.x;
	tex.start_x = point.x * 1.0 / step;
	tex.start_y = point.y * 1.0 / step;
	color = get_pixel_color(tex);
	if (color)
		my_mlx_pixel_put(img,
					sprite->v_offset + point.x,
					sprite->h_offset + point.y,
					color);
}

static void
	draw_sprite(t_sprite *sprite, double *wall_dist, t_all *all)
{
	t_point	point;

	point.y = 0;
	while (point.y < sprite->size)
	{
		if (sprite->h_offset + point.y >= 0 &&
			sprite->h_offset + point.y < all->env->resolution.y)
		{
			point.x = 0;
			while (point.x < sprite->size)
			{
				if (sprite->v_offset + point.x >= 0 &&
					sprite->v_offset + point.x < all->env->resolution.x &&
					fabs(sprite->dist) < wall_dist[sprite->v_offset + point.x])
					draw_pix_sprite(point, sprite, all->img, all->tex.sp_tex);
				point.x++;
			}
		}
		point.y++;
	}
}

static void
	init_sprite(t_sprite *sprite, t_player pl, t_point res)
{
	double	diff_ang;

	sprite->dir = atan2(pl.pos.y - sprite->pos.y, sprite->pos.x - pl.pos.x);
	if (sprite->dir < 0)
		sprite->dir += 2 * M_PI;
	if (pl.dir - sprite->dir > M_PI)
		sprite->dir += 2 * M_PI;
	if (pl.dir - sprite->dir < -M_PI)
		sprite->dir -= 2 * M_PI;
	sprite->dist = sqrt(pow(pl.pos.y - sprite->pos.y, 2) +
				pow(pl.pos.x - sprite->pos.x, 2)) * cos(pl.dir - sprite->dir);
	diff_ang = pl.dir - sprite->dir;
	sprite->size = res.y / sprite->dist;
	sprite->size = (sprite->dist < 0.5) ? 0 : sprite->size;
	sprite->v_offset = (diff_ang) / (ANGLE / (res.x * 1.0))
					- sprite->size / 2 + res.x / 2;
	sprite->h_offset = res.y / 2 - sprite->size / 2;
}

void
	draw_sprites(t_list **sprites, double *wall_dist, t_all *all)
{
	t_list	*sprite;

	ft_lstsort(sprites, *cmp_dist);
	sprite = *sprites;
	while (sprite)
	{
		init_sprite(sprite->content, all->env->player, all->env->resolution);
		draw_sprite(sprite->content, wall_dist, all);
		sprite = sprite->next;
	}
}
