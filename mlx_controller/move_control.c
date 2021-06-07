/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctragula <ctragula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 17:26:38 by ctragula          #+#    #+#             */
/*   Updated: 2021/02/15 15:30:45 by ctragula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move(t_player *player, int direction)
{
	player->pos.x = player->pos.x + direction * SPEED * cos(player->dir);
	player->pos.y = player->pos.y - direction * SPEED * sin(player->dir);
}

void	move_left(t_player *player)
{
	double	angle;

	angle = player->dir + M_PI_2;
	if (angle > 2 * M_PI)
		angle = angle - 2 * M_PI;
	player->pos.x = player->pos.x + SPEED * cos(angle);
	player->pos.y = player->pos.y - SPEED * sin(angle);
}

void	move_right(t_player *player)
{
	double	angle;

	angle = player->dir - M_PI_2;
	if (angle < 0)
		angle = angle + 2 * M_PI;
	player->pos.x = player->pos.x + SPEED * cos(angle);
	player->pos.y = player->pos.y - SPEED * sin(angle);
}

void	rotate(double *angle, int direction)
{
	*angle = *angle + direction * SPEED_R;
	if (*angle >= 2 * M_PI)
		*angle = *angle - 2 * M_PI;
	if (*angle < 0)
		*angle = *angle + 2 * M_PI;
}

void	key_move(t_player *player, unsigned char move_flag, t_vars *vars)
{
	if (move_flag & END)
		cub_close(vars);
	if (move_flag & MOVE_FRONT)
		move(player, 1);
	if (move_flag & MOVE_BACK)
		move(player, -1);
	if (move_flag & MOVE_LEFT)
		move_left(player);
	if (move_flag & MOVE_RIGHT)
		move_right(player);
	if (move_flag & ROTATE_COUNT)
		rotate(&player->dir, 1);
	if (move_flag & ROTATE_CLOCK)
		rotate(&player->dir, -1);
}
