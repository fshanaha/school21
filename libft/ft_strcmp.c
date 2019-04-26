/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:35:22 by fshanaha          #+#    #+#             */
/*   Updated: 2018/12/06 17:19:20 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*ss1;
	const unsigned char	*ss2;

	ss1 = (const unsigned char*)s1;
	ss2 = (const unsigned char*)s2;
	while (*ss1 != '\0' || *ss2 != '\0')
	{
		if (*ss1 != *ss2)
			return (*ss1 - *ss2);
		ss1++;
		ss2++;
	}
	return (0);
}
