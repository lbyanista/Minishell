/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:16:59 by mlabrayj          #+#    #+#             */
/*   Updated: 2021/10/23 17:19:42 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	cd(t_data *data)
{
	if (data->prototype[1])
	{
		if (chdir(data->prototype[1]))
			return (error_msg(data, M_ARGERR, data->prototype[1]));
	}
	else
		chdir(getenv("HOME"));
	return (EXIT_SUCCESS);
}
