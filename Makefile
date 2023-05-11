# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 05:11:21 by dtelnov           #+#    #+#              #
#    Updated: 2023/05/11 06:06:19 by dtelnov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
PROJECT_NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes/ -I libft/includes/
LIBFT = -L libft -lft
RM = rm -rf

# Reset
NC = \033[0m

# Colors
YELLOW = \033[0;33m
GREEN = \033[0;32m
BLUE = \033[0;34m
RED = \033[0;31m
PURPLE = \033[0;35m
CYAN = \033[0;36m
BLACK = \033[0;30m
WHITE = \033[0;37m

# Colors
BYELLOW = \033[1;33m
BGREEN = \033[1;32m
BBLUE = \033[1;34m
BRED = \033[1;31m
BPURPLE = \033[1;35m
BCYAN = \033[1;36m
BBLACK = \033[1;30m
BWHITE = \033[1;37m

SRC_DIR = sources/

FILES = move \
		parsing \
		position \
		presort \
		push_swap \
		push \
		reverse_rotate \
		rotate \
		sort \
		swap \
		utils_stack \
		utils \

SRCS = 	$(addsuffix .c, $(addprefix $(SRC_DIR), $(FILES)))

OBJS = $(SRCS:.c=.o)

TOTAL = $(words $(SRCS))
COUNT = 0

all: $(NAME)

$(NAME): $(OBJS)
	@make --no-print-directory -C libft/
	@echo "\n\n[🔘] $(BGREEN)Compiling $(PROJECT_NAME)..."
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(LIBFT)
	@echo "$(NC)"
	@printf "$(BBLACK)[%1d/%1d] 100%%\t$(BWHITE)All files have been compiled ✔️$(NC)\n" $(COUNT) $(TOTAL)
	@echo "[💠] $(BBLACK)$(NAME)\t$(BWHITE)Executable created ✔️\n$(NC)"

%.o: %.c
	@printf "[🔄] $(BPURPLE)Generating $(PROJECT_NAME) objects... %-33.33s\r$(NC)" $@
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@$(eval PERCENT:=$(shell echo $$((100*$(COUNT)/$(TOTAL)))))

bonus: all

clean:
	@$(RM) $(OBJS)
	@make --no-print-directory clean -C libft/
	@echo "[🧼] $(BYELLOW)Objects $(YELLOW)files have been cleaned from $(PROJECT_NAME) ✔️$(NC)"

fclean: clean
	@$(RM) $(NAME)
	@make --no-print-directory fclean -C libft/
	@echo "[🚮] $(BRED)All $(RED)files have been cleaned ✔️$(NC)"

re: clean all

.PHONY: bonus all clean fclean re