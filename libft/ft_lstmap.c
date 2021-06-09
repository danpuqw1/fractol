/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:02:33 by dteemo            #+#    #+#             */
/*   Updated: 2019/04/08 12:02:34 by dteemo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*cur;
	t_list	*new_el;
	t_list	*last;

	res = (t_list*)malloc(sizeof(t_list));
	if (!(res))
		return (NULL);
	cur = lst;
	res = f(cur);
	cur = cur->next;
	last = res;
	while (cur)
	{
		new_el = (t_list*)malloc(sizeof(t_list));
		if (!(new_el))
			return (res);
		new_el = f(cur);
		last->next = new_el;
		last = last->next;
		cur = cur->next;
	}
	return (res);
}
