/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:23:07 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/10/23 17:20:21 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	builtin(t_data *data)
{
	data->is_builtin = TRUE;
	if (!ft_strcmp(data->prototype[0], "echo"))
		return (echo(data));
	else if (!ft_strcmp(data->prototype[0], "export"))
		return (export(data));
	else if (!ft_strcmp(data->prototype[0], "env"))
		return (env(data));
	else if (!ft_strcmp(data->prototype[0], "cd"))
		return (cd(data));
	else if (!ft_strcmp(data->prototype[0], "unset"))
		return (unset(data));
	data->is_builtin = FALSE;
	return (EXIT_SUCCESS);
}
