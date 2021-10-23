/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:32:03 by mlabrayj          #+#    #+#             */
/*   Updated: 2021/10/23 17:44:16 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

char	**env_array(t_data *data)
{
	char	**envp;
	int		i;

	i = 0;
	envp = malloc(sizeof(*envp) * (ft_lstsize(data->exported) + 1));
	while (data->exported)
	{
		data->info = data->exported->content;
		envp[i++] = ft_strjoin_and_free_s1
			(ft_strjoin(data->info->var, "="), data->info->value);
		data->exported = data->exported->next;
	}
	envp[i] = NULL;
	return (envp);
}

void	daughter_process(t_data *data, int read_end)
{
	if (stream_source(data, read_end, FALSE) || builtin(data))
		exit(EXIT_FAILURE);
	if (data->is_builtin == TRUE)
		exit(EXIT_SUCCESS);
	if (!file_search_using_path_var(data))
		data->executable = data->prototype[0];
	if (execve(data->executable, data->prototype,
			(char *const *)env_array(data)))
		execve_errs(data);
}

int	pipe_and_fork(t_data *data)
{
	if (data->piped_cmd->next)
	{
		if (pipe(data->end) == ERROR)
			return (EXIT_FAILURE);
	}
	data->process = malloc(sizeof(t_process));
	data->process->id = fork();
	if (data->process->id == ERROR)
		return (EXIT_FAILURE);
	if (data->process->id)
		ft_lstadd_back(&data->lst_child_id, ft_lstnew(data->process));
	return (EXIT_SUCCESS);
}

int	simple_command(t_data *data)
{
	int	ret;

	ret = FALSE;
	if (!data->piped_cmd->next)
	{
		scan_command(data);
		if (stream_source(data, 0, TRUE) || builtin(data))
			ret = EXIT_FAILURE;
		else if (data->is_builtin == TRUE)
			ret = TRUE;
		if (data->fd[0] != ERROR)
		{
			if (dup2(data->fd[2], STDIN_FILENO) == ERROR)
				return (error_msg(data, M_ARGERR, NULL));
		}
		if (data->fd[1] != ERROR)
		{
			if (dup2(data->fd[3], STDOUT_FILENO) == ERROR)
				return (error_msg(data, M_ARGERR, NULL));
		}
		close_fds(data);
		free_2d(data->prototype);
	}
	return (ret);
}

void	piped_commands(t_data *data)
{
	int	read_end;

	read_end = -1;
	while (data->piped_cmd)
	{
		scan_command(data);
		if (pipe_and_fork(data))
			error_msg(data, M_ARGERR, NULL);
		if (data->process->id == 0)
			daughter_process(data, read_end);
		read_end = data->end[0];
		close(data->end[1]);
		data->piped_cmd = data->piped_cmd->next;
	}
}
