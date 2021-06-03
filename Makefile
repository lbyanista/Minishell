# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 11:13:16 by mlabrayj          #+#    #+#              #
#    Updated: 2021/06/03 17:35:58 by mlabrayj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ./a.out

SRC		=	main.c 			\
			binartcmd.c 	\
			ft_strlen.c 	\
			ft_strjoin.c 	\
			ft_split.c 		\
			echo.c 			\
			ft_putchar_fd.c \
			ft_putstr_fd.c	\
			ft_strequal.c	\
			ft_strcmp.c		\

FLAGS	= #-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
		@gcc $(SRC) $(FLAGS) -o $(NAME)

clean:
	@rm -rf a.out*

fclean:	clean

re:	fclean all
