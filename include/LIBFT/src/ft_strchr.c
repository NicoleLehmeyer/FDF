/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:28:01 by nlehmeye          #+#    #+#             */
/*   Updated: 2023/11/16 11:16:43 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Locate first int c (converted to char) in the string *s.
//Terminating null character is considered part of the string
//If c is '\0', function will locate '\0'
//Returns pointer to c or NULL if param error

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	i;

	i = c;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == i)
			return ((char *)s);
		s++;
	}
	if (i == '\0')
		return ((char *)s);
	return (NULL);
}
