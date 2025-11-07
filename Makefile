NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =  srcs/pipex.c \
		srcs/utils.c

OBJS = $(SRCS:.c=.o)

GREEN = \033[0;32m
PURPLE = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(PURPLE)Compiling $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) compiled successfully!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(CYAN)Cleaning object files...$(RESET)"
	@rm -f $(OBJS)
	@echo "$(GREEN)Object files cleaned!$(RESET)"

fclean: clean
	@echo "$(CYAN)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)$(NAME) removed!$(RESET)"

re: fclean all

.PHONY: all clean fclean re