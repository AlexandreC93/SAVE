/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkeraudr <dkeraudr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 21:52:51 by dkeraudr          #+#    #+#             */
/*   Updated: 2023/10/30 21:06:45 by dkeraudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>

# define PROMPT "🐚 - minishell$ "
# define HERE_DOC_PATH "/tmp/.here_doc"
# define ERROR -1
// store status in a global variable 
extern int	g_status;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

struct		s_minishell;
typedef struct s_command
{
	char				**argv;
	t_env				*envars;
	struct s_command	*next;
	struct s_minishell	*mini_struct;
}	t_command;

typedef struct s_minishell
{
	t_env		*envars;
	t_command	*commands;
	char		**lines;
	char		*pipe_in;
	char		*pipe_out;
	char		*here_doc_lim;
	int			append;
	t_list		*pids;
}	t_minishell;

// init.c
t_env			*init_env(char **envp);
t_minishell		*init_all(char **envp);
t_command		*init_command(t_minishell	*ministruct);
t_minishell		*reset_ministruct(t_minishell *mini_struct);

// env.c
t_env			*add_env(t_env	*envars, char *key, char *value);
t_env			*remove_env(t_env	*envars, char *key);
char			**build_env(t_env	*envars);
char			*get_envar(t_env *envars, char *key);
t_env			*edit_env(t_env	*envars, char *key, char *value);

// print.c
int				print_env(t_env *envars);
void			print_error(char *exe, char *arg, char *error, int exit_code);
void			print_error_errno(char *exe, char *arg);

// free.c
void			free_t_env(t_env *envar);
void			free_envars(t_env *envars);
void			free_t_commands(t_command *cmd);
void			free_mini_vars(t_minishell *mini_struct);
void			ft_reset(t_minishell *mini_struct);

// builtins
int				cd(char **args, t_minishell *ministruct);
int				pwd(void);
int				echo(char **args);
int				export(char **args, t_env *envars, t_minishell *ministruct);
int				unset(char **args, t_env *envars, t_minishell *ministruct);
void			ft_exit(char **args, t_minishell *ministruct,
					int tmp_in, int tmp_out);
void			free_all(t_minishell *ministruct);

// utils.c
char			*get_mini_prompt(t_env *envars);

//execvp.c
int				ft_execvp(t_command *cmd, int tmp_in, int tmp_out);

//exec.c
int				exec(t_minishell *mini_struct);

//here_doc.c
int				ft_here_doc(char *limiter);

//status.c
int				*_status(void);

//signals.c
void			init_sighandlers(void);

// ft_quotes.c
int				check_quotes(const char *buffer);

// ft_split_argv.c
char			**ft_split_argv(const char *str);

// ft_split_argv_utils.c
int				ft_wordlen(const char *str);
int				ft_wordcount(const char *str);

// get_file.c
int				check_chev(t_minishell *memo, int *ret, int index, int j);

// get_file_utils.c
int				fill_av(t_minishell *memo);

// ft_expand.c
char			*ft_expand(char *line, t_env *envars);

// ft_get_chevron_nb.c
int				get_chevron_nb(char *line);

// piping.c
int				set_fd_out(t_minishell *mini_struct, int tmp_out);
int				set_fd_in(t_minishell *mini_struct, int tmp_in);
void			restore_fd(int tmp_in, int tmp_out, int *fd_in_out);
int				set_pipes(t_command *tmp, int *fd_in, int *fd_out, int tmp_out);

// builtins.c
int				redirect_builtin(t_command *cmd, t_minishell *ministruct,
					int tmp_in, int tmp_out);
int				is_builtin(char *exe);

// wait.c
int				wait_last_cmd(t_list	*pids);
#endif