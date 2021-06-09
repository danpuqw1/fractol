/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 11:48:16 by dteemo            #+#    #+#             */
/*   Updated: 2019/04/06 11:48:17 by dteemo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t	size;

	size = ft_strlen(s2);
	if (size > n)
		size = n;
	if (size != n)
		ft_memset(s1 + size, '\0', n - size);
	s1 = ft_memcpy(s1, s2, size);
	return (s1);
}
