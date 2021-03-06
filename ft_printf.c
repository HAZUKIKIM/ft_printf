/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 11:58:09 by kykim             #+#    #+#             */
/*   Updated: 2018/07/25 16:00:47 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	doublepercent(const char *str, int i)
{
	if (str[i] == '%' && str[i + 1] == '%')
		return (1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		info[4];
	va_list	ap;
	int		count;

	va_start(ap, str);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (doublepercent(str, i))
		{
			write(1, "%", 1);
			i += 2;
			count += 1;
			continue;
		}
		if (str[i] == '%')
		{
			i = allcheck(str, i, info, ap);
			count = specifier_1(info, ap, str[i], count);
			count = specifier_2(info, ap, str[i], count);
			i++;
		}
		write(1, &str[i], 1);
		count += 1;
		i++;
	}
	va_end(ap);
	return (count);
}
