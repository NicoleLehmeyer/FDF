/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <nlehmeye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:05:38 by nlehmeye          #+#    #+#             */
/*   Updated: 2024/05/05 13:05:40 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Count number of words in string
int	totalwordindest_fdf(char const *s, char c)
{
	int	totalword;

	totalword = 0;
	while (*s && (*s != '\n'))
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			totalword++;
			while (*s && *s != c)
				s++;
		}
	}
	return (totalword);
}

// Return max value of 2 integers
int	find_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

// Convert int to positive int
int	pos_conv(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

int	colour(int a, int b)
{
	if (a || b)
		return (0xe70c0c);
	else
		return (0xffffff);
}

void	ft_error(char *error_msg)
{
	ft_printf("%s\n", error_msg);
	exit(1);
}