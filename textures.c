/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctragula <ctragula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 14:34:10 by ctragula          #+#    #+#             */
/*   Updated: 2021/02/15 15:17:44 by ctragula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_one_texture(t_data *tex, void *mlx_ptr, char *filename)
{
	tex->img = mlx_xpm_file_to_image(mlx_ptr, filename, &tex->x, &tex->y);
	if (!tex->img)
		ft_error(MISSING_TEXTURE_FILE, filename);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
									&tex->line_length, &tex->endian);
}

void		get_textures(t_tex *tex, void *mlx_ptr, t_words str)
{
	get_one_texture(&tex->no_tex, mlx_ptr, str.no);
	get_one_texture(&tex->so_tex, mlx_ptr, str.so);
	get_one_texture(&tex->we_tex, mlx_ptr, str.we);
	get_one_texture(&tex->ea_tex, mlx_ptr, str.ea);
	get_one_texture(&tex->sp_tex, mlx_ptr, str.sprite);
}
