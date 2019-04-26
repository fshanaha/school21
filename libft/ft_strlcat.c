/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:10:28 by fshanaha          #+#    #+#             */
/*   Updated: 2018/12/08 17:57:37 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *des, const char *append, size_t nt)
{
	char		*dst;
	const char	*app;
	size_t		n;
	size_t		i;

	dst = des;
	app = append;
	n = nt;
	while (n-- && *dst)
		dst++;
	i = dst - des;
	n = nt - i;
	if (n == 0)
		return (i + ft_strlen(app));
	while (*app)
	{
		if (n != 1)
		{
			*dst++ = *app;
			n--;
		}
		app++;
	}
	ft_bzero(dst, 1);
	return (i + (app - append));
}
