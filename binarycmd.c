/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binarycmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:06:53 by mlabrayj          #+#    #+#             */
/*   Updated: 2021/06/03 17:35:37 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *jointhreestr(char *path, char *bslash, char *cmd)
{
	char *joinpathslash = ft_strjoin(path , bslash);
	char *tmp = joinpathslash;
	joinpathslash = ft_strjoin(joinpathslash, cmd);
	free(tmp);
	return (joinpathslash);
}

int main(int ac, char **av)
{
    	char *path;
    	char **r;
    	int i;
		pid_t h;
		char **k;

    	i = 0;
   	 	path = getenv("PATH");
    	r = ft_split(path, ':');
    	while (r[i])
    	   ft_strjoin(r[i++], "/");

		h = fork();
		int j = 0;
		k = (char**)malloc(sizeof(k) * i);
		while (j < i)
		{
			// k[j] = ft_strjoin(r[j], av[1]);
			k[j] = jointhreestr(r[j], "/", av[1]);
			if (h == 0)
			{
				execve(k[j], &k[j], NULL);
			}
			else if (h != 0)
			{
				wait(NULL);
			}
			free(k[j]);
			j++;
		}
    return 0;
}