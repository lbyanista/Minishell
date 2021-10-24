/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:13:12 by mlabrayj          #+#    #+#             */
/*   Updated: 2021/10/24 14:13:26 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	free_list(t_list **lst)
{
	t_list	*tmp;

	if (*lst == NULL)
		return ;
	tmp = (*lst)->next;
	if ((*lst)->content)
		free((*lst)->content);
	free(*lst);
	*lst = NULL;
	free_list(&tmp);
}

t_list	*ft_lstprevious(t_list *lst)
{
	if (ft_lstsize(lst) == 1)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lst_head(t_list *lst)
{
	while (lst->previous)
		lst = lst->previous;
	return (lst);
}

t_list	*ft_dlstnew(void *content)
{
	t_list	*ptr;

	ptr = (t_list *)malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->content = (void *)content;
	ptr->next = NULL;
	ptr->previous = NULL;
	return (ptr);
}

void	ft_dlstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (alst == NULL)
		return ;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	tmp = ft_lstlast(*alst);
	ft_lstlast(*alst)->next = new;
	new->previous = tmp;
}
