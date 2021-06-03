/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:56:06 by mlabrayj          #+#    #+#             */
/*   Updated: 2021/06/03 17:56:40 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		last_line(char **str, char *buff, char **line)
{
	*line = ft_strdup(*str);
	free(*str);
	*str = NULL;
	free(buff);
	return (0);
}

int		for_norm(char **str, char *temp, char **line, char *buff)
{
	int len;

	len = ft_strchr(*str, '\n') - *str;
	temp = *str;
	*line = ft_substr(*str, 0, len);
	*str = ft_strdup(*str + len + 1);
	free(temp);
	free(buff);
	return (1);
}

int		my_free(char *buff)
{
	free(buff);
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	char		*buff;
	char		*temp;
	static char	*str;
	int			r;

	if (fd < 0 || line == NULL || (read(fd, NULL, 0) < 0))
		return (-1);
	buff = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		str = ft_strdup("");
	while (!ft_strchr(str, '\n'))
	{
		temp = str;
		if ((r = read(fd, buff, BUFFER_SIZE)) < 0)
			return (my_free(buff));
		buff[r] = '\0';
		str = ft_strjoin(str, buff);
		free(temp);
		if (r == 0)
			return (last_line(&str, buff, line));
	}
	if (ft_strchr(str, '\n'))
		return (for_norm(&str, temp, line, buff));
	else
		return (last_line(&str, buff, line));
}
