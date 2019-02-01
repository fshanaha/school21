# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/09 16:38:55 by fshanaha          #+#    #+#              #
#    Updated: 2019/01/23 17:24:18 by sbrella          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

HEAD = fillit.h

READ = read_file.c

SOLSIM = solve_simple.c

MAIN = main.c

LIBFT = ./libft/libft.a

PUTSTR = ft_putstr_mod.c

PRINT = print_map.c

all: $(NAME)
$(NAME):
	@$(MAKE) -C ./libft/
	@gcc $(FLAGS) -o $(NAME) $(MAIN) $(READ) $(SOLSIM) $(PRINT) $(LIBFT) $(PUTSTR) -I $(HEAD)
clean:
	@$(MAKE) -C ./libft/ clean
fclean: clean
	@$(MAKE) -C ./libft/ fclean
	@rm -f $(NAME)
re:	fclean all
