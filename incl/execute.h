/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:46:02 by btvildia          #+#    #+#             */
/*   Updated: 2024/05/17 13:39:26 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "../ft_destructor/ft_alloc.h"
# include "../libft/libft.h"
# include "minishell.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_mshell	t_mshell;

void					ft_pwd(void);
void					ft_cd(char *cmd);
void					ft_env(char **envp);
void					ft_echo(t_mshell *mshell);
void					ft_unset(t_mshell *mshell);
void					ft_export(t_mshell *mshell);
void					ft_execve(char *cmd, char **envp);
void					ft_exec_just_cmd(t_mshell *mshell);
char					*ft_remove_substr(char *str, char *sub);
void					ft_execute(t_mshell *mshell, char **envp);

#endif
