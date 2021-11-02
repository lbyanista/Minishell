/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-mezz <ael-mezz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 18:16:59 by mlabrayj          #+#    #+#             */
/*   Updated: 2021/10/30 16:58:52 by ael-mezz         ###   ########.fr       */
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
