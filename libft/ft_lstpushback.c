/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:26:09 by dteemo            #+#    #+#             */
/*   Updated: 2019/04/18 12:26:11 by dteemo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **alst, t_list *new_obj)
{
	t_list	*cur;

	if (!(alst) || !(new_obj))
		return ;
	cur = *alst;
	while (cur->next)
		cur = cur->next;
	cur->next = new_obj;
}
