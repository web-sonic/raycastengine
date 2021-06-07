/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctragula <ctragula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 19:35:50 by ctragula          #+#    #+#             */
/*   Updated: 2021/02/15 16:32:18 by ctragula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_error(char *msg, char *value)
{
	ft_putendl_fd(ERROR, 2);
	ft_putstr_fd(msg, 2);
	ft_putendl_fd(value, 2);
	exit(1);
}
