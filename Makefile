# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/14 15:15:31 by jose-rig          #+#    #+#              #
#    Updated: 2024/08/23 12:22:44 by jvalle-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = so_long
USER    = jvalle-d
MLX42   = MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm -fsanitize=address
LIBMLX	= MLX42/
CFLAGS  = -Wall -Wextra -Werror -g
CC      = clang

MAGENTA = \033[35;1m
YELLOW  = \033[33;1m
GREEN   = \033[32;1m
WHITE   = \033[37;1m
RESET   = \033[0m
GRAY 	= \033[0;90m
BLUE    = \033[34;1m
CYAN    = \033[37;1m
BOLD	= \033[1m
RED		= \033[31;1m

SRCS	:= ft_checkarg.c ft_checkmap.c ft_checkmap2.c ft_cleanmap.c ft_drawutils.c\
			ft_errors.c ft_findobjects.c ft_frees.c ft_initmlx.c ft_loadtextures.c\
			ft_loadtextures2.c ft_pastepixel.c ft_puts.c ft_puts2.c ft_startgame.c\
			ft_utils.c ft_utils2.c ft_printmoves.c main.c\

OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
		@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME):	compiling $(OBJS)
			@echo
			@echo "$(GREEN)Compiling MLX42$(RESET)"
			@make -C MLX42/build/
			@$(CC) $(CFLAGS) $(OBJS) $(MLX42) -o $(NAME)
			@echo "$(MAGENTA)SO_LONG compiled!$(RESET)"

$%.o: %.c
			@echo "$(BLUE)Compiling: $(RESET)$(notdir $<)"
			@$(CC) $(CFLAGS) -c $< -o $@


compiling:
			@echo "$(YELLOW)Compiling so_long!$(RESET)"
			
clean:
			@rm -rf $(OBJS)
			@make clean -C MLX42/build/
			@echo "$(RED)Cleaning libraries MLX.$(RESET)"
			@echo "$(RED)Cleaning SO_LONG executables.$(RESET)"
			

fclean:
			@rm -rf $(OBJS)
			@rm -rf $(NAME)
			@make clean -C MLX42/build/
			@echo "$(RED)Fcleaning libraries MLX.$(RESET)"
			@echo "$(RED)Fcleaning so_long.$(RESET)"

re: fclean all
			@echo "$(YELLOW)So_long recompiled$(RESET)"

norm:
			@echo "$(YELLOW)Norminette of so_long files.$(RESET)"
			@norminette $(SRCS)
			@echo 
		
						
.PHONY: all clean fclean re norm compiling libmlx bonus
