/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 13:31:19 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/11/09 15:11:32 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	env(t_data *data)
{
	t_list	*tmp;

	if (check_prototype(data->prototype))
		return (error_msg(data, M_STXERR, NULL));
	tmp = data->exported;
	while (data->exported)
	{
		data->info = data->exported->content;
		if (data->info->value && *(data->info->value))
			printf("%s=%s\n", data->info->var, data->info->value);
		data->exported = data->exported->next;
	}
	data->exported = tmp;
	return (EXIT_SUCCESS);
}
