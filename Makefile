NAME					= minishell

CC						= gcc
CFLAGS					= -Wall -Werror -Wextra
AR						= ar rcs
RM						= rm -rf
CDEBUG = #-fsanitize=address

LIBFT_DIR				= ./libft/
LIBFT_FLAGS				= -L ./$(LIBFT_DIR) -lft
LIBFT_FILE				= $(LIBFT_DIR)libft.a

INCS_DIR				= ./include/
SRCS_DIR				= ./src/

INCS					= -I include

SRCS					= $(SRCS_DIR)main.c \
						$(SRCS_DIR)signal.c \
						$(SRCS_DIR)/parser/parser.c \
						$(SRCS_DIR)/parser/prompt.c \
						$(SRCS_DIR)/parser/lexical_checks_A.c \
						$(SRCS_DIR)/parser/lexical_checks_B.c \
						$(SRCS_DIR)/parser/lexical_checks_C.c \
						$(SRCS_DIR)/parser/word_processing.c \
						$(SRCS_DIR)/parser/processing.c \
						$(SRCS_DIR)/parser/create_tokens.c \
						$(SRCS_DIR)/parser/quotes.c \
						$(SRCS_DIR)/utils/matrix.c \
						$(SRCS_DIR)/utils/init.c \
						$(SRCS_DIR)/utils/error.c
					
OBJS					= $(SRCS:.c=.o)

.c.o :
	$(CC) -I ~/.brew/opt/readline/include -I /usr/local/opt/readline/include -I /opt/homebrew/Cellar/readline/8.1.2/include $(CFLAGS) $(CDEBUG) -I $(INCS_DIR) -o $@ -c $?

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -L /usr/local/opt/readline/lib -I /usr/local/opt/readline/include -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include -L /opt/homebrew/Cellar/readline/8.1.2/lib -I /opt/homebrew/Cellar/readline/8.1.2/include $(CDEBUG) -lreadline -o $(NAME) $(OBJS) $(LIBFT_FLAGS) -I $(INCS_DIR)

all : $(NAME)

clean :
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS) minishell.dSYM

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) minishell.dSYM

re : fclean all

norm :
	norminette $(SRCS) $(INCS_DIR)*.h

PHONY	: all clean fclean re