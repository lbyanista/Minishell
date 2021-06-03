/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 13:36:00 by mlabrayj          #+#    #+#             */
/*   Updated: 2021/06/03 13:36:18 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		prompt(void)
{
	char	*tmp;
	size_t	len;
	size_t	count_slash;

	if ((tmp = getenv("USER")))
	{
		ft_putstr_fd("\033[32;1m", 1);
		ft_putstr_fd(tmp, 1);
		ft_putstr_fd("@\033[0m:", 1);
		// free(tmp);
	}
	tmp = getcwd(NULL, 0);
	len = ft_strlen(tmp);
	count_slash = 0;
	while (--len && count_slash < 3)
		if (tmp[len] == '/')
			count_slash++;
	ft_putstr_fd("\e[1;34m", 1);
	while (tmp[++len])
		ft_putchar_fd(tmp[len], 1);
	ft_putstr_fd("$\e[0m ", 1);
	free(tmp);
}
