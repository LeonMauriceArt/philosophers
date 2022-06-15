# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmaurin- <lmaurin-@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 17:51:28 by lmaurin-          #+#    #+#              #
#    Updated: 2022/06/15 15:39:17 by lmaurin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philosophers
HEADER	=	philosophers.h
OBJ		=	$(SRC:.c=.o)
CC		=	gcc
CCFLAGS	=	-Wall -Wextra -Werror -c
SRC		=	ft_atoi.c main.c

all: $(NAME)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CCFLAGS) $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	@/bin/rm -f *.o rm *.a
	
fclean:
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
