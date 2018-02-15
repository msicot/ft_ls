# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msicot <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 14:13:34 by msicot            #+#    #+#              #
#    Updated: 2018/02/14 19:16:24 by msicot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = 
	
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
	@ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean :
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATHJ) 2> /dev/null || true
	@echo "Objects have been removed"

fclean : clean
	@rm -f $(NAME)
	@echo "Library have been removed"

re : fclean all
