# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akalombo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/09 12:17:40 by akalombo          #+#    #+#              #
#    Updated: 2020/01/09 12:17:46 by akalombo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

LIBFT = libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = check_valid.c flag_l.c flag_r.c folders.c main.c sort_passed.c flag_R_.c	flag_l2.c flag_t.c save_content.c check_files.c flag_a.c flag_l3.c	flags.c	sizes.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME):
	make -C libft all
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT)
	
clean:
	make -C libft clean
	rm -f $(OBJS)

fclean:	clean
	make -C libft fclean
	rm -f $(NAME)

re : fclean all
