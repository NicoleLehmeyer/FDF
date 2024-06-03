/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:55:26 by nlehmeye          #+#    #+#             */
/*   Updated: 2023/07/16 16:55:27 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Convert initial portion of string pointed to by str into int representation
//1. spaces etc.
//2. negative conversion
//3. a to i
//make a variable to store th result answer. what data type? int lol dum dum
//atoi(123a4) returns "123"
//are all those [i]'s necessary? Can they be replaced with *str? Yes
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	negative;
	int	n;

	n = 0;
	negative = 1;
	while (*str && (*str == 32 || (*str <= 13 && *str >= 9)))
		str++;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - 48);
		str++;
	}
	return (n * negative);
}
