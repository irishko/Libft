#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irishko <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 22:23:27 by irishko           #+#    #+#              #
#    Updated: 2017/11/07 22:25:22 by irishko          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= libft.a
INC_DIR	= ./includes/
SRC_DIR	= ./src/
SRC_PD	= ./src_print/
CC		= gcc
LC		= ar rc
FG		= -Wall -Wextra -Werror
INC_HD	= $(addprefix $(INC_DIR),$(HD))
CFLAGS	= $(CC) $(FG) -I $(INC_HD)

SRC		= ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_minnum_mas.c \
		ft_maxnum_mas.c \
		ft_is_prime.c \
		ft_howletter.c \
		ft_countnbr.c \
		get_next_line.c \
		atoi_base.c \
		itoa_base.c \
		ft_isspace.c
SRC_PRI	= ft_charprnt.c \
		ft_hexade.c \
		ft_howlen.c \
		ft_iord.c \
		ft_point.c \
		ft_prinff.c \
		ft_printf.c \
		ft_printsecond.c \
		ft_putwstr.c \
		ft_retlen.c \
		ft_unsig.c

SRC_POS	= $(addprefix $(SRC_DIR),$(SRC))
HD		= libft.h
OBJ		= $(SRC:.c=.o)
O_PRI	= $(SRC_PRI:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(O_PRI)
	@$(LC) $(NAME) $(OBJ) $(O_PRI)

$(OBJ): %.o: $(SRC_DIR)%.c
	@$(CFLAGS) -c $< -o $@

$(O_PRI): %.o: $(SRC_DIR)$(SRC_PD)%.c
	@$(CFLAGS) -c $< -o $@

clean:
	@rm -Rf $(OBJ) $(O_PRI)

fclean: clean
	@rm -Rf $(NAME)

re: fclean all
