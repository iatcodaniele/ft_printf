# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diatco <diatco@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 14:29:36 by diatco            #+#    #+#              #
#    Updated: 2023/12/11 11:08:50 by diatco           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --VARIABLES--

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBCMP = ar rcs
RM = rm -f
FNC = ft_printf.c ft_printf_utils.c \

FNC_OBJ := $(FNC:.c=.o)

# --RULES--

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

$(NAME): $(FNC_OBJ)
	$(LIBCMP) $(NAME) $(FNC_OBJ)

clean:
	$(RM) $(FNC_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
