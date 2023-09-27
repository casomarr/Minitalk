# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: casomarr <casomarr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/27 13:00:28 by carolina          #+#    #+#              #
#    Updated: 2023/05/11 17:26:21 by casomarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL := all

NAME_CLIENT = client
NAME_CLIENT_BONUS = client_bonus

NAME_SERVER = server
NAME_SERVER_BONUS = server_bonus

PATH_FT_PRINTF = ft_printf
FT_PRINTF = $(PATH_FT_PRINTF)/libftprintf.a

PATH_PROGRAM = src

CLIENT = $(PATH_PROGRAM)/main_client.c \
		$(PATH_PROGRAM)/utils.c \
		$(PATH_PROGRAM)/utils2.c \

CLIENT_BONUS = $(PATH_PROGRAM)/main_client_bonus.c \
		$(PATH_PROGRAM)/utils_bonus.c \
		$(PATH_PROGRAM)/utils2_bonus.c \

SERVER = $(PATH_PROGRAM)/main_server.c \
		$(PATH_PROGRAM)/utils.c \
		$(PATH_PROGRAM)/utils2.c \

SERVER_BONUS = $(PATH_PROGRAM)/main_server_bonus.c \
		$(PATH_PROGRAM)/utils_bonus.c \
		$(PATH_PROGRAM)/utils2_bonus.c \

CLIENT_OBJS = $(CLIENT:.c=.o)
CLIENT_OBJS_BONUS = $(CLIENT_BONUS:.c=.o)

SERVER_OBJS = $(SERVER:.c=.o)
SERVER_OBJS_BONUS = $(SERVER_BONUS:.c=.o)

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g3

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(PATH_FT_PRINTF) -I $(PATH_PROGRAM)

$(FT_PRINTF):
	@toilet FT_PRINTF -F border -f wideterm
	@$(MAKE) --no-print-directory -C $(PATH_FT_PRINTF)

$(NAME_CLIENT): $(CLIENT_OBJS)
	@toilet CLIENT -F border -f wideterm
	@$(MAKE) --no-print-directory -C $(PATH_FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(CLIENT_OBJS) $(FT_PRINTF)

$(NAME_CLIENT_BONUS): $(CLIENT_OBJS_BONUS)
	@toilet CLIENT BONUS -F border -f wideterm
	@$(MAKE) --no-print-directory -C $(PATH_FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT_BONUS) $(CLIENT_OBJS_BONUS) $(FT_PRINTF)

$(NAME_SERVER): $(SERVER_OBJS)
	@toilet SERVER -F border -f wideterm
	@$(MAKE) --no-print-directory -C $(PATH_FT_PRINTF)
	$(CC) $(CFLAGS) -o ${NAME_SERVER} $(SERVER_OBJS) $(FT_PRINTF)

$(NAME_SERVER_BONUS): $(SERVER_OBJS_BONUS)
	@toilet SERVER BONUS -F border -f wideterm
	@$(MAKE) --no-print-directory -C $(PATH_FT_PRINTF)
	$(CC) $(CFLAGS) -o ${NAME_SERVER_BONUS} $(SERVER_OBJS_BONUS) $(FT_PRINTF)

all: $(FT_PRINTF) $(NAME_CLIENT) $(NAME_SERVER)
	clear
	@toilet COMPILED -F border -f wideterm

bonus : $(FT_PRINTF) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)
	clear
	@toilet BONUS COMPILED -F border -f wideterm


clean:
	$(RM) $(CLIENT_OBJS) $(CLIENT_OBJS_BONUS) $(SERVER_OBJS) $(SERVER_OBJS_BONUS)
	@$(MAKE) -C ${PATH_FT_PRINTF} clean
	clear
	@toilet CLEAN -F border -f wideterm

fclean: clean
	$(RM) $(NAME_CLIENT) $(NAME_CLIENT_BONUS) $(NAME_SERVER) $(NAME_SERVER_BONUS)
	@$(MAKE) -C ${PATH_FT_PRINTF} fclean
	clear
	@toilet FCLEAN -F border -f wideterm

re: fclean all

.PHONY: all clean fclean re