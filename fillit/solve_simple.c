/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_simple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:24:35 by sbrella           #+#    #+#             */
/*   Updated: 2019/01/23 17:29:14 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fillit.h"

int		delete_figure(char *map, char size, int i, unsigned short int piece)
{
	(0x8000 & piece) > 0 ? map[i] = 0 : 0;
	(0x4000 & piece) > 0 ? map[i + 1] = 0 : 0;
	(0x2000 & piece) > 0 ? map[i + 2] = 0 : 0;
	(0x1000 & piece) > 0 ? map[i + 3] = 0 : 0;
	(0x0800 & piece) > 0 ? map[i + size] = 0 : 0;
	(0x0400 & piece) > 0 ? map[i + size + 1] = 0 : 0;
	(0x0200 & piece) > 0 ? map[i + size + 2] = 0 : 0;
	(0x0080 & piece) > 0 ? map[i + size * 2] = 0 : 0;
	(0x0040 & piece) > 0 ? map[i + size * 2 + 1] = 0 : 0;
	(0x0008 & piece) > 0 ? map[i + size * 3] = 0 : 0;
	return (0);
}

int		check_figure(char *map, char size, int i, unsigned short int p)
{
	if ((((0x8000 & p) > 0) & (map[i] > 0))
	|| (((0x4000 & p) > 0) & (map[i + 1] > 0))
	|| (((0x2000 & p) > 0) & (map[i + 2] > 0))
	|| (((0x1000 & p) > 0) & (map[i + 3] > 0))
	|| (((0x0800 & p) > 0) & (map[i + size] > 0))
	|| (((0x0400 & p) > 0) & (map[i + size + 1] > 0))
	|| (((0x0200 & p) > 0) & (map[i + size + 2] > 0))
	|| (((0x0080 & p) > 0) & (map[i + size * 2] > 0))
	|| (((0x0040 & p) > 0) & (map[i + size * 2 + 1] > 0))
	|| (((0x0008 & p) > 0) & (map[i + size * 3] > 0)))
		return (1);
	return (0);
}

int		try_figure(char *map, char size, int i, unsigned short int p)
{
	if ((i % (size) == 0 ? size : i % size) + ((0x4444 & p) > 0)
	+ ((0x2222 & p) > 0) + ((0x1111 & p) > 0) > size)
		return (0);
	if (((i - 1) / size) + 1 + ((0x0F00 & p) > 0) + ((0x00F0 & p) > 0) +
	((0x000F & p) > 0) > size)
		return (0);
	if (check_figure(map, size, i, p))
		return (0);
	map[i] = map[i] | ((0x8000 & p) > 0) * map[400];
	map[i + 1] = map[i + 1] | ((0x4000 & p) > 0) * map[400];
	map[i + 2] = map[i + 2] | ((0x2000 & p) > 0) * map[400];
	map[i + 3] = map[i + 3] | ((0x1000 & p) > 0) * map[400];
	map[i + size] = map[i + size] | ((0x0800 & p) > 0) * map[400];
	map[i + size + 1] = map[i + size + 1] | ((0x0400 & p) > 0) * map[400];
	map[i + size + 2] = map[i + size + 2] | ((0x0200 & p) > 0) * map[400];
	map[i + size * 2] = map[i + size * 2] | ((0x0080 & p) > 0) * map[400];
	map[i + size * 2 + 1] = map[i + size * 2 + 1]
										| ((0x0040 & p) > 0) * map[400];
	map[i + size * 3] = map[i + size * 3] | ((0x0008 & p) > 0) * map[400];
	return (1);
}

int		backtrack(char *map, char size, char piece, unsigned short int *mas)
{
	int max_size;
	int i;
	int flag;

	if (piece > mas[0])
		return (1);
	i = 0;
	max_size = (int)size * (int)size;
	while (++i < max_size)
	{
		map[400] = piece + 'A' - 1;
		if ((flag = try_figure(map, size, i, mas[(int)piece])))
			if (backtrack(map, size, piece + 1, mas))
				return (1);
		if (flag)
			delete_figure(map, size, i, mas[(int)piece]);
	}
	return (0);
}

void	*solve_simple(unsigned short int *mas)
{
	char	*map;
	char	size;

	size = ft_sqrt(4 * mas[0]);
	if (!(map = (char*)malloc(401)))
		return (0);
	while (!(backtrack(map, size++, 1, mas)))
		map = ft_memset((void*)map, 0, 400);
	map[400] = size - 1;
	return (map);
}
