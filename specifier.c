/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 15:31:32 by kykim             #+#    #+#             */
/*   Updated: 2018/07/25 16:00:34 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specifier_1(int info[4], va_list ap, char c, int count)
{
	int num;

	num = 0;
	if (c == 's')
		num = convert_s_total(info, ap);
	else if (c == 'S')
		num = convert_s2(info, ap);
	else if (c == 'p')
		num = convert_p(info, ap);
	else if (c == 'd' || c == 'i')
		num = convert_i_d(info, ap);
	else if (c == 'D')
		num = convert_i_larged(info, ap);
	count = count + num;
	return (count);
}

int	specifier_2(int info[4], va_list ap, char c, int count)
{
	int num;

	num = 0;
	if (c == 'o')
		num = convert_o(info, ap);
	else if (c == 'O')
		num = convert_largeo(info, ap);
	else if (c == 'u')
		num = convert_u(info, ap);
	else if (c == 'U')
		num = convert_largeu(info, ap);
	else if (c == 'x')
		num = convert_x(info, ap);
	else if (c == 'X')
		num = convert_largex(info, ap);
	else if (c == 'c')
		num = convert_c(info, ap);
	else if (c == 'C')
		num = convert_cc(info, ap);
	count = count + num;
	return (count);
}
