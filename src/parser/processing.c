/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:26:36 by sbars             #+#    #+#             */
/*   Updated: 2022/10/24 15:10:11 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	process_word(char *str, t_meta *pkg)
{
	char	*word;
	char	*path;

	word = NULL;
	word = return_word(str, pkg);
	path = is_cmd(word, pkg);
	if (is_builtin(word, pkg))
	{
		if (path)
			free(path);
		create_builtin_token(word, pkg);
	}
	else if (path)
	{
		create_cmd_token(word, path, pkg);
	}
	else
	{
		if (path)
			free(path);
		create_alien_word_token(word, pkg);
	}
	free(word);
}

void	process_operator(char *str, t_meta *pkg)
{
	(void) pkg;
	if (str[pkg->i] == '|')
		;//create_pipe_token(pkg, etc);
	else if (is_heredoc(str, pkg->i))
		expand_heredoc(pkg);
	else if (is_redirection(str, pkg->i))
		;//create_redirection_token;
}

void	process_dollar(char *str, t_meta *pkg)
{

	printf("> dollar: %s\n", str + pkg->i);
	if (is_var(str, pkg->i))
		(void) pkg;
		//pkg-> = var_substitution();
	if (is_dollar_question(str, pkg->i))
		(void) pkg;
	else
		(void) pkg;
}
