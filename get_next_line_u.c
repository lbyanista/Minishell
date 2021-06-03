/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:55:18 by mlabrayj          #+#    #+#             */
/*   Updated: 2021/06/03 17:55:38 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

// char		*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*dest;
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	if (!s1)
// 		return (NULL);
// 	if (!(dest = (char *)malloc(sizeof(char) *
// 					(ft_strlen(s1) + ft_strlen(s2) + 1))))
// 		return (NULL);
// 	while (i < ft_strlen(s1))
// 	{
// 		dest[i] = ((char *)s1)[i];
// 		i++;
// 	}
// 	while (j < ft_strlen(s2))
// 	{
// 		dest[i + j] = ((char *)s2)[j];
// 		j++;
// 	}
// 	dest[i + j] = '\0';
// 	return (dest);
// }

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*substr;

	if (!s)
		return (NULL);
	if (!(substr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	index = 0;
	if (!(start > ft_strlen(s)))
	{
		while (index < len && s[start + index])
		{
			substr[index] = s[start + index];
			index++;
		}
	}
	substr[index] = '\0';
	return (substr);
}

char		*ft_strdup(const char *s1)
{
	size_t	s1_len;
	char	*ptr;
	size_t	index;
	char	*str;

	str = (char *)s1;
	index = 0;
	s1_len = ft_strlen((char *)s1);
	if (!(ptr = (char *)malloc(sizeof(char) * s1_len + 1)))
		return (0);
	while (index < s1_len)
	{
		ptr[index] = str[index];
		index++;
	}
	ptr[index] = '\0';
	return (ptr);
}