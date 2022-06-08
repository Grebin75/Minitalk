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

CFLAGS = -g -Werror -Wall -Wextra

SERVER = SERVER
SERVER_SRCS = server.o

CLIENT = CLIENT
CLIENT_SRCS = client.o

all : $(SERVER) $(CLIENT)

$(SERVER) : $(SERVER_SRCS)
	@$(CC) $(SERVER_SRCS) -o $(SERVER)

$(CLIENT) : $(CLIENT_SRCS)
	@$(CC) $(CLIENT_SRCS) -o $(CLIENT)
clean:
			@$(RM) $(SERVER_SRCS) $(CLIENT_SRCS)

fclean:		clean
			@$(RM) $(SERVER_SRCS) $(CLIENT_SRCS)

re:			fclean all

.PHONY:		all clean fclean re