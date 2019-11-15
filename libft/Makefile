#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/23 14:34:22 by shasnaou          #+#    #+#              #
#    Updated: 2019/06/17 21:15:14 by shasnaou         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CLANG	=	clang

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	libft.a

SRC		=   ft_atoi.c       \
            ft_bzero.c      \
            ft_isalnum.c    \
            ft_isalpha.c    \
            ft_isascii.c    \
            ft_isprint.c    \
            ft_memcpy.c     \
            ft_memset.c     \
            ft_strcat.c     \
            ft_strchr.c     \
            ft_strcmp.c     \
            ft_strcpy.c     \
            ft_strdup.c     \
            ft_strlen.c     \
            ft_strncat.c    \
            ft_isdigit.c    \
            ft_strncmp.c    \
            ft_strncpy.c    \
            ft_strnstr.c    \
            ft_strrchr.c    \
            ft_strstr.c     \
            ft_tolower.c    \
            ft_toupper.c    \
            ft_putstr.c     \
            ft_putchar.c    \
            ft_memccpy.c    \
            ft_putendl.c    \
            ft_putchar_fd.c \
            ft_putstr_fd.c  \
            ft_putendl_fd.c \
            ft_memmove.c    \
            ft_memchr.c     \
            ft_memcmp.c     \
			ft_strlcat.c	\
			ft_memalloc.c	\
			ft_memdel.c		\
			ft_strnew.c		\
			ft_strdel.c		\
			ft_strclr.c		\
			ft_striter.c	\
			ft_striteri.c	\
			ft_strmap.c		\
			ft_strmapi.c	\
			ft_strequ.c		\
			ft_strnequ.c	\
			ft_strsub.c		\
			ft_strjoin.c	\
			ft_strtrim.c	\
			ft_strsplit.c	\
			ft_itoa.c		\
			ft_putnbr.c		\
			ft_putnbr_fd.c	\
			ft_lstnew.c		\
			ft_lstdelone.c	\
			ft_lstdel.c		\
			ft_lstadd.c		\
			ft_lstiter.c	\
			ft_lstaddelem.c	\
			ft_lstlen.c		\
			ft_lstmap.c		\
			ft_joinchar.c	\
			ft_same_char.c	\
			ft_min.c		\
			ft_max.c		\
			ft_fmin.c		\
			ft_fmax.c		\
			ft_strjoinc.c

OBJ =		$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)

%.o: %.c
			$(CLANG) -I. -o $@ -c $< $(CFLAGS)

clean:
			rm -rf $(OBJ)

fclean:		clean
			rm -rf $(NAME)

re:			fclean $(NAME)
