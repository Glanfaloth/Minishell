/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_checks_B.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:56:03 by sbars             #+#    #+#             */
/*   Updated: 2022/09/09 19:22:00 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_cmd(char	**str, int i, t_meta *pkg)
{
	i = -1;


	if (pkg->paths = NULL)
		pkg->paths = paths_finder(truc);
	while (paths[++i])
	{
		
	}
	(void) str;
	(void) i;
	return (1);
}

int	is_builtin(char **str, int i, t_meta *pkg)
{
	(void) str;
	(void) i;
	return (0);
}
