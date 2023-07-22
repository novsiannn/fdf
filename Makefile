# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 15:34:58 by nikitos           #+#    #+#              #
#    Updated: 2023/07/21 23:32:10 by novsiann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT = libftPrintf/libft
PRINTF = libftPrintf/printf
MINILIBX = mlx

SRCS =  src/main.c src/read_file.c src/key_events.c src/draw.c src/utils.c src/utils_2.c src/draw_2.c src/escape.c

OBJS = ${SRCS:.c=.o}

RM = rm -f

GREEN = \033[0;92m
BLUE = \033[0;34m

CFLAGS = -Wall -Wextra -Werror -g -Imlx
CC = gcc
# -fsanitize=address
all:	$(NAME)

$(NAME):	$(OBJS)
			@make -C $(LIBFT)
			@make -C $(PRINTF)
			@make -C $(MINILIBX)
			mv $(LIBFT)/libft.a libft.a
			mv $(PRINTF)/libftprintf.a libftprintf.a
			gcc $(CFLAGS) $(OBJS) -L. -Lmlx -lftprintf -lmlx -framework OpenGL -framework AppKit -o $(NAME) libft.a libftprintf.a
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