/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:32:48 by nlehmeye          #+#    #+#             */
/*   Updated: 2023/07/11 15:32:50 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	while ((src[i] != '\0') && (i < len - 1))
	{
		if (len == 0)
			return (ft_strlen(src));
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	n = ft_strlen(src);
	return (n);
}
