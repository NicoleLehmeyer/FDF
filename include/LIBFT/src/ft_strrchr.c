/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:31:11 by nlehmeye          #+#    #+#             */
/*   Updated: 2023/07/16 18:31:13 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Search for last occurrence of c(converted to char) in *s
// Null terminator considered part of the string.
// Search begun from end of string, --

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if ((char)s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}
