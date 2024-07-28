/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:41:02 by nlehmeye          #+#    #+#             */
/*   Updated: 2023/08/01 17:41:04 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	if (!s1 && !set)
		return (NULL);
	while (start < end && (ft_strchr(set, s1[start])))
		start++;
	while (end > start && (ft_strchr(set, s1[end])))
		end--;
	ret = ft_substr(s1, start, ((end - start) + 1));
	return (ret);
}
