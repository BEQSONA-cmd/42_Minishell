/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:46:36 by btvildia          #+#    #+#             */
/*   Updated: 2024/05/12 22:52:18 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/execute.h"

void	ft_execute(t_mshell *mshell)
{
	if (ft_strncmp(mshell->input, "cd", 2) == 0)
		ft_cd(mshell->input);
	else if (ft_strncmp(mshell->input, "echo", 4) == 0)
		ft_echo(mshell->input);
	else if (ft_strncmp(mshell->input, "pwd", 3) == 0)
		ft_pwd();
	else if (ft_strncmp(mshell->input, "env", 3) == 0)
		ft_env(mshell);
	else if (ft_strncmp(mshell->input, "export", 6) == 0)
		ft_export(mshell);
	else if (ft_strncmp(mshell->input, "unset", 5) == 0)
		ft_unset(mshell);
	else
		ft_exec_just_cmd(mshell);
}
