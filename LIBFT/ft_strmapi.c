/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 16:19:14 by nlehmeye          #+#    #+#             */
/*   Updated: 2023/08/01 16:19:15 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*ret;

	i = 0;
	if (!(s && f))
		return (NULL);
	ret = malloc(ft_strlen(s) + 1);
	if (!ret)
		return (NULL);
	while (i < ft_strlen(s))
	{
		ret[i] = (*f)(i, s[i]);
		i++;
	}
	ret [i] = '\0';
	return (ret);
}
