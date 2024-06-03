/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:08:01 by nlehmeye          #+#    #+#             */
/*   Updated: 2023/08/08 10:08:03 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_datatype(const char datatype, va_list *args, int *len, int *i)
{
	if (datatype == 'c')
		ft_c(va_arg(*args, int), len);
	else if (datatype == 's')
		ft_s(va_arg(*args, const char *), len);
	else if (datatype == 'p')
		ft_p(va_arg(*args, size_t), len);
	else if (datatype == 'd' || datatype == 'i')
		ft_num(va_arg(*args, unsigned int), len);
	else if (datatype == 'u')
		ft_u(va_arg(*args, unsigned int), len);
	else if (datatype == 'x' || datatype == 'X')
		ft_hex(va_arg(*args, unsigned int), len, datatype);
	else if (datatype == '%')
		ft_c('%', len);
	else
		(*i)--;
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			ft_datatype(s[i], &args, &len, &i);
			i++;
		}
		else
		{
			write(1, &s[i], 1);
			i++;
			len++;
		}
	}
	va_end(args);
	return (len);
}
