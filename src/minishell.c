/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:47:29 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/05/17 13:46:07 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

char	*get_currect_path(char **envp)
{
	static char	*path;
	char		*tmp;
	char		*tmp2;
	char		*tmp3;
	int			i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "USER=", 5) != 0)
		i++;
	tmp3 = getcwd(NULL, 0);
	if (!tmp3)
	{
		printf("\nyou can use only 'cd ..' or 'exit'\n\n");
		return (path);
	}
	tmp = ft_strjoin("/home/", envp[i] + 5);
	tmp2 = ft_strjoin(ft_remove_substr(tmp3, tmp), "$ ");
	ft_free(tmp3);
	path = ft_strjoin(YELLOW "Minishell~" RE, tmp2);
	ft_free(tmp2);
	return (path);
}

static void	minishell_loop(t_mshell *mshell, char **envp)
{
	char	*input;
	char	*path;

	while (1)
	{
		path = get_currect_path(mshell->envp);
		ignore_signals();
		input = readline(path);
		add_history(input);
		if (!input || ft_strncmp(input, "exit", 4) == 0)
		{
			printf("exit\n");
			ft_free(input);
			break ;
		}
		parse_input(input, mshell);
		ft_execute(mshell, envp);
		ft_free(input);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_mshell	mshell;
	int			i;

	ft_alloc_init();
	(void)av;
	(void)ac;
	i = 0;
	if (ac != 1)
		exit(write(1, RED "No arguments accepted!\n" RE, 32));
	else
	{
		write(1, GREEN "OK\n" RE, 14);
		init_mshell(&mshell, envp);
		minishell_loop(&mshell, envp);
	}
	ft_destructor();
	return (0);
}
