/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:34:11 by mnathali          #+#    #+#             */
/*   Updated: 2021/10/20 20:51:50 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*toclear;

	new = malloc(sizeof(t_list));
	if (!new || !f)
		return (0);
	toclear = new;
	while (lst != 0)
	{
		new->content = f(lst->content);
		lst = lst->next;
		if (!lst)
			break ;
		if (!new->content)
			continue ;
		new->next = malloc(sizeof(t_list));
		if (!new->next)
		{
			ft_lstclear(&toclear, del);
			return (0);
		}
		new = new->next;
	}
	new->next = 0;
	return (toclear);
}
