/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:44:51 by dteemo            #+#    #+#             */
/*   Updated: 2019/04/07 15:44:52 by dteemo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_obj;
	void	*new_cont;
	size_t	new_size;

	new_size = content_size;
	new_obj = (t_list*)malloc(sizeof(t_list));
	if (!(new_obj))
		return (NULL);
	new_obj->next = NULL;
	if (content == NULL)
	{
		new_obj->content = NULL;
		new_obj->content_size = 0;
	}
	else
	{
		new_cont = (void*)malloc(content_size);
		if (!(new_cont))
			return (new_obj);
		new_cont = ft_memcpy(new_cont, content, content_size);
		new_obj->content = new_cont;
		new_obj->content_size = new_size;
	}
	return (new_obj);
}
