/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:32:35 by nlehmeye          #+#    #+#             */
/*   Updated: 2023/07/11 15:32:39 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	d;
	size_t	s;

	if (len <= ft_strlen(dst))
		return (len + ft_strlen(src));
	d = ft_strlen(dst);
	s = 0;
	while ((src[s] != '\0') && (d + 1 < len))
	{
		dst[d] = src[s];
		d++;
		s++;
	}
	dst[d] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[s]));
}
