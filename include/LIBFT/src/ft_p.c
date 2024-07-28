/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:07:22 by nlehmeye          #+#    #+#             */
/*   Updated: 2023/08/08 10:07:23 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numcount(size_t input)
{
	int	digits;

	digits = 0;
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

void	ft_p(size_t p, int *len)
{
	char	*string;
	int		i;
	int		j;

	j = 4;
	if (p != 0)
		j--;
	string = malloc(ft_numcount(p) + j);
	i = ft_numcount(p) + j - 1;
	if (string == NULL)
		return ;
	if (p == 0)
		string[2] = '0';
	string[i--] = '\0';
	string[0] = '0';
	string[1] = 'x';
	while (p != 0)
	{
		string[i--] = "0123456789abcdef"[p % 16];
		p /= 16;
	}
	ft_s(string, len);
	free(string);
}
