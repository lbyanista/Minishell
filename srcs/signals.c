/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:41:24 by mlabrayj          #+#    #+#             */
/*   Updated: 2021/11/01 19:41:43 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		rl_on_new_line();
		rl_redisplay();
		rl_replace_line("", 0);
		write(1, "  \b\b\n", 5);
		rl_on_new_line();
		rl_redisplay();
	}
}
