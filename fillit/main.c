/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 16:50:11 by sbrella           #+#    #+#             */
/*   Updated: 2019/01/23 16:19:02 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char				*map;
	unsigned short int	*mas;

	map = NULL;
	if (argc != 2)
		return (ft_putstr_mod("error\n"));
	if (!(mas = read_file(argv[1])))
		return (ft_putstr_mod("error\n"));
	if (!(map = solve_simple(mas)))
		return (ft_putstr_mod("error\n"));
	print_map(map, map[400]);
	if (map)
		free(map);
	if (mas)
		free(mas);
	return (0);
}
