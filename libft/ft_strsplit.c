/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:53:40 by fshanaha          #+#    #+#             */
/*   Updated: 2018/12/11 11:07:49 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				**ft_strsplit(char const *s, char c)
{
	char		**malw;
	size_t		words;
	size_t		in;

	in = 0;
	if (!s)
		return (NULL);
	words = ft_evrw(s, c);
	if ((!(malw = (char **)malloc(sizeof(char*) * (words + 1)))))
		return (NULL);
	while (words--)
	{
		while (*(s + in) == c && *(s + in))
			++in;
		if (!(*malw++ = ft_strsub(s, in, ft_evrlen(s + in, c))))
		{
			malw = malw - ft_evrw(s, c) + words;
			ft_char_free_arr(&malw);
			return (NULL);
		}
		if (*(s + in) != c)
			in += ft_evrlen(s + in, c);
	}
	*malw = NULL;
	return (malw - ft_evrw(s, c));
}
