# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibel-kha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/18 16:29:21 by ibel-kha          #+#    #+#              #
#    Updated: 2019/12/18 16:29:28 by ibel-kha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = POLYGONE

SRCS =  read.c\
        triangles.c\
		calcul.c\
		init.c\
		main.c\
		quadrilatere.c\
		ft_quadri.c\
		sort.c\
		calc_angle.c\
		parser.c
OBJ = $(SRCS:.c=.o)

LIBFT = -L libft -lft

CFLAGS = -Wall -Wextra -Werror

CC = gcc $(CFLAGS)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft libft.a
	@$(CC) -o $@ $(OBJ) -lm $(LIBFT)

%.o: %.c
	$(CC) -c $< -o $@ 

clean:
	@make clean -C libft/
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)

re: fclean all
