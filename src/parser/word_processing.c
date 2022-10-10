/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbars <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:26:52 by sbars             #+#    #+#             */
/*   Updated: 2022/10/10 14:26:54 by sbars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	word_len(char *str, t_meta *pkg)
{
	int	counter;
	int	iterator;
	
	counter = 0;
	iterator = pkg->i;
	while (is_word(str, iterator))
	{
		if (is_quote(str[iterator]) && (str[iterator + 1] != '\0'))
		{
			counter += quote_len(pkg, &iterator);
		}
		else 
		{
			counter++;
			iterator++;
		}
	}
	return (counter);
}

// Counts the length of the word, including when it is made of one or more quotes,
// allocates memory for that length, then copies characters from the main string
// to the word string, omitting the quotes and copying the rest
char	*return_word(char *str, t_meta *pkg)
{
	char	*word;
	int		len;
	int		i;

	i = 0;
	len = word_len(str, pkg);
	word = NULL;
	word = (char *) malloc(sizeof(char) * len);
	word[len] = '\0';
	while (i < len)
	{ 
		if (is_quote(str[pkg->i]))
			i = add_quote_content(word, i, pkg);
		else if (is_word(str, pkg->i))
			word[i++] = str[pkg->i++];
	}
	pkg->i--;
	printf("> word \"%s\"(%ld chars): \n", word, ft_strlen(word));
	return (word);
}

char	*is_cmd(char *name, t_meta *pkg)
{
	int	i;

	i = -1;
	char	*path_and_slash;
	char	*full_path;

	path_and_slash = NULL;
	full_path = NULL;
	if (pkg->paths == NULL)
		pkg->paths = init_paths(pkg);
	while (pkg->paths[++i])
	{
		path_and_slash = ft_strjoin(pkg->paths[i], "/");
		full_path = ft_strjoin(path_and_slash, name);
		if (access(full_path, X_OK) == 0)
		{
			free(path_and_slash);
			return (full_path);
		}
	}
	return (NULL);
}



int	is_builtin(char *word, t_meta *pkg)
{
	(void) pkg;
	// Reason I'm keeping the list below commented, is because
	// this function could, on top of checking if the command is a builtin
	// return a digit telling us which builtin it is.
	// To associate a digit with a builtin, just have to do some defines
	// #define ECHO 101
	// #define CD 102
	// etc, then it's useable in if conditions (if tmp = ECHO, run echo), potential time/space-saver
	/*int i;
	char	*list[8];
	
	i = -1;
	list[0] = "echo";
	list[1] = "cd";
	list[2] = "pwd";
	list[3] = "export";
	list[4] = "unset";
	list[5] = "env";
	list[6] = "exit";
	list[7] = NULL;*/
	if (ft_strncmp(word, "echo", 5) == 0 || ft_strncmp(word, "cd", 3) == 0 
		|| ft_strncmp(word, "pwd", 4) == 0 || ft_strncmp(word, "export", 7 ) == 0
		|| ft_strncmp(word, "unset", 6) == 0 || ft_strncmp(word, "env", 4) == 0 
		|| ft_strncmp(word, "exit", 5) == 0)
		return (1);
	return (0);
}
