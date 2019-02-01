/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:50:00 by sbrella           #+#    #+#             */
/*   Updated: 2018/12/08 19:59:07 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	if (!(s1) || !(s2))
		return (-1);
	i = 0;
	while (s1[i] && (s1[i] == s2[i]) && n > 1)
	{
		n--;
		i++;
	}
	if (n == 0 || s1[i] == s2[i])
		return (1);
	else
		return (0);
}
