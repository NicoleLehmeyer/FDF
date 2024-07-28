/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:23:30 by nlehmeye          #+#    #+#             */
/*   Updated: 2023/07/17 12:23:33 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Locate first occurence of the null-terminated 'needle' in 'haystack'
// Where not more than len characters are searched.

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		if (ft_strncmp(&haystack[i], needle, ft_strlen(needle)) == 0)
		{
			if (i + (ft_strlen(needle)) > len)
				return (0);
			return (&((char *)haystack)[i]);
		}
		i++;
	}
	return (NULL);
}
