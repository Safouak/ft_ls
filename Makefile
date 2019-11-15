#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shasnaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/15 19:11:41 by shasnaou          #+#    #+#              #
#    Updated: 2019/06/17 21:14:08 by shasnaou         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	ft_ls

INC			=	-I./libft -I./includes

CLANG		=	clang

CFLAGS		=	-Wall -Wextra -Werror -g

LIB			=	./libft/libft.a

P_LIB		=	./libft/

P_SRC		=	./srcs/

SRCS		=	$(P_SRC)print_errors.c				\
				$(P_SRC)fill_node.c					\
				$(P_SRC)sort_reverse_and_time.c		\
				$(P_SRC)sort_print_and_free.c		\
				$(P_SRC)free_handler.c				\
				$(P_SRC)compute_layout.c			\
				$(P_SRC)prints.c					\
				$(P_SRC)addinfo.c					\
				$(P_SRC)ptr_swap.c					\
				$(P_SRC)sorts.c						\
				$(P_SRC)separate_files_types.c		\
				$(P_SRC)dirs_handling.c				\
				$(P_SRC)collect_arguments.c			\
				$(P_SRC)error_handling.c			\
				$(P_SRC)clip_date.c					\
				$(P_SRC)ls_handling.c				\
				$(P_SRC)init_ptr.c					\
				$(P_SRC)ft_ls.c						\
				$(P_SRC)main.c


OBJS		=	$(SRCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				make -C $(P_LIB)
				$(CLANG) $(INC) $(OBJS) -o $(NAME) -L libft/ -lft

%.o:			%.c
				$(CLANG) $(INC) -o $@ -c $< $(CFLAGS)

RM			=	rm -rf

clean:
				make -C $(P_LIB) clean
				$(RM) $(OBJS) $(P_SRC)*~ $(P_SRC)*# *~ *#

fclean:			clean
				make -C $(P_LIB) fclean
				$(RM) $(NAME)

re:				fclean all
