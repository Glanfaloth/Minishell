#include "../../include/minishell.h"

// TODO: Add support for word cut by quotes such as 
// ec'ho' or gr"e"p which have to work
static int	end_of_word_index(char *str, int i)
{
	//while (str[i] != '\0' && ft_isalnum(str[i]) && !is_blank(str, i) && !is_operator(str, i))
	while (is_word(str, i))
	{
		if (is_blank(str, i))
			return (i - 1);
		//if (is_blank(str, i) || is_operator(str, i) || !ft_isalnum(str[i]))
		//if (is_quote(str[i]))
		//i = closed_quotes_len(str, i);
		i++;
	}
	return (i - 1);
}

int	check_is_word(char	*str, int i)
{
	return (!is_blank(str, i) && !is_operator(str, i) && !is_dollar_question(str, i) && !is_quote(str[i]));
}

int	process_word(char *str, t_meta *pkg)
{
	char	*word;
	int		i;

	word = NULL;
	i = pkg->i;
	while (check_is_word(str, i))
		i++;
	if (i > pkg->i)
	{
		i = 0;
		word = (char *) malloc(sizeof(char) * i + 1);
		while (check_is_word(str, pkg->i))
			word[++i] = str[pkg->i++];
	}
	printf("end_of_word_index: %d\n", end_of_word_index(str, pkg->i));
	printf("process_word: value of i %d\n", pkg->i);
	printf("process_word (len:%ld): %s$\n", ft_strlen(word), word);
	if (is_cmd(word, pkg))
		pkg->i += cmd_extraction(str, pkg->i, word);
	//else if (is_builtin(str, word, pkg))
	//	i += create_builtin_token(str, i);
	else
		pkg->i += ft_strlen(word) - 1;
	/*else if (is_file(str, i, pkg))
		check_file_context(str, i);
		OR just store the word in a "word" token to use later when analyzing redirections for example
	*/
	printf("process_word: value of i %d\n---\n", pkg->i);
	free(word);
	return (pkg->i);
}

//TODO: Complete process_operator()

int	process_operator(char *str,t_meta *pkg)
{
	(void) pkg;
	printf("operator found %c\n", str[pkg->i]);
	if (str[pkg->i] == '|')
	{
		printf("found pipe\n");
	}
	else if (is_heredoc(str, pkg->i))
	{
		pkg->i += 1;
		printf("that's a heredoc, crazy\n");
		//handle_heredoc expansion/lookup
	}
	else if (is_redirection(str, pkg->i))
	{
		pkg->i++;
		printf("redirection found\n");
		//create_redirection_token;
	}
	return (pkg->i);
}

//TODO: Debug process_dollar() in all three situations where it has to work
/*int	process_dollar(char *str, int i, t_meta *pkg)
{
	(void) pkg;
	printf("dollar being processed: %s\n", str + i);
	if (is_dollar_question(str, i))
		i += dollar_question_exec(str, i);
	else if (is_var(str, i))
		i += var_substitution(str, i);
	else
		i += lone_dollar_sign(str, i);
	return (i);
}*/
