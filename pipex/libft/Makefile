# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lverkart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/16 14:17:30 by lverkart          #+#    #+#              #
#    Updated: 2021/04/16 14:17:33 by lverkart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

SRC		=	ft_memset.c		ft_bzero.c		ft_memcpy.c \
			ft_memccpy.c	ft_memmove.c	ft_memchr.c \
			ft_memcmp.c		ft_strlen.c		ft_strlcpy.c \
			ft_strlcat.c	ft_strchr.c		ft_strrchr.c \
			ft_strnstr.c	ft_strncmp.c	ft_atoi.c \
			ft_isalpha.c	ft_isdigit.c	ft_isalnum.c \
			ft_isascii.c	ft_isprint.c	ft_toupper.c \
			ft_tolower.c	ft_substr.c		ft_strjoin.c \
			ft_strtrim.c	ft_split.c		ft_itoa.c \
			ft_strmapi.c	ft_putchar_fd.c	ft_putstr_fd.c \
			ft_putendl_fd.c	ft_putnbr_fd.c	ft_calloc.c \
			ft_strdup.c

SBON	=	ft_lstnew.c			ft_lstadd_front.c \
			ft_lstsize.c		ft_lstlast.c \
			ft_lstadd_back.c 	ft_lstdelone.c \
			ft_lstclear.c		ft_lstiter.c \
			ft_lstmap.c

HEADER	=	libft.h

OBJ		=	$(patsubst %.c,%.o,$(SRC))

OBJBON	=	$(patsubst %.c,%.o,$(SBON))

OBJALL	=	$(patsubst %.c,%.o,$(SRC) $(SBON))

ifdef BONUS
	OBJ += $(patsubst %.c,%.o,$(SBON))
endif

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	ar rsc $(NAME) $?

%.o		: 	%.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

bonus:
	@$(MAKE) BONUS=1 all

clean	:
	$(RM) $(OBJ) $(OBJBON)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re 
