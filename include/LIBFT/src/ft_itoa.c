/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 21:39:55 by nlehmeye          #+#    #+#             */
/*   Updated: 2023/08/01 14:30:33 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numcount(int n)
{
	int	digits;

	digits = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		digits = digits + 1;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		digits++;
	}
	if (n <= 9)
		digits = digits + 1;
	return (digits);
}

char	*ft_itoa(int n)
{
	char	*a;
	long	nbr;
	int		i;

	nbr = n;
	a = malloc(ft_numcount(nbr) + 1);
	if (a == NULL)
		return (NULL);
	i = ft_numcount(nbr);
	a[i] = '\0';
	i--;
	if (nbr == 0)
		a[0] = '0';
	if (nbr < 0)
	{
		a[0] = '-';
		nbr = -nbr;
	}
	while (nbr != 0)
	{
		a[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i--;
	}
	return (a);
}
