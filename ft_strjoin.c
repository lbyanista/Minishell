/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:05:11 by mlabrayj          #+#    #+#             */
/*   Updated: 2021/05/30 18:06:36 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	int		i;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	i = 0;
	p = malloc(sizeof(char *) * (lens1 + ft_strlen(s2)));
	if (p == 0)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		p[i + lens1] = s2[i];
		i++;
	}
	p[i + lens1] = '\0';
	return (p);
}