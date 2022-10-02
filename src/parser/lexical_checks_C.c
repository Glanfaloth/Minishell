#include "../../include/minishell.h"

int	cmd_check_and_process(char *str, char *word, t_meta *pkg)
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
			printf("> Cmd found!: %s\n> binary path: %s\n", name, full_path);
			free(path_and_slash);
			free(full_path);
			return (1);
		}
	}
	return (0);
}



//TODO: Debug and complete is_builtin
int	builtin_check_and_process(char *str, char *word, t_meta *pkg)
{
	(void) pkg;
	(void) str;
	(void) word;
/*	int i;
	char	*list[8];
	
	i = -1;
	list[0] = "echo";
	list[1] = "cd";
	list[2] = "pwd";
	list[3] = "export";
	list[4] = "unset";
	list[5] = "env";
	list[6] = "exit";
	list[7] = NULL;
	while (list[++i] != NULL)
	{
		if (ft_strncmp(list[i], word, ft_strlen(list[i])))
			return (1);
	}

	(void) word;
	(void) str;
	(void) pkg;
	return (0);*/
}