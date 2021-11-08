/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:31:46 by mlabrayj          #+#    #+#             */
/*   Updated: 2021/11/07 13:45:56 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

unsigned long long int	ft_atoi2(const char *str)
{
	unsigned long long int	res;
	long					sign;
	unsigned int			i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i++] - '0';
		if (res > 9223372036854775807 && sign == -1)
			return (0);
		if (res > 9223372036854775807 && sign == 1)
			return (-1);
	}
	return ((int)(res * sign));
}

static	int	is_valid_numeric(char *str)
{
	unsigned long long int	res;
	long					sign;
	unsigned int			i;

	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		res = res * 10 + str[i++] - '0';
		if ((res > 9223372036854775807 && sign == -1)
			|| (res > 9223372036854775807 && sign == 1))
			return (0);
	}
	return (1);
}

void	ft_exit2(char *cmd)
{
	write(1, "exit\nminishell: exit: ", 23);
	write(1, cmd, ft_strlen(cmd));
	write(1, ": numeric argument required\n", 29);
	g_main.exit_status = 255;
}

void	ft_exit(t_data *data)
{
	if (data && data->args_size >= 2)
	{
		if (!is_valid_numeric(data->args[1]))
		{
			ft_exit2(data->args[1]);
			exit(g_main.exit_status);
		}
		else if (data->args_size > 2)
		{
			write(1, "exit\nminishell: exit: too many arguments\n", 42);
			g_main.exit_status = 1;
		}
		else
		{
			write(1, "exit\n", 6);
			g_main.exit_status = ft_atoi2(data->args[1]) % 256;
			exit(g_main.exit_status);
		}
	}
	else
	{
		write(1, "exit\n", 6);
		g_main.exit_status = 0;
		exit(g_main.exit_status);
	}
}
