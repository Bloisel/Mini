/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 22:18:10 by bloisel           #+#    #+#             */
/*   Updated: 2024/06/10 22:18:12 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

int	g_exit_status;

void	main_aux(t_data *dta)
{
	check_err(dta);
	replace_special_char_ac(dta);
	init_triple(dta);
	rm_pipe_t_tab(dta->p);
	print_t_tab(dta->p);
	redirect(dta);
}

int	main(int argc, char **argv, char **env)
{
	t_data				dta;
	t_list				*envl;
	struct sigaction	sa;
	struct termios		terminal;

	if (argc == 0 && argv[1])
		exit (1);
	init_dta(&dta, env);
	init_env_list(&dta, &envl, env);
	check_path(&dta);
	update_shlvl(&dta);
	while (!dta.exit)
	{
		init_signal(&dta, &sa, &terminal);
		put_env_in_arg_2(&dta);
		get_prompt_t(&dta);
		if (dta.prompt != NULL)
			main_aux(&dta);
		reset_data(&dta);
	}
	ft_exit(&dta);
	return (0);
}

// ENTRE le 4 et le 5
//echo '$USER' 