/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:35:55 by fshanaha          #+#    #+#             */
/*   Updated: 2018/12/06 16:12:33 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dubl;
	int		s;

	s = 0;
	while (src[s])
		s++;
	if (!(dubl = (char*)malloc(sizeof(*dubl) * (s + 1))))
		return (NULL);
	s = 0;
	while (src[s])
	{
		dubl[s] = src[s];
		s++;
	}
	dubl[s] = '\0';
	return (dubl);
}
