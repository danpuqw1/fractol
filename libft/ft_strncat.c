/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 11:48:03 by dteemo            #+#    #+#             */
/*   Updated: 2019/04/06 11:48:05 by dteemo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(const char *str1, const char *str2, size_t count)
{
	size_t	i;
	int		j;
	char	*s1;

	s1 = (char*)str1;
	i = 0;
	j = 0;
	while (s1[j] != '\0')
		j++;
	while (str2[i] != '\0' && i < count)
	{
		s1[j + i] = str2[i];
		i++;
	}
	s1[i + j] = '\0';
	return (s1);
}
