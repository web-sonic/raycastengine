/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctragula <ctragula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 10:57:14 by ctragula          #+#    #+#             */
/*   Updated: 2021/02/15 14:57:31 by ctragula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLLER_H
# define CONTROLLER_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define KEY_PRESS		2
# define KEY_RELEASE	3
# define PRESS_MASK		1L<<0
# define RELEASE_MASK	1L<<1
# define WINDOW_DESTROY 17

# define MOVE_FRONT		0x01
# define MOVE_BACK		0x02
# define MOVE_LEFT		0x04
# define MOVE_RIGHT     0x08
# define ROTATE_CLOCK   0x10
# define ROTATE_COUNT	0x20

# define END 0x40

#endif
