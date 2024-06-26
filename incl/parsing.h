/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:30:36 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/06/03 16:25:30 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_mshell		t_mshell;
typedef struct s_builtin	t_builtin;

typedef enum e_type
{
	T_NDEF,		// *notdefined
	T_WORD,		// word, string, file, cmd ...
	T_PIPE,		//|
	T_HEREDOC,	//<<
	T_RED_INP,	//<
	T_APPEND,	//>>
	T_RED_OUT,	//>
}							t_type;

typedef struct s_token
{
	char					*word;
	t_type					type;
}							t_token;

typedef struct s_cmdarr
{
	char					**args;
	t_token					*inp; // arr[struct{word, type}];
	t_token					*out; // arr[struct{word, type}];
	int						inp_l;
	int						out_l;
}							t_cmdarr;

typedef struct s_count
{
	int						arg;
	int						in;
	int						out;
}							t_count;

typedef struct s_env_lst
{
	char					*val;
	char					*name;
	struct s_env_lst		*next;
}							t_env_lst;

// err check
void						syntax_err(char *c, int type);
int							input_err_check(t_mshell *mshell, char *input);
int							token_order_check(t_mshell *mshell);
// parsing
void						init_env(t_mshell *mshell, char **env);
int							fill_str(char *s, t_env_lst **lst);
int							parse_input(char *input, t_mshell *mshell);
void						dollar_value_subst(char **s, char *q,
								t_mshell *mshell);
void						open_quotes(t_mshell *mshell);
void						fill_cmd(int cmd, int *tok, t_mshell *mshell);
// parsing utils
int							space(char c);
int							quote(char c);
int							spec_symb(char *s);
void						quote_opened_type(char c, char *q);
int							pass_str(char *s);
int							ft_strchr_pos(char *s, int c);
int							env_lst_len(t_env_lst *lst);
t_env_lst					*find_env_node(char *name, t_env_lst *env);
char						*cut_name(char *s);
void						init_dst(char **dst, char *src);
void						init_tokarr(char *s, t_mshell *mshell);
void						init_cmdarr(t_mshell *mshell);
void						init_cmd(int c, int *t, t_mshell *mshell);
void						alloc_cmd(t_count sizes, t_cmdarr *cmd);
t_type						token_typizator(char *s);
void						fill_redir_type(t_token *rdr, t_token *tarr,
								int *t);
void						print_cmds(t_mshell *mshell);
void						print_env(t_env_lst *env);
#endif
