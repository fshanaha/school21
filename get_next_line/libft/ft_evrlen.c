/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:16:45 by fshanaha          #+#    #+#             */
/*   Updated: 2018/12/10 12:17:04 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_evrlen(char const *str, char symb)
{
	size_t	i;

	i = 0;
	while (*str != symb && *str)
	{
		str++;
		++i;
	}
	return (i);
}
