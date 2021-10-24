# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/13 08:14:39 by ael-mezz          #+#    #+#              #
#    Updated: 2021/10/24 14:30:29 by mlabrayj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c								\
		utils/lst_utils.c					\
		utils/lst_utils_1.c					\
		utils/utils.c						\
		utils/utils_1.c						\
		utils/utils_2.c						\
		utils/parsing_utils.c				\
		utils/execution_utils.c				\
		utils/execution_utils_1.c			\
		parsing/parsing.c					\
		parsing/expansions.c				\
		parsing/expand_env_vars.c			\
		parsing/heredoc_parsing.c			\
		parsing/redirections.c				\
		execution/execution.c				\
		execution/execution_1.c				\
		execution/streams.c					\
		execution/scan_command.c			\
		execution/find_executable.c			\
		execution/builtins/builtins.c		\
		execution/builtins/echo.c			\
		execution/builtins/env.c			\
		execution/builtins/export.c			\
		execution/builtins/export_1.c		\
		execution/builtins/export_2.c		\
		execution/builtins/cd.c				\
		execution/builtins/unset.c

LIBFT =	libft/libft.a

LDFLAGS= -L/goinfre/mlabrayj/.brew/opt/readline/lib
CFLAGS= -I/goinfre/mlabrayj/.brew/opt/readline/include

FLAGS = -g -lreadline -ledit $(LDFLAGS) $(CFLAGS) -Wall -Werror -Wextra #-fsanitize=address

SRCS_PATH =	./srcs

CC = gcc

RM = rm -rf

OBJ = $(SRCS:.c=.o)

OBJ_DIR = mv *.o srcs

HEADER = headers/minishell.h

SRCS := $(addprefix $(SRCS_PATH)/, $(SRCS))

all: $(SRCS) $(HEADER)
	@make -C libft && make bonus -C libft
	@$(CC) $(SRCS) $(LIBFT) $(FLAGS) -o minishell
	@./minishell

clean:
	@echo "cleaning..."
	@make clean -C libft

fclean:	clean
	@$(RM) minishell minishell.dSYM
	@make fclean -C libft

test:
	@$(CC) srcs/$(FILE).c $(LIBFT) $(FLAGS) -o $(FILE)
	@echo "...test...\n\n====================="
	@./$(FILE)

re: fclean all
