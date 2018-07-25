# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kykim <kykim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/25 14:16:54 by kykim             #+#    #+#              #
#    Updated: 2018/07/25 15:55:58 by kykim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = convert_c_cc.c \
	   convert_i_d.c \
	   convert_i_d2.c \
	   convert_o.c \
	   convert_o2.c \
	   convert_p.c \
	   convert_s.c \
	   convert_s2.c \
	   convert_u.c \
	   convert_x.c \
	   convert_x2.c \
	   convert_x3.c \
	   etc.c \
	   etc2.c \
	   etc3.c \
	   etc4.c \
	   parsing.c \
	   ft_printf.c \
	   specifier.c \

SRCO = $(SRCS:.c=.o)

HEADER = ft_printf.h

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) :
	gcc -c $(FLAG) -I $(HEADER) $(SRCS)
	ar rc $(NAME) $(SRCO)
	ranlib $(NAME)

clean :
	rm -f $(SRCO)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
