/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 13:31:19 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/11/17 21:59:26 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	env(t_data data)
{
	while (data.exported)
	{
		data.info = data.exported->content;
		if (data.info->value && *(data.info->value))
			printf("%s=%s\n", data.info->var, data.info->value);
		data.exported = data.exported->next;
	}
	return (EXIT_SUCCESS);
}
