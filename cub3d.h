/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctragula <ctragula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 23:48:04 by ctragula          #+#    #+#             */
/*   Updated: 2021/02/15 21:02:35 by ctragula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "structure.h"
# include "error_handler/ft_errors.h"
# include "gnl/get_next_line.h"
# include <math.h>
# include "mlx/mlx.h"
# include "mlx_controller/controller.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <errno.h>
# include <stdio.h>
# include <string.h>

typedef struct	s_all
{
	t_vars		*vars;
	t_data		*img;
	t_scheme	*env;
	t_tex		tex;
	double		*wall_dist;
}				t_all;

# define ANGLE 40 * M_PI / 180
# define NORTH M_PI_2
# define SOUTH 3 * M_PI_2
# define WEST M_PI
# define EAST 0
# define DELTA 0.000001
# define SPEED 0.15
# define SPEED_R 0.10
# define SIZE_BP_HEADER 54
# define SIZE_BP_INFO 40
# define BIG_INT 1000000000

void			start_cub3d(t_scheme *env);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			draw_map(char **map, t_data *img, t_vars *vars);
int				draw_3d(t_all *all);
void			ft_parse_map(char *file, t_scheme *env);
void			add_resolution(t_point *resolution, char **args);
void			add_texture(t_words *texture, char **args);
void			add_color(t_color *colors, char **args);
void			check_line(t_scheme *env, char **args);
t_calc			cast_ray(t_player player, char **map, t_ray ray);
void			ft_error(char *msg, char *value);
void			ft_validate_configs(t_scheme *env);
void			ft_validate_str(char *str, char *id);
void			validate_texture(t_words texture, char *arg);
void			ft_input_validate(int ac, char **av, t_bool *is_screen);
void			map_validator(char **map);
void			add_cell(t_coord pos, t_list **sprites, t_player pl);
void			draw_sprites(t_list **sprites, double *wall_dist, t_all *all);
unsigned int	get_pixel_color(t_data tex);
void			ft_controller(t_all *all);
void			key_move(t_player *player,
					unsigned char move_flag, t_vars *vars);
int				cub_close(t_vars *vars);
void			get_textures(t_tex *tex, void *mlx_ptr, t_words str);
void			get_screenshot(t_scheme *env);
void			free_sprite(void *content);
void			free_all(t_all *all);

#endif
