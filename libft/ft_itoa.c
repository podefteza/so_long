/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos-j <carlos-j@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:04:29 by carlos-j          #+#    #+#             */
/*   Updated: 2024/11/12 14:10:58 by carlos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Converts an integer value to a null-terminated string.

#include "../so_long.h"

static unsigned int	ft_int_length(int integer)
{
	unsigned int	length;

	length = 0;
	if (integer < 0)
		length = 1;
	if (integer == 0)
		return (1);
	while (integer != 0)
	{
		integer = integer / 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char	*s;

	unsigned int (length);
	unsigned int (number);
	length = ft_int_length(n);
	s = (char *)malloc(sizeof(char) * (length + 1));
	if (s == NULL)
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		number = n * -1;
	}
	else
		number = n;
	if (number == 0)
		s[0] = '0';
	s[length] = '\0';
	while (number != 0)
	{
		s[length - 1] = (number % 10) + '0';
		number = number / 10;
		length--;
	}
	return (s);
}
