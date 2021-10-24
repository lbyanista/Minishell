/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:16:11 by mlabrayj          #+#    #+#             */
/*   Updated: 2021/10/24 14:22:13 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	is_directory(char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd >= 3)
	{
		close (fd);
		errno = EISDIR;
		return (1);
	}
	return (0);
}

void	close_fds(t_data *data)
{
	close(data->end[0]);
	close(data->end[1]);
	close(data->fd[0]);
	close(data->fd[1]);
	close(data->fd[2]);
	close(data->fd[3]);
}

void	close_fds_and_wait(t_data *data)
{
	int		stat;

	close_fds(data);
	while (data->lst_child_id)
	{
		data->process = data->lst_child_id->content;
		waitpid(data->process->id, &stat, 0);
		data->lst_child_id = data->lst_child_id->next;
	}
	if (WIFEXITED(stat))
		data->exit_status = WEXITSTATUS(stat);
}

static void	error_prompt(t_data *data, char *arg)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(data->prototype[0], STDERR_FILENO);
	ft_putstr_fd(": `", STDERR_FILENO);
	if (arg)
	{
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putstr_fd("': ", STDERR_FILENO);
	}
}

int	error_msg(t_data *data, int errno_code, char *file)
{
	error_prompt(data, file);
	if (errno_code == M_NOCMD || errno_code == M_NOEXENT)
	{
		if (errno_code == M_NOCMD)
			ft_putstr_fd("command not found\n", STDERR_FILENO);
		else
			ft_putstr_fd("No such file or directory\n", STDERR_FILENO);
		return (127);
	}
	else if (errno_code == M_ARGERR || errno_code == M_NOVALID)
	{
		if (errno_code == M_NOVALID)
			ft_putstr_fd("not a valid identifier\n", STDERR_FILENO);
		else
			perror(NULL);
	}
	else if (errno_code == M_BADACCES)
	{
		perror(NULL);
		return (126);
	}
	else if (errno_code == M_STXERR)
	{
		ft_putstr_fd("syntax error!\n", STDERR_FILENO);
		return (258);
	}
	return (1);
}
