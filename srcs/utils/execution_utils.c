/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:22:16 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/10/24 14:16:26 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

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
