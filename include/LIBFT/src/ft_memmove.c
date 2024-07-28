/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:42:58 by nlehmeye          #+#    #+#             */
/*   Updated: 2023/07/18 09:42:59 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//memcpy but NO OVERRIDING

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst == NULL && src == NULL)
		return (NULL);
	if (src > dst)
		dst = ft_memcpy(dst, src, len);
	else
	{
		while (len--)
		{
			((char *)dst)[len] = ((char *)src)[len];
		}
	}
	return (dst);
}
