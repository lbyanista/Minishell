/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:06:00 by mlabrayj          #+#    #+#             */
/*   Updated: 2021/06/03 13:16:57 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define clear() printf("\033[H\033[J")

typedef struct s_var
{
    int     _error;
    int     _status;
}               t_var;


char	**ft_split(char const *s, char c);
char    *ft_strjoin(char const *s1, char const *s2);
int     ft_strlen(const char *str);
int     ft_strcmp(const char *s1, const char *s2);
int		ft_strequal(const char *s1, const char *s2);