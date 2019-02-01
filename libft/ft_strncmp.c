/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:24:31 by fshanaha          #+#    #+#             */
/*   Updated: 2018/12/06 17:27:52 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = (unsigned char*)str1;
	st2 = (unsigned char*)str2;
	while (n--)
	{
		if (*st1 != *st2)
			return (*st1 - *st2);
		if (*st1 == '\0' || *st2 == '\0')
			return (0);
		st1++;
		st2++;
	}
	return (0);
}
