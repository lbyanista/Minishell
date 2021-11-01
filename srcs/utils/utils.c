/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 09:41:53 by ael-mezz          #+#    #+#             */
/*   Updated: 2021/10/29 12:50:10 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

char	**ft_split_input(char const *s, char *separator)
{
	char		**ptr;
	size_t		cw;

	if (s == NULL)
		return (NULL);
	cw = ft_countwords(s, separator);
	ptr = (char **)malloc(sizeof(char *) * (cw + 1));
	if (!ptr)
		return (NULL);
	ptr[cw] = NULL;
	return (spliter(s, ptr, separator, cw));
}

t_bool	quoted_fragment(char c)
{
	if (c == '\'' || c == '\"')
		return (TRUE);
	return (FALSE);
}

int	find_char(char *str, char c)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == c)
				return (i);
			i++;
		}
	}
	return (-1);
}
