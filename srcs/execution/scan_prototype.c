/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_prototype.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 14:25:44 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/11/15 16:24:07 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static void	command_name_to_lower_case(t_data *data)
{
	char	*tmp;
	char	*command_name;
	int		j;

	j = -1;
	command_name = data->command->prototype->content;
	tmp = ft_strdup(command_name);
	while (command_name[++j])
		command_name[j] = ft_tolower(command_name[j]);
	if (!ft_strcmp(command_name, "export") || !ft_strcmp(command_name, "unset")
		|| !ft_strcmp(command_name, "exit") || !ft_strcmp(command_name, "cd"))
	{
		free(data->command->prototype->content);
		data->command->prototype->content = tmp;
	}
	else
		free(tmp);
}

static char	**lst_to_table(t_list *lst)
{
	char	**table;
	int		i;

	table = malloc(sizeof(*table) * (ft_lstsize(lst) + 1));
	i = 0;
	while (lst)
	{
		table[i++] = ft_strdup(lst->content);
		lst = lst->next;
	}
	table[i] = NULL;
	return (table);
}

static void	expand_prototype(t_data *data)
{
	if (!data->command->prototype)
		return ;
	data->command->prototype->content
		= expand_env_vars(data, data->command->prototype->content);
	data->command->prototype->content
		= expand_token(data, data->command->prototype->content);
	data->command->prototype = data->command->prototype->next;
	expand_prototype(data);
}

void	scan_prototype(t_data *data)
{
	t_list	*tmp;

	data->command = data->piped_cmd->content;
	tmp = data->command->prototype;
	if (!tmp)
		return ;
	command_name_to_lower_case(data);
	expand_prototype(data);
	data->command->prototype = tmp;
	data->prototype = lst_to_table(data->command->prototype);
}
