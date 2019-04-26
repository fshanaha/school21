# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 19:16:59 by fshanaha          #+#    #+#              #
#    Updated: 2019/03/07 19:22:45 by fshanaha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

HEADER = libft.h

SRCS =	ft_lstadd.c ft_memset.c ft_strcmp.c ft_strncmp.c \
		ft_lstdel.c ft_num.c ft_strcpy.c ft_strncpy.c \
		ft_atoi.c ft_lstdelone.c ft_putchar.c ft_strdel.c ft_strnequ.c \
		ft_bzero.c ft_lstiter.c ft_putchar_fd.c ft_strdup.c ft_strnew.c \
		ft_evrlen.c ft_lstmap.c ft_putendl.c ft_strequ.c ft_strnstr.c \
		ft_evrw.c ft_lstnew.c ft_putendl_fd.c ft_striter.c ft_strrchr.c \
		ft_char_free_arr.c ft_memalloc.c ft_putnbr.c ft_striteri.c ft_strsplit.c \
		ft_isalnum.c ft_memccpy.c ft_putnbr_fd.c ft_strjoin.c ft_strstr.c \
		ft_isalpha.c ft_memchr.c ft_putstr.c ft_strlcat.c ft_strsub.c \
		ft_isascii.c ft_memcmp.c ft_putstr_fd.c ft_strlen.c ft_strtrim.c \
		ft_isdigit.c ft_memcpy.c ft_strcat.c ft_strmap.c ft_tolower.c \
		ft_isprint.c ft_memdel.c ft_strchr.c ft_strmapi.c ft_toupper.c \
		ft_itoa.c ft_memmove.c ft_strclr.c ft_strncat.c ft_cleancont.c \
		ft_power.c ft_get_next_line.c

FILE = $(SRCS: .c=.o)

all: $(NAME)

$(NAME):
	@gcc -g -c $(SRCS) -I $(HEADER)
	@ar rc $(NAME) *.o

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
