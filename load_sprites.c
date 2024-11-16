/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:17:54 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/16 12:47:04 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprites(t_game *game, int img_size)
{
	game->sprites.background = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			BACKGROUND_SPRITE, &img_size, &img_size);
	game->sprites.player = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			PLAYER_RIGHT_SPRITE, &img_size, &img_size);
	game->sprites.player_right = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			PLAYER_RIGHT_SPRITE, &img_size, &img_size);
	game->sprites.player_left = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			PLAYER_LEFT_SPRITE, &img_size, &img_size);
	game->sprites.exit = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			CLOSED_DOOR_SPRITE, &img_size, &img_size);
	game->sprites.collectible = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			COLLECTIBLE_SPRITE, &img_size, &img_size);
	game->sprites.wall = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			WALL_SPRITE, &img_size, &img_size);
	game->sprites.player_left_closed_door = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			PLAYER_LEFT_CLOSED_DOOR_SPRITE, &img_size, &img_size);
	game->sprites.player_right_closed_door = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			PLAYER_RIGHT_CLOSED_DOOR_SPRITE, &img_size, &img_size);
	game->sprites.player_left_open_door = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			PLAYER_LEFT_OPEN_DOOR_SPRITE, &img_size, &img_size);
	game->sprites.player_right_open_door = mlx_xpm_file_to_image(game->minilibx.connect_mlx,
			PLAYER_RIGHT_OPEN_DOOR_SPRITE, &img_size, &img_size);
}
