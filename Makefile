# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mathfern <mathfern@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 19:52:44 by mathfern          #+#    #+#              #
#    Updated: 2021/11/05 22:12:57 by mathfern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAMEBONUS = pipex_bonus

CC = clang -g -fsanitize=address 

CFLAGS = -Wall -Wextra -Werror 

HEADER = pipex.h

AUX =	

SRC =	./main.c \
		./src/pipex.c \
		./src/process.c \
		./aux/ft_putstr_fd.c \
		./aux/ft_split.c \
		./aux/ft_strlen.c \
		./aux/ft_strncmp.c \
		./aux/ft_substr.c \
		./aux/ft_calloc.c \
		./aux/ft_bzero.c 

SRCBONUS =	./main_bonus.c \
			./src/pipex.c \
			./src/process.c \
			./aux/ft_putstr_fd.c \
			./aux/ft_split.c \
			./aux/ft_strlen.c \
			./aux/ft_strncmp.c \
			./aux/ft_substr.c \
			./aux/ft_calloc.c \
			./aux/ft_bzero.c 

OBJ = $(SRC:c=o)

OBJBONUS = $(SRCBONUS:c=o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f $(OBJBONUS)

fclean:
	@rm -f $(OBJ)
	@rm -f $(OBJBONUS)
	@rm -f $(NAME)
	@rm -f $(NAMEBONUS)

re: fclean all

bonus: $(NAMEBONUS)

$(NAMEBONUS): $(OBJBONUS)
	$(CC) $(CFLAGS) -o $(NAMEBONUS) $(OBJBONUS)

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

.PHONY: all clean fclean re bonus
