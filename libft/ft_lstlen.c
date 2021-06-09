/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:28:33 by dteemo            #+#    #+#             */
/*   Updated: 2019/04/18 12:28:34 by dteemo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlen(t_list **alst)
{
	t_list	*cur;
	size_t	res;

	if (!alst)
		return (0);
	cur = *alst;
	res = 0;
	while (cur)
	{
		cur = cur->next;
		res++;
	}
	return (res);
}
