# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msicot <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 14:13:34 by msicot            #+#    #+#              #
#    Updated: 2018/02/15 14:09:57 by msicot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = ft_ls.c 
	
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./inc/

LS_NAME = ft_ls
complete = @echo "\033[92mComplete\033[0m"
cleaning = @echo "\033[92mCleaning complete\033[0m"

CC = gcc
CFLAGS = -Werror -Wextra -Wall
NAME = ft_ls
		
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME)) 
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	@gcc -Wextra -Werror -Wall $(OBJ) -L./libft/ -lft -o $(LS_NAME)
	$(complete)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@echo "Building ft_ls"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean :
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATHJ) 2> /dev/null || true
	@make clean -C ./libft
	@echo "LS's objects have been removed"
	$(cleaning)

fclean : clean
	@rm -f $(NAME)
	@make fclean -C ./libft
	@echo "LS has been removed"

re : fclean all
