# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nikitos <nikitos@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 15:34:58 by nikitos           #+#    #+#              #
#    Updated: 2023/03/21 22:19:41 by nikitos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

LIBFT = libftPrintf/libft
PRINTF = libftPrintf/src

CLIENT_MAIN =  client.c
SERVER_MAIN = server.c

SERVER_OBJ_MAIN = ${SERVER_MAIN:.c=.o}
CLIENT_OBJ_MAIN = ${CLIENT_MAIN:.c=.o}

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g

CC = gcc

all:	$(SERVER) $(CLIENT)

$(SERVER):	$(SERVER_OBJ_MAIN)
			@make -C $(LIBFT)
			@make -C $(PRINTF)
			mv $(LIBFT)/libft.a libft.a
			mv $(PRINTF)/libftprintf.a libftprintf.a
			gcc $(CFLAGS) $(SERVER_OBJ_MAIN) -L. -lft -lftprintf -o $(SERVER)

$(CLIENT):	$(CLIENT_OBJ_MAIN)
			gcc $(CFLAGS) $(CLIENT_OBJ_MAIN) -L. -lft -lftprintf -o $(CLIENT)

clean:
		@make -C $(LIBFT) clean
		@make -C $(PRINTF) clean
		$(RM) $(SERVER_OBJ_MAIN) $(CLIENT_OBJ_MAIN)
		$(RM) libft.a libftprintf.a

fclean: clean
		${RM} $(SERVER) $(CLIENT)

re:		fclean all

.PHONY:		all clean fclean re