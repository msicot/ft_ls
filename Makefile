# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msicot <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 14:13:34 by msicot            #+#    #+#              #
#    Updated: 2018/03/07 11:45:10 by msicot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = ft_ls.c ft_list_fx.c ft_flags.c ft_errors.c get_names.c ft_ls_0.c ft_recursive.c ft_path_check.c rm_node.c ft_listp.c ft_sortlist.c ft_sortlist_r.c ft_sortlist_t.c ft_print.c ft_option_l.c ft_types_l.c ft_del_info.c ft_time.c ft_filetype_l.c
	
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./inc/

LS_NAME = ft_ls
complete = @echo "\033[92mComplete\033[0m"
cleaning = @echo "LS building...\n\033[92mCleaning complete\033[0m"


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

make m : all
	@./a.out
