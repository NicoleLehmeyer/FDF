/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:58:10 by nlehmeye          #+#    #+#             */
/*   Updated: 2023/07/16 16:58:11 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Compare *s1 and *s2
// RETURN: Difference between the first different character in the strings

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(s1) && i <= ft_strlen(s2) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
