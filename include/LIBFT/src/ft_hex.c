/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:09:44 by nlehmeye          #+#    #+#             */
/*   Updated: 2023/08/08 10:09:45 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numcount(unsigned int input)
{
	int	digits;

	digits = 0;
	if (input == 0)
		return (1);
	if (input < 0)
	{
		digits++;
		input = -input;
	}
	while (input != 0)
	{
		input /= 16;
		digits++;
	}
	return (digits);
}

void	ft_hex(unsigned int input, int *len, const char datatype)
{
	char	*hex;
	char	*string;
	int		i;

	string = malloc(ft_numcount(input) + 1);
	if (string == NULL)
		return ;
	i = ft_numcount(input);
	string[i] = '\0';
	hex = "0123456789abcdef";
	if (datatype == 'X')
		hex = "0123456789ABCDEF";
	if (input == 0)
		string[0] = '0';
	while (input != 0)
	{
		i--;
		string[i] = hex[input % 16];
		input /= 16;
	}
	ft_s(string, len);
	free(string);
}
