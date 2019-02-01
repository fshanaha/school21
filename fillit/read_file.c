/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:12:38 by sbrella           #+#    #+#             */
/*   Updated: 2019/01/15 20:04:53 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short int	normalize(unsigned short int *piece)
{
	while ((0x8888 & *piece) == 0)
		*piece = *piece << 1;
	while ((0xF000 & *piece) == 0)
		*piece = *piece << 4;
	return (*piece);
}

unsigned short int	check_piece(unsigned short int piece)
{
	char	i;
	char	a;

	a = 0;
	i = -1;
	while (++i < 16)
		a += (piece >> i) & 1;
	CHECK(a != 4);
	a = 0;
	while (i + 1)
	{
		if (((piece >> i) & 1) != 1)
		{
			i--;
			continue;
		}
		((i % 4) != 0) ? a += (piece >> (i - 1)) & 1 : 0;
		((i % 4) != 3) ? a += (piece >> (i + 1)) & 1 : 0;
		(i < 12) ? a += (piece >> (i + 4)) & 1 : 0;
		(i > 3) ? a += (piece >> (i - 4)) & 1 : 0;
		i--;
	}
	return ((a == 6 || a == 8) ? normalize(&piece) : 0);
}

unsigned short int	get_next_piece(int fd)
{
	int					i;
	int					gnl;
	char				line[21];
	unsigned short int	piece;

	piece = 0;
	i = 0;
	CHECK((gnl = read(fd, line, 21)) != 20 && gnl != 21);
	CHECK(line[4] != '\n' || line[9] != '\n' || line[14] != '\n'
											|| line[19] != '\n');
	CHECK((gnl == 21) && line[20] != '\n');
	while (i < 21)
	{
		CHECK((i + 1) % 5 != 0 && i != 20 && line[i] != '.' && line[i] != '#');
		if ((i + 1) % 5 == 0 || i == 20)
		{
			i++;
			continue;
		}
		piece += line[i] & 1;
		piece = piece << (i != 18);
		i++;
	}
	return (check_piece(piece) + (gnl == 20 ? 1 : 0));
}

unsigned short int	*read_file(char *file)
{
	unsigned short int	nbr;
	int					fd;
	unsigned short int	*tetr;

	if (!(tetr = malloc(sizeof(unsigned short int) * 27)))
		return (NULL);
	tetr[0] = 0;
	fd = open(file, O_RDONLY);
	while ((nbr = get_next_piece(fd)))
	{
		if (tetr[0] == 26 || nbr == 1)
		{
			close(fd);
			free(tetr);
			return (NULL);
		}
		tetr[++tetr[0]] = nbr & 0xFFFE;
		if (nbr & 1)
			break ;
	}
	close(fd);
	if (nbr == 0)
		free(tetr);
	return (nbr == 0 ? 0 : tetr);
}
