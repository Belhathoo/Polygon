# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oouklich <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/24 18:58:22 by oouklich          #+#    #+#              #
#    Updated: 2019/12/24 20:29:24 by oouklich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = polygon

SRC = main.c\
	   draw.c\
	   keys.c\
	   ft_atod.c\
	   draw_line.c\
	   calcul_angle.c\
	   sort_list.c\
	   parser.c\
	   twodimlen.c\
	   twodimfree.c\
	   read.c
SRCS = $(addprefix srcs/, $(SRC))
OBJS = $(SRC:%.c=objs/%.o)
OBJS_DIR = objs

ifeq ($(shell uname), Darwin)
$(info MacOs detected)
MLX_DIR = minilibx_macos
else
$(info $(shell uname) detected)
MLX_DIR = minilibx_linux
endif
ifeq ($(shell uname), Darwin)
MLX = -lmlx -framework OpenGL -framework AppKit
else
MLX = -lm -lmlx -lXext -lX11
endif

LIBFT = libft -lft
LIBFT_DIR = libft

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	gcc -o $@ $(OBJS) -L $(MLX_DIR) $(MLX) -I $(MLX_DIR) -L $(LIBFT) -I $(LIBFT_DIR) -I .

$(OBJS_DIR):
	mkdir -p $@

objs/%.o: srcs/%.c graphic.h
	gcc -c $< -o $@ -I $(MLX_DIR) -I .

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
