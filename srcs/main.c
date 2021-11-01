/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 08:15:00 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/10/29 13:04:06 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	global_init(t_data *data, int argc, char **argv, char *const *envp)
{
	data->garbage = NULL;
	data->exported = NULL;
	data->exit_status = 0;
	data->argc = argc;
	data->argv = argv;
	data->envp = envp;
	build_env_vars(data, envp);
}

static void	_init(t_data *data)
{
	data->piped_cmd = NULL;
	data->word = NULL;
	data->lst_child_id = NULL;
	data->quoting_state = UNQUOTED;
	data->passive = FALSE;
	data->command = NULL;
	data->file_data = NULL;
	data->end[1] = ERROR;
	data->end[0] = ERROR;
	data->fd[0] = ERROR;
	data->fd[1] = ERROR;
	data->fd[2] = ERROR;
	data->fd[3] = ERROR;
}

void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		rl_on_new_line();
		rl_redisplay();
		rl_replace_line("", 0);
		write(1, "  \b\b\n", 5);
		rl_on_new_line();
		rl_redisplay();
	}
}

int	main(int argc, char **argv, char *const envp[])
{
	t_data	data;

	global_init(&data, argc, argv, envp);
	signal(SIGINT, sig_handler);
	while (1)
	{
		data.input = readline(PROMPT);
		_init(&data);
		if (!data.input || !*data.input || parser(&data) == ERROR
			|| execute(&data) == ERROR)
			;
		else
			data.exit_status = 0;
		if (data.input && *data.input)
		{
			add_history(data.input);
			free(data.input);
		}
		else if (!data.input)
			break ;
	}
	return (0);
}
