/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:13:23 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:22:26 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define USER "\002\033[0;36mminishell$> \033[0;37m\003"
# define MAXINT 2147483647

# include"../libft/libft.h"
# include<readline/readline.h>
# include<readline/history.h>
# include<stdio.h>
# include<sys/types.h>
# include<sys/wait.h>
# include<unistd.h>
# include<signal.h>
# include<errno.h>
# include<fcntl.h>
# include<dirent.h>
# include<termios.h>

typedef struct s_lst
{
	char	*flag;
	char	*data;
}	t_lst;

typedef struct s_arg
{
	int		*quotes;
	char	**arg;
}	t_arg;

typedef struct s_data
{
	int		fd[2][2];
	int		status;
	int		is_in;
	int		is_out;
	int		fd_in;
	int		fd_out;
	char	**actual;
	char	**keys;
	int		key_done;
	int		is_hdoc;
	char	**dup_env;
	t_list	**env_list;
	t_list	*key_to_free;
	int		path_ok;
	int		st;
	char	**path_split;
	char	*cmd_path;
	int		back2;
	char	*nickname;
	char	*empty;
	t_lst	**d_arg;
	size_t	nb_arg;
	char	*prompt_t;
	int		secure_len;
	char	*temp_str_replace_arg;
	char	**prompt;
	char	***p;
	int		nb_cmd_p;
	int		ready_next;
	char	**historique;
	size_t	nb_arg_hist;
	size_t	nb_pipe;
	int		exit_multi_pipe;
	char	*pipe_str;
	char	**env;
	char	**brut_env;
	int		exit;
	int		exit_actual;
}	t_data;

extern int	g_exit_status;

//prompt
void	init_dta(t_data *dta, char **env);
int		get_prompt_t(t_data *dta);
int		geprompt_2(t_data *dta, char *tmp);
void	get_nickname(t_data *dta, char **env);
void	print_char_tab_t(char **tab);
void	rl_replace_line(const char *text, int clear_undo);
void	init_triple(t_data *dta);
char	**tab_dup(char **tab);
void	print_t_tab(char ***tab);

//buildin
void	pwd(t_data *dta);
void	unset(t_data *dta, int j);
void	export(t_data *dta);
void	env(t_data *dta, int is_export);
void	echo(t_data *dta, int i);
void	cd(t_data *dta);
void	run_minishell(t_data *dta);
void	exec_cmd(t_data *dta);
void	unset_from_list(t_data *dta, char **var, int len);

//pars
void	init_historic(t_data *dta, char *new);
int		is_wspace(char c);
int		is_sep(char c);
int		is_to_space(char c);
int		is_redirect(char c);
int		check_equal(t_data *dta);
void	replace_tab(t_data *dta);
void	space_spe_char(t_data *dta);
size_t	nb_charinstr(char *str, char c);
int		check_equal(t_data *dta);
void	check_end_pipe(t_data *dta);
int		check_last_char(char *str, char c);
void	check_is_hdoc(t_data *dta, int i);
int		check_only_space(t_data *dta);
void	replace_pipe(t_data *dta);
void	addtab_arg(t_data *dta, t_lst *lst);
char	*replace_arg(t_data *dta);
void	replace_in_quote(t_data *dta);
void	replace_in_simple_quote(t_data *dta);
void	replace_special_char(t_data *dta);
void	replace_special_char_in_arg(t_data *dta);
void	replace_not_in_db(t_data *dta, size_t len, size_t i, int exist);
void	replace_existing_arg(t_data *dta);
void	remove_quote(t_data *dta);
void	add_historic(t_data *dta);
int		check_arg(char *l, char *str);
void	print_historic(t_data *dta);
void	print_arg(t_data *dta);
t_lst	**pars_equal(t_data *dta);
void	put_str_in_new_file(char *str, char *key, t_data *dta);
void	store_key(t_data *dta, char *key);
void	stop_handle(t_data *dta, int i);
void	reconstruct_prompt(t_data *dta, int i, int j);
void	reconstruct_prompt_2(t_data *dta, int *i, int *j, char *new);
void	set_arg(t_data *dta, int *arg);
int		size_to_char(char *str, char c);
void	replace_existing_arg_for_env(t_data *dta, t_lst *lst);
void	redirect(t_data *dta);
char	*ft_strnstr_len(const char *big, const char *little, size_t len);
void	init_env_list(t_data *dta, t_list **envp, char **env);
void	put_env_in_arg_2(t_data *dta);
void	reconstruct_prompt(t_data *dta, int i, int j);
char	**list_to_tab(t_list *lst);
void	prepare_for_next(t_data*dta);
void	ft_lst_free(t_list *lst);
char	*ft_getenv(const char *str, t_data *dta);
char	*strstr_el(const char *big, const char *little,
			size_t len, size_t ilen);
int		hub_env(t_data *dta, char **env_brut);
void	handle_in_quote(t_data *dta, int i);
int		tab_len(char **tab);
void	remove_from_arglst(t_data *dta, char *str);
void	replace_special_char_ac(t_data *dta);

//exit
void	ft_exit(t_data *dta);
void	free_tab(char **str);
void	free_triple_tab(char ***tab);
void	free_lst(t_lst **lst, t_data *dta);
void	free_keys(t_data *dta);
void	free_tab_len(char **str, size_t nb_arg);
void	reset_data(t_data *dta);
void	check_err(t_data *dta);

//signal
void	init_signal(t_data *dta, struct sigaction *sa,
			struct termios *terminal);
void	handle_sig(int signum, siginfo_t *info, void *ptr);
void	handle_sig_alt(int signum, siginfo_t *info, void *ptr);

//execut
void	update_env_var(t_data *dta, char *var, char *value);
void	run_cmd_whith_pipe(t_data *dta);
int		mess_error(t_data *dta, int err, char *s1, char *s2);
void	r_redirection(t_data *dta, int i);		
void	check_redirs(t_data *dta);
int		get_cmd_path(t_data *dta);
int		is_builtin(t_data *dta);
void	execute_cmd(t_data *dta);
void	exec_hdoc(t_data *dta);
int		get_path(t_data *dta);
void	run_cmd_no_pipe(t_data *dta);
void	rm_pipe_t_tab(char ***tab);
//main
void	check_path(t_data *dta);
void	dup_env(t_data *dta, char **env);
void	put_env_in_arg(t_data *dta);
void	update_shlvl(t_data *dta);
#endif
