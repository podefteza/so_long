/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:22:03 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/21 10:41:03 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	extension_check(int argc, char **argv, t_game *game)
{
	size_t	len;

	if (argc != 2)
		error_output("Error\nUsage: ./so_long map.ber\n", game);
	len = ft_strlen(argv[1]);
	if ((len < 4 || ft_strncmp(argv[1] + len - 4, ".ber", 4) != 0))
		error_output("Error\nInvalid file extension. Use .ber files only.\n", game);
	return (0);
}

int	map_checker(char *argv, t_game *game)
{
	int	count;
	int	fd;

	game->map.buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!game->map.buffer)
		return (error_output("Memory allocation failed for buffer.\n", game));
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (error_output("Failed to open map file.\n", game));
	count = read(fd, game->map.buffer, BUFFER_SIZE);
	if (count == -1)
	{
		free(game->map.buffer);
		close(fd);
		return (error_output("Failed to read map file.\n", game));
	}
	close(fd);
	game->map.buffer[count] = '\0';
	game->map.map = ft_split(game, '\n');
	free(game->map.buffer);
	if (!game->map.map)
		return (error_output("Failed to split map into lines.\n", game));
	if (!player_count(game) || !check_rectangular(game)
		|| !check_walls(game) || !check_valid_path(game))
		free_map(game);
	return (1);
}
