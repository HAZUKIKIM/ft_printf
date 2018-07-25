/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_i_d2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 12:47:31 by kykim             #+#    #+#             */
/*   Updated: 2018/07/24 12:48:55 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		width_left(int info[4], int buffsize, intmax_t num)
{
	pos_neg_space(info, num);
	putzero(info, digit(num));
	ft_putonlynbr(num);
	if ((((info[0] % 100) / 10) != 1) && (((info[0] % 10)) != 1) && num >= 0)
	{
		while (buffsize > bigger(info[2], digit(num)))
		{
			write(1, " ", 1);
			buffsize--;
		}
	}
	else
	{
		while (buffsize > bigger(info[2], digit(num)) + 1)
		{
			write(1, " ", 1);
			buffsize--;
		}
	}
}

void		width(int info[4], int buffsize, intmax_t num)
{
	if ((info[0] % 1000) / 100 == 0)
	{
		while (buffsize > bigger(info[2], digit(num)) + 1)
		{
			write(1, " ", 1);
			buffsize--;
		}
		pos_neg_space(info, num);
		if (((info[0] % 100) / 10) != 1 && ((info[0] % 10)) != 1 && num >= 0)
			write(1, " ", 1);
		if (digit(num) > info[2])
			ft_putonlynbr(num);
		else
		{
			putzero(info, digit(num));
			ft_putonlynbr(num);
		}
	}
	else
		width_left(info, buffsize, num);
}
