# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lverkart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 15:28:04 by lverkart          #+#    #+#              #
#    Updated: 2021/06/07 15:28:06 by lverkart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex


CC				=	gcc

FLAGS			=	-Wall -Wextra -Werror

INC				=	-I includes/ -I$(LIB_DIR)

LIBFT			=	 $(LIB_DIR)libft.a

SRCB			=	pipex_bonus.c	pipex_mod_bonus.c	pipex_utilus_bonus.c	pipex_valid_bonus.c

SRC				=	pipex.c			pipex_valid.c

OBJ_NAME		=	$(SRC:.c=.o)

OBJB_NAME		=	$(SRCB:.c=.o)

SOURCES			=	$(addprefix $(SRC_DIR), $(SRC))

SOURCESB		=	$(addprefix $(SRC_DIR), $(SRCB))

OBJ				=	$(addprefix $(OBJ_DIR),$(OBJ_NAME))

OBJB			=	$(addprefix $(OBJ_DIR),$(OBJB_NAME))

OBJECTS_LIST	=	$(patsubst %.c, %.o, $(SRC))

OBJECTS			=	$(addprefix $(OBJ_DIR), $(OBJECTS_LIST))

HEADERS			=	includes/pipex.h libft/libft.h

LIB_DIR			=	libft/

SRC_DIR			=	srcs/

OBJ_DIR			=	objs/

ifdef BONUS
	OBJECTS_LIST	=	$(patsubst %.c, %.o, $(SRCB))
endif

all				:	$(NAME)


$(NAME)			:	$(LIBFT)  $(OBJ_DIR) $(OBJECTS)
	@$(CC) $(FLAGS) $(LIBFT) $(INC) $(OBJECTS) -o $(NAME)

bonus:
	@$(MAKE) BONUS=1 all	

$(OBJ_DIR)		:
	@mkdir -p $(OBJ_DIR)

$(LIBFT)		:
	@$(MAKE) -sC $(LIB_DIR)

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) -o $@ -c $< $(INC)

clean			:
	@$(MAKE) -sC $(LIB_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean			:	clean
	@rm -f $(LIBFT)
	@rm -f $(NAME)
	@rm -f $(NAMEB)

re				:	fclean all

.PHONY			:	all clean fclean re

