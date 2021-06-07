/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctragula <ctragula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 19:51:21 by ctragula          #+#    #+#             */
/*   Updated: 2021/02/15 21:00:28 by ctragula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERRORS_H
# define FT_ERRORS_H

# define ERROR "Error"
# define ERROR_COUNT_ARGS "Wrong count arguments for "
# define ERROR_VALUE_ARG "Wrong value of argument for "
# define ERROR_NUM_ARGS "Wrong number arguments"
# define ERROR_SECOND_ARG "Wrong name of second argument. Must be \"--save\""
# define ERROR_FIRST_ARG "Wrong name of first argument. Must be \"*.cub\""
# define ERROR_COLOR_ARG "Wrong number color (must be from '0' to '255') for "
# define ERROR_FIRST_LINE_MAP "Invalid parameter or map (Maybe trash in file)"
# define EMPTY_LINE_MAP "Empty line in map"
# define INVALID_MAP "Invalid map in line: "
# define MISSING_RESOLUTION "In file missing resolution."
# define MISSING_NORTH_TEXTURE "In file missing path for north texture."
# define MISSING_SOUTH_TEXTURE "In file missing path for south texture."
# define MISSING_WEST_TEXTURE "In file missing path for west texture."
# define MISSING_EAST_TEXTURE "In file missing path for east texture."
# define MISSING_SPRITE_TEXTURE "In file missing path for sprite."
# define MISSING_FLOOR_COLOR "In file missing color for floor."
# define MISSING_CEIL_COLOR "In file missing color for ceil."
# define MULTIPLAYER "In map 2 players and more."
# define OPENMAP "The map must be closed/surrounded by walls."
# define NO_PLAYER "Missing player in map."
# define ERROR_NULL_RESOLUTION "Value of resolution is zero."
# define ERROR_DOUBLE_CONFIG "double config declaration for "
# define ERROR_RESOLUTION_SIZE "resolution very big"
# define MISSING_TEXTURE_FILE "This file maybe missing, may broken, may wrong: "

#endif
