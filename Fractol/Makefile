# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/04 16:59:00 by fshanaha          #+#    #+#              #
#    Updated: 2019/04/01 18:02:43 by fshanaha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCSFOLDER = ./

SRCS = main.c \
		buffalo.c burning_ship.c duobrot.c error.c julia.c keys.c \
		mandelbrot.c move_julia.c triobrot.c

OBJNAME = $(SRCS:.c=.o)
OBJDIR = ./obj/
OBJ = $(addprefix $(OBJDIR),$(OBJNAME))
INCLUDES = ./include/
FLAG = -Wall -Wextra -Werror
BUILDFOLDER = ./build/

LIBFTFOLDER = ./Libft/
LIBFTINCLUDES = $(LIBFTFOLDER)
LIBFTINK = -I $(LIBFTINCLUDES) -L $(LIBFTFOLDER) -lft

MLXLINTMACOS = -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
all: $(NAME)
$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFTFOLDER)
	gcc $(FLAG) $(OBJ) $(MLXLINTMACOS) $(LIBFTINK) -o $(NAME)
clean:
	$(MAKE) -C $(LIBFTFOLDER) clean
	rm -rf $(OBJDIR)
	rm -rf *.o
fclean: clean
	$(MAKE) -C $(LIBFTFOLDER) fclean
	rm -rf $(BUILDFOLDER)
	rm -rf $(NAME)
$(OBJDIR)%.o:$(SRCSFOLDER)%.c
	mkdir -p $(OBJDIR)
	gcc -g -I $(INCLUDES) -o $@ -c $<
re: fclean $(NAME)
