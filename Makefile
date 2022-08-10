# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcoutinh <hcoutinh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/03 11:17:11 by hcoutinh          #+#    #+#              #
#    Updated: 2022/06/07 17:53:46 by hcoutinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -g -Werror -Wall -Wextra -fsanitize=address

SERVER = server
SERVER_SRCS = server.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

CLIENT = client
CLIENT_SRCS = client.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

all : $(SERVER) $(CLIENT)

$(SERVER) : $(SERVER_OBJS)
	@$(CC) $(CFLAGS) $(SERVER_OBJS) -o $(SERVER)

$(CLIENT) : $(CLIENT_OBJS)
	@$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(CLIENT)
clean:
			@$(RM) $(SERVER_OBJS) $(CLIENT_OBJS) 

fclean:		clean
			@$(RM) $(SERVER) $(CLIENT)

re:			fclean all

.PHONY:		all clean fclean re