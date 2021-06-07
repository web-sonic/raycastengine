/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctragula <ctragula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:49:38 by ctragula          #+#    #+#             */
/*   Updated: 2021/02/15 21:08:10 by ctragula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	add_resolution(t_point *resolution, char **args)
{
	if (ft_wordtab_count(args) != 3)
		ft_error(ERROR_COUNT_ARGS, args[0]);
	if (resolution->x)
		ft_error(ERROR_DOUBLE_CONFIG, args[0]);
	ft_validate_str(args[1], args[0]);
	ft_validate_str(args[2], args[0]);
	resolution->x = ft_atoi(args[1]);
	resolution->y = ft_atoi(args[2]);
	ft_wordtab_clear(args);
}

void	add_texture(t_words *texture, char **args)
{
	if (ft_wordtab_count(args) != 2)
		ft_error(ERROR_COUNT_ARGS, "texture");
	validate_texture(*texture, args[0]);
	if (!ft_strncmp(args[0], "NO", 3))
		texture->no = ft_strdup(args[1]);
	if (!ft_strncmp(args[0], "SO", 3))
		texture->so = ft_strdup(args[1]);
	if (!ft_strncmp(args[0], "WE", 3))
		texture->we = ft_strdup(args[1]);
	if (!ft_strncmp(args[0], "EA", 3))
		texture->ea = ft_strdup(args[1]);
	if (!ft_strncmp(args[0], "S", 3))
		texture->sprite = ft_strdup(args[1]);
	ft_wordtab_clear(args);
}

void	add_color(t_color *colors, char **args)
{
	char	**str_colors;
	int		rgb;
	size_t	i;

	if ((colors->floor && args[0][0] == 'F') || colors->ceil)
		ft_error(ERROR_DOUBLE_CONFIG, args[0]);
	if (ft_wordtab_count(args) != 2)
		ft_error(ERROR_COUNT_ARGS, "color");
	str_colors = ft_split(args[1], ',');
	if (ft_wordtab_count(str_colors) != 3 || !str_colors)
		ft_error(ERROR_VALUE_ARG, "color");
	i = 0;
	while (str_colors[i])
		ft_validate_str(str_colors[i++], args[0]);
	rgb = (atoi(str_colors[0]) << 16) +
			(atoi(str_colors[1]) << 8) +
			atoi(str_colors[2]);
	ft_wordtab_clear(str_colors);
	(!ft_strncmp(args[0], "F", 2)) ? colors->floor = rgb :
								(colors->ceil = rgb);
	ft_wordtab_clear(args);
}

void	check_line(t_scheme *env, char **args)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] != '1')
				ft_error(ERROR_FIRST_LINE_MAP, "");
			j++;
		}
		i++;
	}
	ft_validate_configs(env);
	env->map = malloc(sizeof(char *) * 2);
}
