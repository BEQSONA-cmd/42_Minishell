/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sources.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:48:00 by btvildia          #+#    #+#             */
/*   Updated: 2024/05/01 19:06:36 by btvildia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOURCES_H
# define SOURCES_H
# include "minishell.h"

# define RED "\x1b[31m"
# define BLUE "\x1b[34m"
# define RESET "\x1b[0m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strncpy(char *s1, char *s2, int n);
char	**ft_split(char *a, char d);
int		ft_strlen(char *s);
void	ft_strcpy(char *d, char *s);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strchr(char *s, int c);
char	*ft_strstr(char *s1, char *s2);
char	*ft_remove_substr(char *s, char *sub);

#endif