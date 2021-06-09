/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 12:01:59 by dteemo            #+#    #+#             */
/*   Updated: 2019/04/06 12:02:02 by dteemo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;
	size_t	j;
	int		res;
	char	*s1;

	s1 = (char*)str1;
	i = 0;
	if (ft_strcmp(str2, "\0") == 0 && len == 0)
		return (s1);
	while (s1[i] != '\0' && i < len)
	{
		res = i;
		j = 0;
		while (s1[i + j] != '\0' && str2[j] != '\0' && (i + j) < len)
		{
			if (s1[i + j] != str2[j])
				res = -1;
			j++;
		}
		if (res != -1 && str2[j] == '\0')
			return (s1 + res);
		i++;
	}
	return (NULL);
}
