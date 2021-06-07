/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctragula <ctragula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:44:46 by ctragula          #+#    #+#             */
/*   Updated: 2021/02/15 21:20:52 by ctragula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	valid_symbol(char elem, t_bool *player, int line)
{
	if (!ft_strchr("02 ", elem))
	{
		if (ft_strchr("NSWE", elem) && player && *player)
			ft_error(MULTIPLAYER, "");
		else if (ft_strchr("NSWE", elem))
			*player = TRUE;
		else
			ft_error(INVALID_MAP, ft_itoa(line));
	}
}

static void	extreme_elem(char elem, int line, t_bool *pl)
{
	if (elem && elem != '1' && elem != ' ')
	{
		valid_symbol(elem, pl, line);
		ft_error(OPENMAP, ft_itoa(line));
	}
}

static void	valid_pos(char **map, size_t y, size_t x)
{
	if (x >= ft_strlen(map[y - 1]) || x >= ft_strlen(map[y + 1]))
		ft_error(OPENMAP, "");
	if (map[y - 1][x] == ' ' || map[y][x - 1] == ' ' ||
		map[y + 1][x] == ' ' || map[y][x + 1] == ' ')
		ft_error(OPENMAP, "");
}

static void	first_last_line(char *map, int line, t_bool *pl)
{
	size_t	i;

	i = 0;
	while (map[i])
		extreme_elem(map[i++], line, pl);
}

void		map_validator(char **map)
{
	size_t	i;
	size_t	j;
	t_bool	player;

	player = FALSE;
	first_last_line(map[0], 0, &player);
	i = 1;
	while (map[i + 1])
	{
		extreme_elem(map[i][0], i, &player);
		j = 1;
		while (map[i][j + 1])
		{
			if (!ft_strchr("1 ", map[i][j]))
			{
				valid_symbol(map[i][j], &player, i);
				valid_pos(map, i, j);
			}
			j++;
		}
		extreme_elem(map[i][j], i, &player);
		i++;
	}
	first_last_line(map[i], 0, &player);
	(!player) ? ft_error(NO_PLAYER, "") : 0;
}
