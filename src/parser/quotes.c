#include "../../include/minishell.h"

// Should find the highest scope closed_quotes and return it
char    *process_quotes(char *word, t_meta *pkg)
{
    (void) word;
    (void) pkg;
 /*   char    *before_quote;
    char    *quote_content;
    char    *after_quote;
    char    *temp;
    char    *ret;
    int     i;
    
    i = -1;
    before_quote = NULL;
    quote_content = NULL;
    after_quote = NULL;
    while (word[++i])
    {
        if (is_quote(word[i]))
        {
            before_quote = ft_substr(word, 0, i);
            quote_content = return_quote_content(word, i, pkg);
            ret = ft_strjoin(before_quote, quote_content);
            free(before_quote);
            free(quote_content);
            i += ft_strlen(quote_content);
            if (word[i] != '\0')
                after_quote = ft_substr(word, i, ft_strlen(word) - i);
        }
        i++;
    }*/
    return (0);
}


/*int iterate_quote_content(t_meta *pkg)
{

    while (pkg->str[temp_i] != '\0')
    {
        if (pkg->str[temp_i] == type && ft_strchr(pkg->str + temp_i + 1, type))
            return (temp_i);
        else
            temp_i++;
    }
    return (temp_i);
}*/

int quote_len(t_meta *pkg, int *iterator)
{
    char type;
    int len;
    // temp, remove after testing;
    //int len_backup;
    
    type = pkg->str[*iterator];
    *iterator += 1;
    len = 0;
    //len_backup = len;
while (pkg->str[*iterator] != '\0')
    {
        if (pkg->str[*iterator] == type)
        {
            *iterator += 1;
            return (len);
        }
        else
        {
            *iterator += 1;
            len++; 
        }
    }
//    printf("Len results: word[%d]=%c, word[%d]=%c\n", len_backup, pkg->str[pkg->i + len_backup], len, pkg->str[pkg->i + len]);
    return (len);
}

// add_quote content, must add ALL characters to the string word,
// the character within pkg->str, starting from the index pkg->i
// which  
int add_quote_content(char *word, int i, t_meta *pkg)
{
    int type;

// woaw spotted a big mistake here, I was passing i instead of pkg->i !!
// wrong index can fuck it all up
    type = pkg->str[pkg->i];
    pkg->i++;
    while (pkg->str[pkg->i] != '\0')
    {
        if (pkg->str[pkg->i] == type)
        {
            pkg->i++;
            return (i);
        }
        else
        {
            word[i] = pkg->str[pkg->i];
        }
        printf("|| word[%d] now: %c ||\n", i - 1, pkg->str[pkg->i - 1]);
        i++;
        pkg->i++;
    }
    printf("quotes.c: add_quote_content word index: %d\n", i);
    return (i);
}

int quote_in_word(char *word)
{
    return (ft_strchr(word, 39) || ft_strchr(word, 34));
}

/*char    *return_quote_content(char *word, int i, t_meta *pkg)
{
    char    *ret;
    char    *old;
    char    *new;
    int     temp_i;
    int     type;

    ret = ft_strdup("");
    new = NULL;
    type = word[i];
    temp_i = i;
    while (word[temp_i] != '\0');
    {
        if (type == 34 && is_dollar(word[temp_i]))
            printf("TODO:substitute variable in quote\n");
        if (word[temp_i] == type && is_last_quote(word, i))
        else if (word[temp_i] && !is_last_quote(word, i))
        {
            new = return_quote
        }
        temp_i++;
    }
}*/

/*int how_many_closed_quotes(t_meta *pkg)
{
    char    *str;
    int     i;
    int     scount;
    int     dcount;

    str = pkg->str;
    i = pkg->i;
    scount = 0;
    dcount = 0;
    if (is_quote(str[i]))
    {
        while (str[++i])
        {
            if (str[i] == 39)
                scount++;
            else if (str[i] == 34)
                dcount++;
        }
    }
    if ((dquote % 10 == 0) && (squote % 10 == 0))
        return (QUOTES_CLOSED);
    else if ((dquote % 10 == 0) || (squote % 10 == 0))
        return (CLOSED_AND_UNCLOSED_QUOTES);
    else
        return (UNCLOSED_QUOTES);
}*/
