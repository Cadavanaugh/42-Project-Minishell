NAME			= minishell

LIBFT_DIR		= ./libs/libft
LIBFT			= $(LIBFT_DIR)/libft.a	
LDLFLAGS		= -L$(LIBFT_DIR) -lft -lreadline

CC 				= cc
CFLAGS 			= -Wall -Werror -Wextra -I.

SRCS 			= src/minishell.c
OBJS 			= $(SRCS:%.c=%.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LDLFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re