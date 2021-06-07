/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctragula <ctragula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 10:53:51 by ctragula          #+#    #+#             */
/*   Updated: 2021/02/15 15:30:23 by ctragula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	key_pressed(int keycode, unsigned char *move_flag)
{
	if (keycode == 13)
		*move_flag |= MOVE_FRONT;
	if (keycode == 1)
		*move_flag |= MOVE_BACK;
	if (keycode == 0)
		*move_flag |= MOVE_LEFT;
	if (keycode == 2)
		*move_flag |= MOVE_RIGHT;
	if (keycode == 123)
		*move_flag |= ROTATE_COUNT;
	if (keycode == 124)
		*move_flag |= ROTATE_CLOCK;
	if (keycode == 53)
		*move_flag |= END;
	return (0);
}

static int	key_released(int keycode, unsigned char *move_flag)
{
	if (keycode == 13)
		*move_flag &= ~MOVE_FRONT;
	if (keycode == 1)
		*move_flag &= ~MOVE_BACK;
	if (keycode == 0)
		*move_flag &= ~MOVE_LEFT;
	if (keycode == 2)
		*move_flag &= ~MOVE_RIGHT;
	if (keycode == 123)
		*move_flag &= ~ROTATE_COUNT;
	if (keycode == 124)
		*move_flag &= ~ROTATE_CLOCK;
	return (0);
}

void		ft_controller(t_all *all)
{
	mlx_hook(all->vars->win_ptr, WINDOW_DESTROY, 0, cub_close, all->vars);
	mlx_hook(all->vars->win_ptr,
			KEY_PRESS, PRESS_MASK, key_pressed, &all->env->move_flag);
	mlx_hook(all->vars->win_ptr,
			KEY_RELEASE, RELEASE_MASK, key_released, &all->env->move_flag);
}
