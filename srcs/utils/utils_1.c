/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:54:43 by mlabrayj          #+#    #+#             */
/*   Updated: 2021/10/27 15:41:40 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	is_backslashed(int i, char *str)
{
	int	special;
	int	d;

	special = FALSE;
	if (i == 0)
		return (0);
	d = i - 1;
	while (d >= 0 && str[d] == '\\')
		d--;
	while (++d <= i - 1)
	{
		if (str[d] == '\\' && special == FALSE)
			special = TRUE;
		else if (str[d] == '\\' && special == TRUE)
			special = FALSE;
	}
	return (special);
}

static int	separator_search(const char *s, char *separator, int c)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (separator[++i])
	{
		if ((s[c] == separator[i] && is_backslashed(c, (char *)s)) \
			|| s[c] != separator[i])
			j++;
	}
	if (j == (int)ft_strlen(separator))
		return (0);
	return (1);
}

size_t	ft_countwords(char const *s, char *separator)
{
	int		start;
	size_t	count;

	count = 0;
	start = 0;
	while (s[start])
	{
		while (separator_search(s, separator, start) && s[start])
			start++;
		if (s[start])
			count++;
		while (!separator_search(s, separator, start) && s[start])
			start++;
	}
	return (count);
}

static char	**ft_koalloc(char **ptr, size_t i)
{
	i += 1;
	while (ptr[--i] != NULL)
		free(ptr[i]);
	free(ptr);
	return (NULL);
}

char	**spliter(char const *s, char **ptr, char *separator, size_t cw)
{
	size_t	i;
	int		start;
	int		len;
	int		j;

	i = -1;
	start = 0;
	len = 0;
	while (s[start] && ++i < cw)
	{
		while (separator_search(s, separator, start) && s[start])
			start++;
		j = -1;
		while (!separator_search(s, separator, start) && s[start++])
			len++;
		start -= len;
		ptr[i] = ft_calloc(len + 1, sizeof(char));
		if (!ptr[i])
			return (ft_koalloc(ptr, i));
		ft_memcpy(ptr[i], s + start, len);
		start += len;
		len = 0;
	}
	return (ptr);
}
