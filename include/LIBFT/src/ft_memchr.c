/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:04:10 by nlehmeye          #+#    #+#             */
/*   Updated: 2023/07/14 19:04:12 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Search n bytes from *s for int c
//Return first occurence of c

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *)s;
	while (i < n)
	{
		if (p[i] == (char)c)
			return (&p[i]);
		i++;
	}
	return (0);
}
