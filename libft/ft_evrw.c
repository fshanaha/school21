/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evrw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:04:18 by fshanaha          #+#    #+#             */
/*   Updated: 2018/12/10 12:04:57 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_evrw(char const *str, char symb)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		if (*str != symb)
		{
			i++;
			while (*str != symb && *str)
				str++;
		}
		while (*str == symb && *str)
			str++;
	}
	return (i);
}
