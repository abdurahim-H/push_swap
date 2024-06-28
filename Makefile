# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/28 07:48:45 by abhudulo          #+#    #+#              #
#    Updated: 2024/06/28 10:57:26 by abhudulo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project Name
NAME = push_swap

# Library Paths
LIB_PATH = libft/
LIB = $(LIB_PATH)libft.a

# UTHash Path and Repo
UTHASH_PATH = uthash/
UTHASH_REPO = https://github.com/troydhanson/uthash.git

# Source and Object Files
SRC_PATH = src/
OBJ_PATH = obj/
SRC_FILES = $(notdir $(wildcard $(SRC_PATH)*.c))
SRC = $(addprefix $(SRC_PATH),$(SRC_FILES))
OBJ = $(patsubst %,$(OBJ_PATH)%,$(SRC_FILES:.c=.o))

# Compiler and Flags
CC = gcc
CFLAGS = -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all \
         -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow \
         -fno-sanitize=null -fno-sanitize=alignment -Werror -Wextra

# Clean Command
RM = rm -rf

# Color Definitions
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m
BOLD = \033[1m
UNDERLINE = \033[4m
BG_RED = \033[1;41m
BG_GREEN = \033[1;42m
BG_YELLOW = \033[1;43m
BG_BLUE = \033[0;44m
BG_MAGENTA = \033[0;45m
BG_CYAN = \033[0;46m

# Echo Command
ECHO = printf

# Phony Targets
.PHONY: all subsystem clean fclean re clone_uthash

# Main Targets
all: clone_uthash subsystem $(NAME)
	@$(ECHO) "${BG_GREEN}${YELLOW}${BOLD}All components are built.${RESET}\n"

clone_uthash:
	@if [ ! -d "$(UTHASH_PATH)" ]; then \
		$(ECHO) "${BG_YELLOW}${RED}${BOLD}Cloning uthash repository...${RESET}\n"; \
		git clone $(UTHASH_REPO) $(UTHASH_PATH); \
	fi

subsystem:
	@$(ECHO) "${BG_YELLOW}${RED}${BOLD}Building libft...${RESET}\n"
	@make -C $(LIB_PATH) all

$(NAME): $(OBJ)
	@$(ECHO) "${BG_BLUE}${YELLOW}Compiling $(NAME)...${RESET}\n"
	@$(CC) $(CFLAGS) -I inc -I $(UTHASH_PATH) -o $(NAME) $(OBJ) $(LIB)
	@$(ECHO) "${BG_GREEN}${RED}$(NAME) has been compiled.${RESET}\n"

# Compilation Rule
$(OBJ_PATH)%.o: $(SRC_PATH)%.c | clone_uthash
	@mkdir -p $(OBJ_PATH)
	@$(ECHO) "${BG_BLUE}${YELLOW}Compiling $<...${RESET}\n"
	@$(CC) $(CFLAGS) -I inc -I $(UTHASH_PATH) -c $< -o $@

# Clean Objects
clean:
	@$(ECHO) "${BG_MAGENTA}${BLUE}Cleaning object files...${RESET}\n"
	@make -C $(LIB_PATH) clean
	@$(RM) $(OBJ_PATH)
	@$(ECHO) "${BG_RED}${GREEN}Object files removed.${RESET}\n"

# Full Clean
fclean: clean
	@$(ECHO) "${BG_MAGENTA}${BLUE}Performing full clean...${RESET}\n"
	@make -C $(LIB_PATH) fclean
	@$(RM) $(NAME)
	@$(RM) -rf $(UTHASH_PATH)
	@$(ECHO) "${BG_RED}${GREEN}All files removed.${RESET}\n"

# Rebuild
re: fclean all
	@$(ECHO) "${BG_GREEN}${YELLOW}${BOLD}Rebuilt everything.${RESET}\n"
