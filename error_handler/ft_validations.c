/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctragula <ctragula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 19:30:33 by ctragula          #+#    #+#             */
/*   Updated: 2021/02/15 21:23:41 by ctragula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_validate_configs(t_scheme *env)
{
	if (!env->resolution.x)
		ft_error(MISSING_RESOLUTION, "");
	if (!env->texture.no)
		ft_error(MISSING_NORTH_TEXTURE, "");
	if (!env->texture.sprite)
		ft_error(MISSING_SPRITE_TEXTURE, "");
	if (!env->texture.so)
		ft_error(MISSING_SOUTH_TEXTURE, "");
	if (!env->texture.we)
		ft_error(MISSING_WEST_TEXTURE, "");
	if (!env->texture.ea)
		ft_error(MISSING_EAST_TEXTURE, "");
	if (!env->colors.floor)
		ft_error(MISSING_FLOOR_COLOR, "");
	if (!env->colors.ceil)
		ft_error(MISSING_CEIL_COLOR, "");
}

void	ft_validate_str(char *str, char *id)
{
	size_t	i;

	i = 0;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			ft_error(ERROR_VALUE_ARG, id);
	if (!ft_strncmp(id, "F", 2) || !ft_strncmp(id, "C", 2))
	{
		if (atoi(str) > 255 || ft_strlen(str) > 3)
			ft_error(ERROR_COLOR_ARG, id);
	}
	if (!ft_strncmp(id, "R", 2))
	{
		if (ft_strlen(str) > 10 ||
			(ft_strlen(str) == 10 && atoi(str) < BIG_INT))
			ft_error(ERROR_RESOLUTION_SIZE, "");
		if (!atoi(str))
			ft_error(ERROR_VALUE_ARG, id);
	}
}

void	validate_texture(t_words texture, char *arg)
{
	if (!ft_strncmp(arg, "NO", 3) && texture.no)
		ft_error(ERROR_DOUBLE_CONFIG, arg);
	if (!ft_strncmp(arg, "SO", 3) && texture.so)
		ft_error(ERROR_DOUBLE_CONFIG, arg);
	if (!ft_strncmp(arg, "WE", 3) && texture.we)
		ft_error(ERROR_DOUBLE_CONFIG, arg);
	if (!ft_strncmp(arg, "EA", 3) && texture.ea)
		ft_error(ERROR_DOUBLE_CONFIG, arg);
	if (!ft_strncmp(arg, "S", 3) && texture.sprite)
		ft_error(ERROR_DOUBLE_CONFIG, arg);
}

void	ft_input_validate(int ac, char **av, t_bool *is_screen)
{
	char	*cub_s;
	char	*tmp;

	cub_s = NULL;
	*is_screen = FALSE;
	if (ac < 2 || ac > 3)
		ft_error(ERROR_NUM_ARGS, "");
	tmp = ft_strnstr(av[1], ".cub", ft_strlen(av[1]));
	while (tmp)
	{
		cub_s = tmp;
		tmp = ft_strnstr(cub_s + 1, ".cub", ft_strlen(av[1]));
	}
	if (!cub_s || ft_strlen(cub_s) > 4)
		ft_error(ERROR_FIRST_ARG, "");
	if (ac == 3)
	{
		if (!ft_strncmp(av[2], "--save", 7))
			*is_screen = TRUE;
		else
			ft_error(ERROR_SECOND_ARG, "");
	}
}
