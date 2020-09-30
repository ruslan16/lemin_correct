# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etristan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/07 16:32:13 by etristan          #+#    #+#              #
#    Updated: 2020/09/30 17:30:00 by sirvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_W = srcs/dlc.c srcs/dlc_t.c srcs/find_path_capacity.c srcs/get_path.c \
	srcs/main.c srcs/move_ants.c srcs/pars_link.c srcs/pars_room.c \
	srcs/search_path.c srcs/search_path_d.c srcs/search_path_t.c srcs/sort.c

SRC_NAME = $(notdir $(SRC_W))

#SRC_NAME = $(wildcard *.c)

SRC_PATH = srcs

OBJ_PATH = objs

OBJ_NAME = $(SRC_NAME:.c=.o)

DEP_NAME = $(SRC_NAME:.c=.d)

SRCS = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJS = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CFLAGS += -I ./inc

CFLAGS += -I ./libft/includes

LIBFT = libft

LDLIBS = -lft

LDFLAGS = -L $(LIBFT)

###############################################################################
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	NUMPROC := $(shell grep -c ^processor /proc/cpuinfo)
else ifeq ($(UNAME_S),Darwin)
	NUMPROC := $(shell sysctl hw.ncpu | awk '{print $$2}')
endif
################################################################################

all	: $(NAME)

fast	:
	@$(MAKE) -s -j$(NUMPROC)

libft.a	:
	@printf "$(RED)Making libft...$(EOC)\n"
	@$(MAKE) --no-print-directory -C $(LIBFT) all

$(OBJ_PATH)     : libft.a
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	@printf "$(GRN)Compiling with \"$(CFLAGS)\" :$(EOC)\n"

$(NAME)	: $(OBJS)
	@printf "$(GRN)%-50s$(EOC)\n" "Compilation done"
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)
	@printf "$(GRN)%-50s$(EOC)\n" "$(NAME_P) done"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@printf "%-50s\r" "$(CC) $@"
	$(CC) $(CFLAGS) -MD -o $@ -c $<

include $(wildcard $(OBJ_PATH)/$(DEP_NAME))

clean	:
	/bin/rm -rf $(OBJ_PATH)
	@$(MAKE) --no-print-directory -C $(LIBFT) fclean
	@printf "$(RED)./$(OBJ_PATH), libft cleaned$(EOC)\n"

fclean	:	clean
	/bin/rm -f $(NAME)
	@printf "$(RED)$(NAME), libft.a removed$(EOC)\n"

ref	:
	/bin/rm -rf $(OBJ_PATH)
	@printf "$(RED)./$(OBJ_PATH), cleaned$(EOC)\n"
	@$(MAKE) --no-print-directory -j$(NUMPROC) $(NAME)

re	:	fclean
	@$(MAKE) --no-print-directory -j$(NUMPROC) $(NAME)

.PHONY: all fast clean fclean re ref libft.a $(NAME)

GRN =	\033[0;32m
RED =	\033[0;31m
EOC =	\033[0m
