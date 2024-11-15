/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:42:36 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/06 17:18:37 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc(3)) and returns an array of strings obtained by
splitting ’s’ using the character ’c’ as a delimiter. The array must end with
a NULL pointer. */

#include "../so_long.h"

int	count_words(char *s, char c)
{
	int	words;
	int	flag;

	words = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			flag = 1;
			words++;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (words);
}

int	count_letters(char *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

char	**ft_split(t_game *game, char c)
{
	int		i;
	int		j;
	char	**str;

	if (!game->map.buffer)
		return (NULL);
	i = 0;
	j = -1;
	game->map.lines = count_words(game->map.buffer, c);
	str = (char **)malloc((game->map.lines + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (++j < game->map.lines)
	{
		while (game->map.buffer[i] == c)
			i++;
		str[j] = ft_substr(game->map.buffer, i,
				count_letters(game->map.buffer, c, i));
		if (!str)
			return (NULL);
		i += count_letters(game->map.buffer, c, i);
	}
	str[j] = 0;
	game->map.columns = ft_strlen(str[0]);
	return (str);
}
