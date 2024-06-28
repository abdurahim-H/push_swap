# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/28 07:48:56 by abhudulo          #+#    #+#              #
#    Updated: 2024/06/28 07:48:59 by abhudulo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := libft.a
SRCS    := $(wildcard *.c)
SRCS_B  := $(wildcard *bonus.c)
HEADER  := libft.h
OBJ_DIR := obj/
OBJS    := $(SRCS:%.c=$(OBJ_DIR)%.o)
OBJS_B  := $(SRCS_B:%.c=$(OBJ_DIR)%.o)

CC      := gcc
CFLAGS  := -Werror -Wextra -Wall -I.

RED     := \033[1;31m
GREEN   := \033[1;32m
YELLOW  := \033[1;33m
RESET   := \033[0m

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_B)
	@echo "$(YELLOW)Creating library...$(RESET)"
	ar rcs $@ $^
	@echo "$(GREEN)Library created: $@$(RESET)"

$(OBJ_DIR)%.o: %.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Compiled: $<$(RESET)"

bonus: $(OBJS) $(OBJS_B)
	@echo "$(YELLOW)Making bonus part...$(RESET)"
	@$(MAKE) $(NAME)

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	rm -f $(OBJS) $(OBJS_B)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Full clean...$(RESET)"
	rm -f $(NAME)

re: fclean all
	@echo "$(GREEN)Rebuilt everything.$(RESET)"