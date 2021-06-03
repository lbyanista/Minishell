/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlabrayj <mlabrayj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:44:14 by mlabrayj          #+#    #+#             */
/*   Updated: 2021/06/03 18:21:08 by mlabrayj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int main(int ac, char **av)
{
	char *str;

	// echo(av);
	str = malloc(sizeof(str) * 2048);
	while (1)
	{
		prompt();
		// 
		read(0, str, 2048);
		write(1, str, strlen(str));
	}
	
	return (0);
}

// int	main(int ac , char **av)
// {
// 	clear();
// 	while (1)
// 	{
	
	
// 	char	*username;
// 	char	str[256];
// 	// char 	*strpwdmin = "pwd";
// 	// char	*strpwdmaj = "PWD";
// 	pid_t h;
// 	char	*args[] = {"/bin/ls"};

	
// 	username = getenv("HOME");
// 	// bash_loop();
// 	// return (0);


// 	printf("%s$", username);
// 	scanf("%s", str);
// 	fflush(stdout);
// 	// printf("\n%d\n", ft_strlen(str));
// 	// printf("%s\n", str);
// 	h = fork();
// 	if(h == 0){
// 	 	execve("/bin/ls", args, NULL);
// 		// echo(&av[1]);
// 	 	exit(1);
// 	}
// 	else if (h != 0)
// 	{
// 		// printf("\n***%d***/n", h);
// 		wait(NULL);
// 	}
	
// 	// if (str[1] == 'l')
// 	// {
// 	// 	printf("hadi ls liste");
// 	// }
// 	// int a = strcmp(str, strpwdmaj);
// 	// int b = strcmp(str, strpwdmin);
// 	// printf("hadi a =%d \n hadi b=%d", a, b);
// 	// scanf("%d", &a);
// 	// if (a == 0 || b == 0)
// 	// {
// 	// 	printf("%s\n", getenv("LS"));
// 	// 	// system("pwd");
// 	// 	// sleep(1);
// 	// 	// clear();
// 	// 	// break ;
// 	// }
// 	}
// 	sleep(1);
// 	clear();
// 	return(0);
// }