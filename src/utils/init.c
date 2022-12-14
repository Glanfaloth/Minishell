/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <sbars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:19:40 by sbars             #+#    #+#             */
/*   Updated: 2022/10/24 11:46:53 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_meta	*init_meta(t_prompt	*prompt)
{
	t_meta	*meta;

	meta = NULL;
	meta = (t_meta *) malloc(sizeof(t_meta) * 1);
	meta->prompt = prompt;
	meta->paths = NULL;
	meta->str = NULL;
	meta->i = 0;
	return (meta);
}

char	**init_paths(t_meta	*pkg)
{
	int		i;
	char	**tmp;
	char	**paths;

	i = -1;
	tmp = NULL;
	paths = NULL;
	while (pkg->prompt->envp[++i])
	{
		if (ft_strncmp(pkg->prompt->envp[i], "PATH=", 5) == 0)
		{
			tmp = ft_split(pkg->prompt->envp[i], '=');
			paths = ft_split(tmp[1], ':');
			free(tmp);
			if (paths)
				return (paths);
		}
	}
	return (0);
}
