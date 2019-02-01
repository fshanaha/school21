/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:13:54 by sbrella           #+#    #+#             */
/*   Updated: 2019/01/23 17:28:22 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# define CHECK(x) if (x) return (0);

int					delete_figure(char *map, char size, int i,
										unsigned short int piece);
int					check_figure(char *map, char size, int i,
										unsigned short int p);
int					try_figure(char *map, char size, int i,
										unsigned short int p);
int					backtrack(char *map, char size, char piece,
										unsigned short int *mas);
void				*solve_simple(unsigned short int *mas);
unsigned short int	normalize(unsigned short int *piece);
unsigned short int	*read_file(char *file);
void				*solve_simple(unsigned short int *mas);
void				print_map(char *map, char size);
unsigned short int	get_next_piece(int fd);
unsigned short int	convert(char *line);
int					ft_putstr_mod(char const *s);

#endif
