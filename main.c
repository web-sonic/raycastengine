/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctragula <ctragula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 09:09:14 by ctragula          #+#    #+#             */
/*   Updated: 2021/02/15 21:18:35 by ctragula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		init_enviroment(t_scheme *env)
{
	env->resolution.x = 0;
	env->resolution.y = 0;
	env->texture.no = 0;
	env->texture.so = 0;
	env->texture.we = 0;
	env->texture.ea = 0;
	env->texture.sprite = 0;
	env->colors.floor = 0;
	env->colors.ceil = 0;
	env->map = 0;
	env->sprites = 0;
}

static t_player	init_player(int x, int y, char dir)
{
	t_player	player;

	player.pos.x = x + 0.5;
	player.pos.y = y + 0.5;
	if (dir == 'N')
		player.dir = NORTH;
	if (dir == 'S')
		player.dir = SOUTH;
	if (dir == 'W')
		player.dir = WEST;
	if (dir == 'E')
		player.dir = EAST;
	return (player);
}

static void		init_sprites(t_list **sprites, int x, int y)
{
	t_sprite	*sprite;

	sprite = malloc(sizeof(t_sprite));
	sprite->pos.x = x + 0.5;
	sprite->pos.y = y + 0.5;
	ft_lstadd_back(sprites, ft_lstnew(sprite));
}

static void		init_objects(char **map, t_scheme *env)
{
	int			i;
	int			j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("NWSE", map[i][j]))
				env->player = init_player(j, i, map[i][j]);
			if (map[i][j] == '2')
				init_sprites(&env->sprites, j, i);
		}
	}
}

int				main(int argc, char **argv)
{
	t_bool		is_screen;
	t_scheme	env;

	ft_input_validate(argc, argv, &is_screen);
	init_enviroment(&env);
	ft_parse_map(argv[1], &env);
	map_validator(env.map);
	init_objects(env.map, &env);
	if (is_screen)
		get_screenshot(&env);
	else
		start_cub3d(&env);
	return (0);
}
