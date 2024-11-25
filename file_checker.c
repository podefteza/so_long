/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:22:03 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/25 12:14:24 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	extension_check(int argc, char **argv, t_game *game)
{
	size_t	len;

	if (argc != 2)
		cleanup_and_exit(game, "Error\nUsage: ./so_long map.ber\n", 42);
	len = ft_strlen(argv[1]);
	if ((len < 4 || ft_strncmp(argv[1] + len - 4, ".ber", 4) != 0))
		cleanup_and_exit(game,
			"Error\nInvalid file extension. Use .ber files only.\n", 42);
	return (0);
}

int	map_checker(char *argv, t_game *game)
{
	int	count;

	game->map.buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!game->map.buffer)
		cleanup_and_exit(game, "Memory allocation failed for buffer.\n", 42);
	game->map.map_read_fd = open(argv, O_RDONLY);
	if (game->map.map_read_fd == -1)
		cleanup_and_exit(game, "Failed to open map file.\n", 42);
	count = read(game->map.map_read_fd, game->map.buffer, BUFFER_SIZE);
	if (count == -1)
	{
		free(game->map.buffer);
		close(game->map.map_read_fd);
		cleanup_and_exit(game, "Failed to read map file.\n", 42);
	}
	close(game->map.map_read_fd);
	game->map.buffer[count] = '\0';
	game->map.map = ft_split(game, '\n');
	if (!game->map.map)
		cleanup_and_exit(game, "Failed to split map into lines.\n", 42);
	free(game->map.buffer);
	if (!player_count(game) || !check_rectangular(game) || !check_walls(game)
		|| !check_valid_path(game))
		free_map(game);
	return (1);
}
