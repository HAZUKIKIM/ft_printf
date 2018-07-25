/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_i_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 11:18:55 by kykim             #+#    #+#             */
/*   Updated: 2018/07/24 23:13:56 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	length_convert_i(int info[4], va_list ap)
{
	intmax_t num;

	if (info[3] == 1)
		num = (signed char)va_arg(ap, intmax_t);
	else if (info[3] == 2)
		num = (short)va_arg(ap, intmax_t);
	else if (info[3] == 3)
		num = (long long)va_arg(ap, intmax_t);
	else if (info[3] == 4)
		num = (long)va_arg(ap, intmax_t);
	else if (info[3] == 5)
		num = va_arg(ap, intmax_t);
	else if (info[3] == 6)
		num = (size_t)va_arg(ap, intmax_t);
	else
		num = (int)va_arg(ap, intmax_t);
	return (num);
}

void		pos_neg_space(int info[4], intmax_t num)
{
	if ((((info[0] % 10)) == 1) && (((info[0] % 100) / 10) != 1) && num >= 0)
		write(1, " ", 1);
	if (((info[0] % 100) / 10) == 1 && num >= 0)
		write(1, "+", 1);
	if (num < 0)
		write(1, "-", 1);
}

int			buff_same_digit(int info[4], intmax_t num, int buffsize)
{
	pos_neg_space(info, num);
	ft_putonlynbr(num);
	if (info[0] == 0 && num >= 0)
		return (buffsize);
	else
		return (buffsize + 1);
}

int			convert_i_d(int info[4], va_list ap)
{
	intmax_t	num;
	int			buffsize;
	int			printed_byte;

	printed_byte = 0;
	num = length_convert_i(info, ap);
	buffsize = bigger(info[2], bigger(info[1], digit(num)));
	if (buffsize == digit(num))
		return (buff_same_digit(info, num, buffsize));
	else if (buffsize == info[1])
	{
		width(info, buffsize, num);
		return (buffsize);
	}
	else if (buffsize == info[2])
	{
		pos_neg_space(info, num);
		putzero(info, digit(num));
		ft_putonlynbr(num);
		if (info[0] == 0 && num >= 0)
			return (buffsize);
		else
			return (buffsize + 1);
	}
	return (0);
}

int			convert_i_larged(int info[4], va_list ap)
{
	intmax_t	num;
	int			buffsize;
	int			printed_byte;

	printed_byte = 0;
	num = (long)va_arg(ap, intmax_t);
	buffsize = bigger(info[2], bigger(info[1], digit(num)));
	if (buffsize == digit(num))
		return (buff_same_digit(info, num, buffsize));
	else if (buffsize == info[1])
	{
		width(info, buffsize, num);
		return (buffsize);
	}
	else if (buffsize == info[2])
	{
		pos_neg_space(info, num);
		putzero(info, digit(num));
		ft_putonlynbr(num);
		if (info[0] == 0 && num >= 0)
			return (buffsize);
		else
			return (buffsize + 1);
	}
	return (0);
}
