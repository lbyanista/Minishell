/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 13:29:24 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/10/24 14:29:49 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int	export(t_data *data)
{
	int		i;

	i = 0;
	if (!data->prototype[1] || !data->prototype[1][0])
		export_print(data);
	else if (*(data->prototype)[1] == '-')
		return (error_msg(data, M_STXERR, NULL));
	while (data->prototype[++i] && data->prototype[i][0])
	{
		if (check_export_syntax(data, i) == ERROR)
			return (error_msg(data, M_NOVALID, data->prototype[i]));
		if (!scan_env_vars(data))
			insert_var(data, NULL);
	}
	return (EXIT_SUCCESS);
}
