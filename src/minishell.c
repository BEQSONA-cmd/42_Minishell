/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:47:29 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/06/02 00:06:06 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

void	init_builtin_arr(t_mshell *mshell)
{
	int	n_cmds;

	n_cmds = 6;
	mshell->builtin = ft_malloc(sizeof(t_builtin) * (n_cmds + 1));
	mshell->builtin[0].name = "pwd";
	mshell->builtin[0].fn_ptr = ft_pwd;
	mshell->builtin[1].name = "cd";
	mshell->builtin[1].fn_ptr = ft_cd;
	mshell->builtin[2].name = "echo";
	mshell->builtin[2].fn_ptr = ft_echo;
	mshell->builtin[3].name = "unset";
	mshell->builtin[3].fn_ptr = ft_unset;
	mshell->builtin[4].name = "export";
	mshell->builtin[4].fn_ptr = ft_export;
	mshell->builtin[5].name = "env";
	mshell->builtin[5].fn_ptr = ft_env;
	mshell->builtin[6].name = NULL;
	mshell->builtin[6].fn_ptr = NULL;
}

void	init_mshell(t_mshell *mshell, char **env)
{
	mshell->env = NULL;
	mshell->export = NULL;
	mshell->exit_status = 0;
	mshell->builtin = NULL;
	mshell->tokarr = NULL;
	mshell->cmdarr = NULL;
	mshell->tokarr_l = 0;
	mshell->cmdarr_l = 0;
	mshell->cmd_num = 0;
	init_env(mshell, env);
	init_builtin_arr(mshell);
}

static void	minishell_loop(t_mshell *mshell)
{
	char	*input;
	char	*path;

	ignore_signals();
	while (1)
	{
		g_signal = 0;
		path = get_currect_path(mshell);
		input = readline(path);
		if (!input || (ft_strcmp(input, "exit") == 0))
		{
			printf("exit\n");
			ft_free(input);
			break ;
		}
		if (!*input)
		{
			ft_free(input);
			continue ;
		}
		add_history(input);
		if (parse_input(input, mshell))
			execute(mshell);
		clean_command_data(mshell);
		ft_free(input);
	}
	ft_free(path);
}

int	main(int ac, char **av, char **envp)
{
	t_mshell	mshell;

	ft_alloc_init();
	(void)av;
	(void)ac;
	if (ac != 1)
		exit(write(1, RED "No arguments accepted!\n" RE, 32));
	else
	{
		init_mshell(&mshell, get_envp(envp));
		minishell_loop(&mshell);
	}
	ft_destructor();
	return (0);
}
