# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sthrace <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 15:35:40 by sthrace           #+#    #+#              #
#    Updated: 2020/12/14 17:18:50 by sthrace          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c \
			Parsers/ft_parse_prec.c \
			Parsers/ft_parse_width.c \
			Parsers/ft_form.c \
			Print/ft_type_char.c \
			Print/ft_type_hexa.c \
			Print/ft_type_int.c \
			Print/ft_type_unsgn.c \
			Print/ft_type_str.c \
			Print/ft_type_num.c \
			Print/ft_type_ptr.c \
			Utils/ft_atoi.c \
			Utils/ft_isdigit.c \
			Utils/ft_itoa.c \
			Utils/ft_strchr.c \
			Utils/ft_strlen.c \
			Utils/ft_substr.c \
			Utils/ft_toupper.c \

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
