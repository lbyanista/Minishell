/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:06:00 by mlabrayj          #+#    #+#             */
/*   Updated: 2021/05/30 18:20:57 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define clear() printf("\033[H\033[J")

char	**ft_split(char const *s, char c);
char    *ft_strjoin(char const *s1, char const *s2);
int     ft_strlen(const char *str);