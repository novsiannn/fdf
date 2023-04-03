# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 15:34:58 by nikitos           #+#    #+#              #
#    Updated: 2023/04/03 21:03:38 by nikitos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT = libftPrintf/libft
PRINTF = libftPrintf/printf
MINILIBX = mlx

SRCS =  src/fdf.c

OBJS = ${SRCS:.c=.o}

RM = rm -f

GREEN = \033[0;92m
BLUE = \033[0;34m

CFLAGS = -Wall -Wextra -Werror -g
CC = gcc

all:	$(NAME)

$(NAME):	$(OBJS)
			@make -C $(LIBFT)
			@make -C $(PRINTF)
			@make -C $(MINILIBX)
			mv $(LIBFT)/libft.a libft.a
			mv $(PRINTF)/libftprintf.a libftprintf.a
			mv $(MINILIBX)/libmlx.a libmlx.a
			gcc $(CFLAGS) $(OBJS) -L. -lft -lftprintf -o $(NAME)
			@echo "$(BLUE)FDF compiled!$(DEF_COLOR)"

clean:
		@make -C $(LIBFT) clean
		@make -C $(PRINTF) clean
		@make -C $(MINILIBX) clean
		$(RM) $(OBJS) libmlx.a
		$(RM) libft.a libftprintf.a

fclean: clean
		${RM} $(NAME)
		@echo "$(GREEN)Everything is cleaned!"

re:		fclean all

.PHONY:		all clean fclean re