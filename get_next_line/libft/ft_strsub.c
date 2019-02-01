/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:29:03 by fshanaha          #+#    #+#             */
/*   Updated: 2018/12/09 14:31:13 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (0x0);
	if (s)
	{
		while (str && start--)
			s++;
		ft_strncpy(str, s, len);
		str[len] = '\0';
		return (str);
	}
	return (0x0);
}
