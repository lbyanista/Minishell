/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:44:54 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/10/23 17:29:07 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

t_BOOL	theres_atoken(char *fragment)
{
	int	i;

	i = -1;
	while (fragment[++i])
	{
		if (fragment[i] != ' ')
			return (TRUE);
	}
	free(fragment);
	return (FALSE);
}

t_BOOL	is_redirection(char *str, int i, int quoting_state)
{
	if ((str[i] == '>' || str[i] == '<') && quoting_state == UNQUOTED)
		return (TRUE);
	return (FALSE);
}

t_BOOL	closed_quotes(char *input, int i)
{
	int	j;

	j = i;
	while (input[++j])
	{
		if (input[j] == input[i])
			return (TRUE);
	}
	return (FALSE);
}

void	define_quoting_state(t_data *data, char *input, int i)
{
	if (data->passive)
	{
		data->quoting_state = UNQUOTED;
		data->passive = FALSE;
	}
	else if (input[i] == data->quoting_state)
		data->passive = TRUE;
	if (data->quoting_state == UNQUOTED && quoted_fragment(input[i])
		&& closed_quotes(input, i))
		data->quoting_state = input[i];
}

char	*lst_to_word(t_list *lst)
{
	int		l;
	char	*str;
	int		i;

	i = 0;
	l = ft_lstsize(lst);
	str = malloc(sizeof(*str) * (l + 1));
	while (lst)
	{
		str[i++] = *(char *)lst->content;
		lst = lst->next;
	}
	str[i] = '\0';
	return (str);
}
