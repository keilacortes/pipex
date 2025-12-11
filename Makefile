NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft

SRCS =  $(addprefix srcs/, main.c \
						   utils.c \
						   pipex.c \
						   path.c \
						   )

OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a

GREEN = \033[0;32m
PURPLE = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(LIBFT) $(NAME)

$(LIBFT):
	@echo "$(PURPLE)Compiling libft...$(RESET)"
	@make -C ./libft  --no-print-directory

$(NAME): $(OBJS)
	@echo "$(PURPLE)Compiling $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo "$(GREEN)$(NAME) compiled successfully!$(RESET)"

clean:
	@echo "$(CYAN)Cleaning object files...$(RESET)"
	@rm -f $(OBJS)
	@make -C ./libft clean --no-print-directory
	@echo "$(GREEN)Object files cleaned!$(RESET)"

fclean: clean
	@echo "$(CYAN)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@make -C ./libft fclean --no-print-directory
	@echo "$(GREEN)$(NAME) removed!$(RESET)"

re: fclean all

.PHONY: all clean fclean re
