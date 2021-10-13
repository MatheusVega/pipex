# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mathfern <mathfern@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 19:52:44 by mathfern          #+#    #+#              #
#    Updated: 2021/10/08 20:10:35 by mathfern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 

OBJS = ${SRCS:.c=.o}

CC = gcc -fsanitize=address -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = pipex

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	$(OBJS) make -C ${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
			make -C clean ${RM} ${OBJS}

fclean:		clean make -C clean ${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
