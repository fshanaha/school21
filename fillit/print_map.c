/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 17:59:35 by sbrella           #+#    #+#             */
/*   Updated: 2019/01/22 18:40:28 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_byteprint(size_t size, void *map)
{
	size_t	count;

	count = 0;
	while (count < size)
	{
		ft_putchar((((char*)map)[count] == 0) ? '.' : ((char*)map)[count]);
		count++;
	}
}

void		print_map(char *map, char size)
{
	char count;

	count = size;
	map++;
	while (count--)
	{
		ft_byteprint(size, map);
		ft_putchar('\n');
		map = map + size;
	}
}
