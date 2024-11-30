/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:42:36 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/30 18:33:32 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc(3)) and returns an array of strings obtained by
splitting ’s’ using the character ’c’ as a delimiter. The array must end with
a NULL pointer. */

#include "../so_long.h"

int	count_words(char *s, char c)
{
	int	words;
	int	in_word;

	words = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
		{
			words++;
			in_word = 0;
			while (*s == c)
				s++;
		}
		else
		{
			in_word = 1;
			s++;
		}
	}
	if (in_word)
		words++;
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
	int		word_len;
	char	**str;

	i = 0;
	j = 0;
	game->map.lines = count_words(game->map.buffer, c);
	str = (char **)malloc((game->map.lines + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (j < game->map.lines)
	{
		word_len = 0;
		while (game->map.buffer[i] != c && game->map.buffer[i])
		{
			word_len++;
			i++;
		}
		str[j++] = ft_substr(game->map.buffer, i - word_len, word_len);
		i++;
	}
	str[j] = NULL;
	game->map.columns = ft_strlen(str[0]);
	return (str);
}
