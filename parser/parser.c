/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctragula <ctragula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:36:32 by ctragula          #+#    #+#             */
/*   Updated: 2021/02/15 17:39:03 by ctragula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static t_bool	route_configs(t_scheme *env, char **args)
{
	if (!strncmp(args[0], "NO", 3) ||
		!strncmp(args[0], "SO", 3) ||
		!strncmp(args[0], "WE", 3) ||
		!strncmp(args[0], "EA", 3) ||
		!strncmp(args[0], "S", 2))
	{
		add_texture(&env->texture, args);
		return (FALSE);
	}
	else if (!strncmp(args[0], "F", 2) || !strncmp(args[0], "C", 2))
	{
		add_color(&env->colors, args);
		return (FALSE);
	}
	else if (!strncmp(args[0], "R", 2))
	{
		add_resolution(&env->resolution, args);
		return (FALSE);
	}
	else
		check_line(env, args);
	return (TRUE);
}

static void		rd_map(char *line, t_scheme *env)
{
	char			**tmp;
	size_t			cnt;
	static t_bool	empty_line = 0;

	cnt = 0;
	if (!(*line) && !empty_line)
		empty_line = TRUE;
	else if (!(*line))
		ft_error(EMPTY_LINE_MAP, "");
	while (env->map[cnt])
		cnt++;
	tmp = env->map;
	env->map = malloc(sizeof(char *) * (cnt + 2));
	env->map[cnt + 1] = 0;
	env->map[cnt] = ft_strdup(line);
	while (cnt--)
		env->map[cnt] = ft_strdup(tmp[cnt]);
	ft_wordtab_clear(tmp);
	cnt++;
}

static int		rd_configs(char *line, t_scheme *env)
{
	char	**args;
	t_bool	is_map;

	if (!(*line))
		return (FALSE);
	args = ft_split(line, ' ');
	is_map = route_configs(env, args);
	if (is_map)
	{
		ft_wordtab_clear(args);
		env->map[0] = ft_strdup(line);
		env->map[1] = 0;
	}
	return (is_map);
}

void			ft_parse_map(char *file, t_scheme *env)
{
	int		fd;
	t_bool	is_map;
	char	*line;
	int		ret;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(strerror(errno), "");
	is_map = FALSE;
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (ret < 0)
			ft_error(strerror(errno), "");
		(!is_map) ? is_map = rd_configs(line, env) : rd_map(line, env);
		free(line);
	}
	close(fd);
}
