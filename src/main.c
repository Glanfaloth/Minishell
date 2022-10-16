/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanlan <lanlan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:27:35 by lanlan            #+#    #+#             */
/*   Updated: 2022/10/16 22:47:51 by lanlan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
# include <readline/readline.h>

static t_prompt	init_prompt(char **argv, char **envp)
{
	t_prompt	prompt;

	(void) argv;
	prompt.commands = NULL;
	prompt.envp = ft_matrixdup(envp);
	return (prompt);
}

int	main(int argc, char **argv, char **envp)
{
	t_prompt	prompt;
	t_meta		*pkg;
	char		*prompt_str;

	prompt = init_prompt(argv, envp);
	while (argc || argv || envp)
	{
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, SIG_IGN);
		pkg = init_meta(&prompt);
		prompt_str = get_prompt(prompt);
//		chain = parser(readline(cwd));
		if (prompt_str)
			parser(readline(prompt_str), pkg);
		else
			parser(readline("guest@minishell $ "), pkg);
//		if (chain != NULL)
//     		executor(chain);
		free(prompt_str);
		free(pkg->paths);
		free(pkg);
	}
	return (0);
}
