/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 10:06:45 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/10/23 17:39:59 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	execute(t_data *data)
{
	int	ret;

	ret = simple_command(data);
	if (ret)
	{
		if (ret == EXIT_FAILURE)
			data->exit_status = ret;
		else
			ret = EXIT_SUCCESS;
		return (ret);
	}
	piped_commands(data);
	close_fds_and_wait(data);
	return (data->exit_status);
}
