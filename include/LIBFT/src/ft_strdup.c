/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:56:01 by nlehmeye          #+#    #+#             */
/*   Updated: 2023/07/16 16:56:03 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*n;
	size_t	i;
	size_t	space;

	i = 0;
	space = ft_strlen(s1) + 1;
	n = malloc(space);
	if (n == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		n[i] = s1[i];
		i++;
	}
	n[i] = '\0';
	return (n);
}
