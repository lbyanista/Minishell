/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 08:37:34 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/10/24 14:13:10 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
}

void	print_content_list(t_list *lst)
{
	t_list	*sub_list;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (lst)
	{
		sub_list = (t_list *)(lst->content);
		while (sub_list)
		{
			printf("-- %i -- %i --: |%s|\n", j, i++, (char *)sub_list->content);
			sub_list = sub_list->next;
		}
		j++;
		i = 0;
		lst = lst->next;
	}
}

void	ft_dlst_delete_node(t_list *lst)
{
	if (lst->previous)
		lst->previous->next = lst->next;
	if (lst->next)
		lst->next->previous = lst->previous;
}

t_list	*lst_elem(t_list *lst, int index)
{
	index++;
	while (lst && --index)
		lst = lst->next;
	return (lst);
}

// void	print_lines(t_data data)
// {
// 	t_list *cmd;
// 	t_list *pipes;
// 	t_list *tokens;

// 	while (data.line)
// 	{
// 		cmd = (t_list *)(data.line->content);
// 		while (cmd)
// 		{
// 			pipes = (t_list *)(cmd->content);
// 			print_content_list(pipes);
// 			puts("=\n=\n=\n=\n=");
// 			cmd = cmd->next;
// 		}
// 		data.line = data.line->next;
// 	}
// }
