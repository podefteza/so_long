/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 08:03:57 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/22 08:26:05 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_output(char *error, t_game *game)
{
	ft_putstr_fd(error, 2);
	// free...
	free_collectibles(game);
	exit(1);
}
