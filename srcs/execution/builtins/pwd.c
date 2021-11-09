/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:23:09 by mlabrayj          #+#    #+#             */
/*   Updated: 2021/11/09 14:48:50 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

int pwd(t_data  *data)
{
	char	*path;
	char	*tmp;

	ptr = NULL;
	path = malloc(100);
	getcwd(path, 1024);
	tmp = path;
	if (g_main.point)
	{
		path = ft_strjoin(path, g_main.point);
		free(tmp);
	}
	printf("%s\n", path);
	free(path);
    return (0);
}
