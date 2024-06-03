/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:16:43 by nlehmeye          #+#    #+#             */
/*   Updated: 2023/07/30 16:16:45 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*n;
	size_t	i;
	size_t	j;

	i = 0;
	n = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (n == NULL)
		return (NULL);
	j = 0;
	while (s1[j] && s1 != NULL)
		n[i++] = s1[j++];
	j = 0;
	while (s2[j] && s2 != NULL)
		n[i++] = s2[j++];
	n[i++] = '\0';
	return (n);
}
