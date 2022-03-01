# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 16:07:45 by dha               #+#    #+#              #
#    Updated: 2022/03/01 19:44:21 by dha              ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
# CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf
NAME = so_long

LIBFT_DIR = ./libft
LIBFT_NAME = ft
LIBFT = $(LIBFT_DIR)/lib$(LIBFT_NAME).a

MINILIBX_DIR = ./minilibx_mms
MINILIBX_NAME = mlx
MINILIBX = libmlx.dylib

SRCS = main.c
INCS = solong.h
OBJ_DIR = ./obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# BONUS_SRCS = 
# BONUS_INCS = 
# BONUS_OBJS = $(addprefix $(OBJ_DIR)/, $(BONUS_SRCS:.c=.o))

all : $(NAME)

# bonus : $(BONUS)

$(NAME) : $(LIBFT) $(MINILIBX) $(OBJS) $(INCS)
	@$(CC) $(CFLAGS) $(OBJS) -L $(LIBFT_DIR) -l$(LIBFT_NAME) -L $(MINILIBX_DIR) -l$(MINILIBX_NAME) -framework OpenGL -framework Appkit -o $@
	@printf "💡 Make $(NAME) Done\n"

# $(BONUS) : $(LIBFT) $(BONUS_OBJS) $(BONUS_INCS)
# 	@$(CC) $(CFLAGS) -I ./ $(BONUS_OBJS) -L $(LIBFT_DIR) -l$(LIBFT_NAME) -o $@
# 	@printf "💡 Make $(BONUS) Done\n"
	
clean :
	@$(RM) $(OBJ_DIR)
	@echo "🗑 Remove $(NAME)'s OBJs Done"

fclean : clean
	@$(RM) $(NAME)
	@echo "🗑 Remove $(NAME) Done"

wclean : fclean $(LIBFT_NAME)_fclean

re : fclean all

rr : wclean all

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c $< -o $@ -g

.PHONY : all clean fclean wclean re rr $(LIBFT_NAME)_clean $(LIBFT_NAME)_fclean

$(LIBFT) :
	@make -C $(LIBFT_DIR)

$(LIBFT_NAME)_clean :
	@make -C $(LIBFT_DIR) clean

$(LIBFT_NAME)_fclean :
	@make -C $(LIBFT_DIR) fclean

$(MINILIBX) :
	@make -sC $(MINILIBX_DIR)
	@cp $(MINILIBX_DIR)/$(MINILIBX) .