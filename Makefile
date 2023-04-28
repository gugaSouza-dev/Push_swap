# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gusouza- <gusouza-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 00:26:04 by gusouza-          #+#    #+#              #
#    Updated: 2023/04/10 00:42:29 by gusouza-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
SOURCES_LIST	=	main.c error.c arguments.c list.c moviments.c \
					super_moviments.c utils.c sort.c
OBJS			=	$(SOURCES_LIST:.c=.o)
LIBFT			=	${LIBFT_DIR}libft.a
LIBFT_DIR		=	./libft/
CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra -g

all: ${NAME}

libft: ${LIBFT}

${NAME}:	${LIBFT} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} ${INCLUDES} -o ${NAME}
#	@make clean
	@echo "push swap created successfully!"


${LIBFT}:
	clear && make -sC ${LIBFT_DIR}

clean:
	@make -sC ${LIBFT_DIR} clean
	@rm -rf ${OBJS}

fclean: clean
	@echo "Removing Libft..."
	@rm -rf ${LIBFT}
	@echo "Libft removed successfully!"
	@echo "Removing push swap..."
	@rm -rf ${NAME}
	@echo "push swap removed successfully!"

re:	fclean all

.PHONY:		all, clean, fclean, re
