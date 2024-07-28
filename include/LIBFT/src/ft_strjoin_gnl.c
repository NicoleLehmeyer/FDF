/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_gnl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <nlehmeye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 00:11:30 by nlehmeye          #+#    #+#             */
/*   Updated: 2024/07/26 00:11:32 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*newstring;
	size_t	i;
	size_t	j;

	if (!(s1))
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	i = 0;
	newstring = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (newstring == NULL)
		return (NULL);
	j = 0;
	while (s1[i] != '\0')
		newstring[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		newstring[i++] = s2[j++];
	newstring[i] = '\0';
	free(s1);
	return (newstring);
}
