# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 15:34:58 by nikitos           #+#    #+#              #
#    Updated: 2023/04/02 14:43:18 by novsiann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT = libftPrintf/libft
PRINTF = libftPrintf/printf

SRCS =  src/fdf.c

OBJS = ${SRCS:.c=.o}

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g
CC = gcc

all:	$(NAME)

$(NAME):	$(OBJS)
			@make -C $(LIBFT)
			@make -C $(PRINTF)
			mv $(LIBFT)/libft.a libft.a
			mv $(PRINTF)/libftprintf.a libftprintf.a
			gcc $(CFLAGS) $(OBJS) -L. -lft -lftprintf -o $(NAME)

clean:
		@make -C $(LIBFT) clean
		@make -C $(PRINTF) clean
		$(RM) $(OBJS)
		$(RM) libft.a libftprintf.a

fclean: clean
		${RM} $(NAME)

re:		fclean all

.PHONY:		all clean fclean re