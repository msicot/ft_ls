# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msicot <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 14:13:34 by msicot            #+#    #+#              #
#    Updated: 2018/02/15 14:05:31 by msicot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = ft_strlen.c	ft_strdup.c	ft_strcpy.c	ft_strncpy.c ft_strcat.c	ft_strncat.c	ft_strlcat.c	ft_strchr.c	ft_strrchr.c	\
		ft_strstr.c	ft_strnstr.c	ft_strcmp.c	ft_strncmp.c	ft_memset.c	ft_bzero.c	ft_memcpy.c	ft_memccpy.c ft_memmove.c	ft_memchr.c	\
		ft_memcmp.c	ft_atoi.c	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	ft_isascii.c	ft_isprint.c ft_toupper.c	ft_tolower.c	\
		ft_memalloc.c ft_memdel.c	ft_strnew.c	ft_strdel.c	ft_strclr.c	ft_striter.c ft_striteri.c	ft_strmap.c	ft_strmapi.c ft_strequ.c \
		ft_strnequ.c ft_strsub.c	ft_strjoin.c	ft_strtrim.c	ft_strsplit.c	ft_putchar.c	ft_putstr.c	ft_putendl.c	ft_putnbr.c	\
		ft_putchar_fd.c		ft_putstr_fd.c ft_putendl_fd.c	ft_putnbr_fd.c	ft_itoa.c	ft_lstnew.c	ft_lstdel.c	ft_lstdelone.c	ft_lstadd.c	\
		ft_lstiter.c	ft_lstmap.c	ft_is_negative.c ft_strlowcase.c	ft_strupcase.c	ft_iterative_factorial.c ft_sqrt.c ft_printf.c \
		ft_error.c ft_flags.c	ft_format.c	ft_integer.c	ft_is_type.c	ft_itoa_max.c	ft_options.c	ft_printf.c	ft_read.c \
		ft_is_num.c ft_is_c.c ft_is_p.c	ft_is_unic.c ft_is_unis.c ft_string.c ft_octal.c ft_octal2.c	ft_itoa_base.c	ft_itoa_base_u.c \
		ft_width.c ft_sign.c ft_precision.c ft_is_u.c ft_itoa_usigned.c ft_width_o.c ft_width_x.c ft_hexa.c ft_hexa2.c ft_null.c ft_pourc.c \
		ft_width_p.c ft_wipre_unis.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./inc/

CC = gcc
CFLAGS = -Werror -Wextra -Wall
NAME = libft.a
		
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME)) 
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Generating objects for the library.."
	@echo "Generating the library.."
	@ar rc $(NAME) $(OBJ)
	@echo "Indexing the library.."
	@echo "Done."
	@ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean :
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATHJ) 2> /dev/null || true
	@echo "Libft's objects have been removed"

fclean : clean
	@rm -f $(NAME)
	@echo "Library have been removed"

re : fclean all
