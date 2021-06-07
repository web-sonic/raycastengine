/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctragula <ctragula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:30:00 by ctragula          #+#    #+#             */
/*   Updated: 2021/02/15 15:18:45 by ctragula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int		get_pixel_color(t_data tex)
{
	char	*color;

	color = tex.addr +
	(tex.start_y * tex.line_length + tex.start_x * (tex.bits_per_pixel / 8));
	if (color)
		return (*(unsigned int *)color);
	return (0);
}
