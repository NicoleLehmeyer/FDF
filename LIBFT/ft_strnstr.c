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
// DEBUG: What happens when you start strncmp but then hit the limit of len??
//1. If statements or when needle is null or length of needle is 0, return null
//2. If statement for when needle strlen is greater than len, return null
//3. While loop, for while i < n
//4. Use strncmp to find first occurrence, when 0 is returned
//5. If i + strlen (needle) > n then return null
//6. Otherwise, return char pointer &haystack[i]
//7. i++ for the rest of the loop, then return null
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
