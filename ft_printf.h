/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kykim <kykim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 11:58:36 by kykim             #+#    #+#             */
/*   Updated: 2018/07/25 15:54:01 by kykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <stdint.h>

//ft_printf.c
int	doublepercent(const char *str, int i);
int	ft_printf(const char *str, ...);

//parsing.c
int	flagcheck(const char *str, int i, int info[4]);
int	widthcheck(const char *str, int i, int info[4], va_list ap);
int	precisioncheck(const char *str, int i, int info[4], va_list ap);
int	lengthcheck(const char *str, int i, int info[4]);
int	allcheck(const char *str, int i, int info[4], va_list ap);

//convert_c_cc.c
char *print_left(char *buff, int buffsize, wint_t c, int i);
char *print_right(char *buff, int buffsize, wint_t c, int i);
int convert_c(int info[4], va_list ap);
int		convert_cc(int info[4], va_list ap);

//etc.c
void ft_putstr(char *str);
void ft_putwstr(wchar_t *str);
int ft_strlen(char *str);
int smaller(int a, int b);
int bigger(int a, int b);

//etc2.c
int ft_wstrlen(wchar_t *str);
void ft_putchar(char c);
int digit(intmax_t num);
void	ft_putonlynbr(intmax_t n);
void putzero(int info[4], int digit);

//etc3.c
int hex_digit(uintmax_t num);
void print_hex_x(uintmax_t num);
void print_hex_largex(uintmax_t num);
uintmax_t length_convert_x(int info[4], va_list ap);
uintmax_t	length_convert_o(int info[4], va_list ap);

//etc4.c
int	oct_digit(uintmax_t num);
void print_oct_o(uintmax_t num);
uintmax_t	length_convert_u(int info[4], va_list ap);
int		u_digit(uintmax_t num);
void	ft_putonly_unbr(uintmax_t n);

//convert_s.c
int setbuffsize(int info[4], int strlen);
void yes_flag(int info[4], int buffsize, char *buff, char *str);
void no_flag(int info[4], int buffsize, char *buff, char *str);
int convert_s(int info[4], va_list ap);

//convert_s2.c
void	yes_flagw(int info[4], int buffsize, wchar_t *buff, wchar_t *str);
void	no_flagw(int info[4], int buffsize, wchar_t *buff, wchar_t *str);
int		convert_s2(int info[4], va_list ap);
int		convert_s_total(int info[4], va_list ap);

//convert_i_d.c
intmax_t	length_convert_i(int info[4], va_list ap);
void		pos_neg_space(int info[4], intmax_t num);
int			buff_same_digit(int info[4], intmax_t num, int buffsize);
int			convert_i_d(int info[4], va_list ap);
int			convert_i_larged(int info[4], va_list ap);

//convert_i_d2.c
void		width_left(int info[4], int buffsize, intmax_t num);
void		width(int info[4], int buffsize, intmax_t num);

//convert_x.c
int same_hex_digit(int info[4], uintmax_t num, int digit);
int same_hex_precision(int info[4], uintmax_t num, int digit);
int width_without_hash(int info[4], uintmax_t num, int digit, int i);
int width_with_hash_largewidth(int info[4], uintmax_t num, int digit, int i);
int same_hex_width(int info[4], uintmax_t num, int digit);

//convert_x2.c    
int		convert_x(int info[4], va_list ap);
int convert_largex(int info[4], va_list ap);

//convert_x3.c
int	same_hex_digit_l(int info[4], uintmax_t num, int digit);
int	same_hex_precision_l(int info[4], uintmax_t num, int digit);
int	width_without_hash_l(int info[4], uintmax_t num, int digit, int i);
int	width_with_hash_largewidth_l(int info[4], uintmax_t num, int digit, int i);
int	same_hex_width_l(int info[4], uintmax_t num, int digit);

//convert_o.c
int	same_oct_digit(int info[4], uintmax_t num, int digit);
int	same_oct_precision(int info[4], uintmax_t num, int digit);
int	same_oct_width(int info[4], uintmax_t num, int digit);
int convert_o(int info[4], va_list ap);
int	convert_largeo(int info[4], va_list ap);

//convert_o2.c
int		width_without_hash_o(int info[4], uintmax_t num, int digit, int i);
void	width_with_hash_largew_o_l(int info[4], uintmax_t num, int digit, int i);
int		width_with_hash_largew_o(int info[4], uintmax_t num, int digit, int i);

//convert_u.c
void	u_buff_same_width(int info[4], int digit, uintmax_t num);
int		convert_u(int info[4], va_list ap);
int		convert_largeu(int info[4], va_list ap);

//convert_p.c 
void	convert_p_width(int info[4], uintmax_t ptr, int digit);
int		convert_p(int info[4], va_list ap);

//specifier.c
int specifier_1(int info[4], va_list ap, char c, int count);
int specifier_2(int info[4], va_list ap, char c, int count);
#endif
