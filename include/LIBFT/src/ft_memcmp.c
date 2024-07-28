/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:55:49 by nlehmeye          #+#    #+#             */
/*   Updated: 2023/07/16 16:55:51 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Compares byte string s1 against byte string s2
//Both strings are assumed to be n bytes long.
//NOTE TO SELF: (void *) don't have '\0' like strings

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
