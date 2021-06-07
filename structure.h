/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctragula <ctragula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 11:32:39 by ctragula          #+#    #+#             */
/*   Updated: 2021/02/15 15:19:14 by ctragula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include "libft/libft.h"

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_words
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*sprite;
}					t_words;

typedef struct		s_coord
{
	double			x;
	double			y;
}					t_coord;

typedef struct		s_calc
{
	t_coord			wall;
	double			len;
}					t_calc;

typedef struct		s_color
{
	int				floor;
	int				ceil;
}					t_color;

typedef struct		s_player
{
	t_coord			pos;
	double			dir;
}					t_player;

typedef struct		s_scheme
{
	t_point			resolution;
	t_words			texture;
	t_color			colors;
	t_player		player;
	t_list			*sprites;
	char			**map;
	unsigned char	move_flag;
}					t_scheme;

typedef struct		s_sprite
{
	t_coord			pos;
	double			dist;
	double			dist2;
	double			dir;
	int				size;
	t_point			start;
	int				h_offset;
	int				v_offset;
}					t_sprite;

typedef struct		s_ray
{
	t_coord			step;
	double			angle;
	int				num;
}					t_ray;

typedef struct		s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				x;
	int				y;
	double			scale;
	int				start_x;
	int				start_y;
}					t_data;

typedef struct		s_data_map
{
	int				color;
	t_coord			coord;
}					t_data_map;

typedef struct		s_vars
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_vars;

typedef struct		s_tex
{
	t_data			no_tex;
	t_data			so_tex;
	t_data			we_tex;
	t_data			ea_tex;
	t_data			sp_tex;
}					t_tex;

#endif
