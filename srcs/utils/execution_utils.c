/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:22:16 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/10/25 11:44:12 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	error_msg_norm(int errno_code)
{
	if (errno_code == M_BADACCES)
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
	error_msg_norm(errno_code);
	return (1);
}

void	execve_errs(t_data *data)
{
	if ((errno == ENOENT || errno == EFAULT)
		&& ((data->prototype[0][0] == '~' || data->prototype[0][0] == '.'
		|| data->prototype[0][0] == '/') || data->err_path_env))
		exit(error_msg(data, M_NOEXENT, NULL));
	else if (errno == ENOENT || errno == EFAULT)
		exit(error_msg(data, M_NOCMD, NULL));
	else if (is_directory(data->executable) || errno == EACCES)
		exit(error_msg(data, M_BADACCES, NULL));
}
