/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:24:31 by mlabrayj          #+#    #+#             */
/*   Updated: 2021/10/24 14:27:48 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

static int	is_plus_sign(t_data *data, char *var, int i)
{
	if (var[i] == '+' && i == (int)ft_strlen(var) - 1 && data->info->value)
		return (1);
	return (0);
}

static int	analyze_var(t_data *data, char *var)
{
	int	i;

	i = 0;
	if (!ft_isalpha(var[0]) && var[i] != '_')
		return (ERROR);
	while (var[++i])
		if (!ft_isalnum(var[i]) && !is_plus_sign(data, var, i) && var[i] != '_')
			return (ERROR);
	return (1);
}

int	check_export_syntax(t_data *data, int j)
{
	int	i;
	int	l;

	data->info = malloc(sizeof(t_info));
	l = ft_strlen(data->prototype[j]);
	i = find_char(data->prototype[j], '=');
	if (i == ERROR)
	{
		i = l;
		data->info->value = NULL;
	}
	else if (i == l - 1)
		data->info->value = ft_strdup("");
	else
		data->info->value
			= ft_substr(data->prototype[j], i + 1, l - i);
	data->info->var = ft_substr(data->prototype[j], 0, i);
	if (analyze_var(data, data->info->var) == ERROR)
		return (ERROR);
	return (1);
}

void	export_print(t_data *data)
{
	t_list	*tmp;

	tmp = data->exported;
	while (tmp)
	{
		data->info = tmp->content;
		if (data->info->value)
			printf("declare -x %s=\"%s\"\n", data->info->var, data->info->value);
		else
			printf("declare -x %s\n", data->info->var);
		tmp = tmp->next;
	}
}

void	increase_shelllvl(t_data *data)
{
	t_list	*tmp;
	int		level;

	tmp = data->exported;
	while (data->exported)
	{
		data->info = data->exported->content;
		if (!ft_strcmp(data->info->var, "SHLVL"))
		{
			if (data->info->value)
			{
				level = ft_atoi(data->info->value) + 1;
				free(data->info->value);
				data->info->value = ft_itoa(level);
			}
		}
		data->exported = data->exported->next;
	}
	data->exported = tmp;
}
