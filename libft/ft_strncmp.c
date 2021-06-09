/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:42:53 by dteemo            #+#    #+#             */
/*   Updated: 2019/04/10 16:42:54 by dteemo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while (s1[i] == s2[i] && i < n)
	{
		if (s1[i] == '\0')
			return (s1[i] - s2[i]);
		i++;
	}
	if (i != n)
	{
		c1 = s1[i];
		c2 = s2[i];
		return (c1 - c2);
	}
	return (0);
}
