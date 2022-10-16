/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanlan <lanlan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 13:28:34 by lanlan            #+#    #+#             */
/*   Updated: 2022/10/16 22:41:57 by lanlan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "parser.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <fcntl.h>
typedef struct s_prompt
{
	t_list	*commands;
	char	**envp;
	pid_t	pid;
}			t_prompt;

typedef struct s_meta
{
	t_prompt	*prompt;
	char	**paths;
	char	*str;
	int		i;
	int		i_backup;
}			t_meta;

// parser/
// parser.c
int		parser(char *str, t_meta *pkg);
// prompt.c
char	*get_prompt(t_prompt prompt);
// For further parser prototypes, see parser.h

// utils/
// matrix.c
char	**ft_matrixdup(char **matrix);
// error.c
int		errormsg(char *str, t_meta	*pkg);
// init.c
t_meta	*init_meta(t_prompt *prompt);
char	**init_paths(t_meta	*pkg);
// parsing_utils.c
int		last_strchr_index(char *str, char c);

void	handle_sigint(int sig);
#endif
