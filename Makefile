# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sthrace <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 15:35:40 by sthrace           #+#    #+#              #
#    Updated: 2021/02/16 18:59:47 by sthrace          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c \
		Parser/ft_parser.c \
		Parser/ft_form.c \
		Parser/ft_selector.c \
		Utils/ft_utils.c \
		Print/print_int.c \
		Print/print_char.c \
		Print/print_str.c \
		Print/print_unsigned.c \
		Print/print_pointer.c \
		Print/print_hexa.c \
		Print/print_float.c \
		Print/print_g.c \
		Print/print_octal.c

NAME	= libftprintf.a
OBJS	= $(SRCS:.c=.o)
INCLUDES = -I./Includes
HEADER = Includes/ft_printf.h

WFLAGS	= -Wall -Wextra -Werror

.c.o:
	gcc $(WFLAGS) -c $< -o $(<:.c=.o) $(INCLUDES)
$(NAME): $(OBJS) $(HEADER)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: all
