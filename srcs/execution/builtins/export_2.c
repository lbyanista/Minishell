/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:30:00 by mlabrayj          #+#    #+#             */
/*   Updated: 2021/10/24 14:30:56 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../headers/minishell.h"

static void	sort_var(t_data *data)
{
	t_list			*last;
	t_info			*info_1;

	last = ft_lstlast(data->exported);
	data->info = last->content;
	while (last->previous)
	{
		info_1 = last->previous->content;
		if (ft_strcmp(data->info->var, info_1->var) > 0)
			break ;
		if (last->previous->previous)
			last->previous->previous->next = last;
		last->previous->next = last->next;
		last->next = last->previous;
		last->previous = last->next->previous;
		if (last->next->next)
			last->next->next->previous = last->next;
		last->next->previous = last;
	}
	if (!last->previous)
		data->exported = last;
}

void	insert_var(t_data *data, char *input)
{
	int				i;

	if (input)
	{
		i = find_char(input, '=');
		data->info = malloc(sizeof(t_info));
		data->info->var = ft_substr(input, 0, i);
		data->info->value = ft_substr(input, i + 1, ft_strlen(input) - i);
	}
	ft_dlstadd_back(&data->exported, ft_dlstnew(data->info));
	sort_var(data);
}

static int	already_exported(t_data *data, int i, t_info *info_1)
{
	if (!ft_strcmp(info_1->var, data->info->var))
	{
		if (data->info->value)
		{
			if (i == ERROR)
			{
				free(info_1->value);
				info_1->value = NULL;
			}
			info_1->value
				= ft_strjoin_and_free_s1(info_1->value, data->info->value);
		}
		return (1);
	}
	return (0);
}

int	scan_env_vars(t_data *data)
{
	t_info	*info_1;
	t_list	*tmp;
	int		i;

	tmp = data->exported;
	i = find_char(data->info->var, '+');
	if (i != ERROR)
		data->info->var[ft_strlen(data->info->var) - 1] = '\0';
	while (data->exported)
	{
		info_1 = data->exported->content;
		if (already_exported(data, i, info_1))
		{
			data->exported = tmp;
			return (1);
		}
		data->exported = data->exported->next;
	}
	data->exported = tmp;
	return (0);
}

void	build_env_vars(t_data *data, char *const	*envp)
{
	int	i;

	i = -1;
	data->exported = NULL;
	while (envp[++i])
		insert_var(data, (char *)envp[i]);
	increase_shelllvl(data);
}
