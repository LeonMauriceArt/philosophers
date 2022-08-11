# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leonard <leonard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 17:51:28 by lmaurin-          #+#    #+#              #
#    Updated: 2022/08/11 19:46:47 by leonard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philosophers
HEADER	=	philosophers.h
OBJ		=	$(SRC:.c=.o)
CC		=	gcc -pthread -fsanitize=address -g3
CCFLAGS	=	-Wall -Wextra -Werror -c
SRC		=	./main.c ./srcs/parsing.c ./utils/utils.c ./utils/ft_atoi.c \
			./srcs/init_philos.c ./srcs/philo.c
			

all: $(NAME)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CCFLAGS) $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	@/bin/rm -f *.o rm *.a
	@/bin/rm -f ./srcs/*.o rm ./srcs/*.a
	@/bin/rm -f ./utils/*.o rm ./utils/*.a

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
