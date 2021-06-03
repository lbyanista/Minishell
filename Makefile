# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 11:13:16 by mlabrayj          #+#    #+#              #
#    Updated: 2021/06/03 13:25:39 by mlabrayj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ./a.out

SRC		=	builtins.c \
			ft_strlen.c \
			ft_strjoin.c \
			ft_split.c \

FLAGS	= #-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
		@gcc $(SRC) -g $(FLAGS) -o $(NAME)

clean:
	@rm -rf a.out*

fclean:	clean

re:	fclean all
