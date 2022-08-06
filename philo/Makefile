# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leonard <leonard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 17:51:28 by lmaurin-          #+#    #+#              #
#    Updated: 2022/08/06 17:17:09 by leonard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philosophers
HEADER	=	philosophers.h
OBJ		=	$(SRC:.c=.o)
CC		=	gcc -pthread
CCFLAGS	=	-Wall -Wextra -Werror -c 
SRC		=	./utils/ft_atoi.c ./utils/utils.c ./parsing/parsing.c main.c \
			./srcs/philo_loop.c ./parsing/init_philos.c \
			./srcs/thread_manager.c ./srcs/logs.c \
			./srcs/actions.c
			

all: $(NAME)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CCFLAGS) $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	@/bin/rm -f *.o rm *.a
	@/bin/rm -f ./srcs/*.o rm ./srcs/*.a
	@/bin/rm -f ./utils/*.o rm ./utils/*.a
	@/bin/rm -f ./parsing/*.o rm ./parsing/*.a

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
