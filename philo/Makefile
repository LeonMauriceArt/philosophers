# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmaurin- <lmaurin-@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 17:51:28 by lmaurin-          #+#    #+#              #
#    Updated: 2022/06/29 16:12:01 by lmaurin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philosophers
HEADER	=	philosophers.h
OBJ		=	$(SRC:.c=.o)
CC		=	gcc
CCFLAGS	=	-Wall -Wextra -Werror -c
SRC		=	./utils/ft_atoi.c ./utils/utils.c ./srcs/parsing.c main.c \
			./srcs/philo_loop.c ./srcs/init_philos.c ./utils/debug.c \
			./srcs/thread_manager.c
			

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
