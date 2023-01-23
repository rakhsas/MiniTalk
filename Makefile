# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rakhsas <rakhsas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 23:21:00 by rakhsas           #+#    #+#              #
#    Updated: 2023/01/23 12:57:09 by rakhsas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra

CC = gcc

CLIENT = client
SERVER = server

CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

all: $(CLIENT) $(SERVER)

$(CLIENT) : client.c
		$(CC) $(CFLAGS) client.c utils.c -o client
$(SERVER) : server.c
		$(CC) $(CFLAGS) server.c utils.c -o server

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS) : client_bonus.c
		$(CC) $(CFLAGS) client_bonus.c utils.c -o client_bonus
$(SERVER_BONUS) : server_bonus.c
		$(CC) $(CFLAGS) server_bonus.c utils.c -o server_bonus
fclean:
	rm -rf $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all bonus
