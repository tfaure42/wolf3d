# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/18 11:04:41 by tfaure            #+#    #+#              #
#    Updated: 2017/06/26 10:13:54 by myernaux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
NAMEBIN = wolf3d.a
FLAGS = -Wall -Wextra #-Werror
INC = includes
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -lm
SRC_PATH = srcs
OBJ_PATH = obj
LIBFT_PATH = libft
LIBFTA = libft.a
LIBFT = $(addprefix $(LIBFT_PATH)/,$(LIBFTA))
SRC_NAME = parse.c init_data.c find_the_wall.c init_mlx.c set_degree.c draw_wall.c keycode.c move.c draw_env.c
SRCS = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJS = $(addprefix $(OBJ_PATH)/,$(SRC_NAME:.c=.o))

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m


all: $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@gcc $(FLAGS) -I $(INC) -o $@ -c $<

$(NAME): $(OBJS)
	@make -C $(LIBFT_PATH)
	@cp $(LIBFT) ./$(NAMEBIN)
	@ar rc $(NAMEBIN) $(OBJS)
	@ranlib $(NAMEBIN)
	@gcc -o $(NAME) $(NAMEBIN) srcs/main.c $(MLXFLAGS)
	@echo "$(GREEN)--------Wolf3D compiled--------$(NC)"

clean:
	@make clean -C $(LIBFT_PATH)
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@/bin/rm -rf $(NAMEBIN)
	@/bin/rm -rf $(NAME)
	@echo "$(GREEN)---Wolf3D removed completely---$(NC)"

re: fclean all
