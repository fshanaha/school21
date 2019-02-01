/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:29:10 by sbrella           #+#    #+#             */
/*   Updated: 2018/12/10 15:39:19 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	getwlen(const char *s, char c)
{
	size_t a;

	a = 0;
	while (*s != c && *s)
	{
		s++;
		a++;
	}
	return (a);
}

static void		ft_free_masmas(size_t a, char **mas)
{
	while (a)
		free(mas[a--]);
	free(mas[0]);
	free(mas);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	count;
	size_t	a;
	char	**mas;

	a = 0;
	if (!(s))
		return (0);
	count = ft_count_words(s, c);
	if (!(mas = (char**)malloc(sizeof(char*) * (count + 1))))
		return (0);
	while (a < count)
	{
		while (*s == c)
			s++;
		if (!(mas[a] = (char*)malloc(getwlen(s, c) + 1)))
		{
			ft_free_masmas(a, mas);
			return (0);
		}
		ft_strcopy(mas[a++], s, (getwlen(s, c) + 1));
		s += getwlen(s, c);
	}
	mas[a] = 0;
	return (mas);
}
