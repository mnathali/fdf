/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnathali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:08:34 by mnathali          #+#    #+#             */
/*   Updated: 2021/10/20 22:27:56 by mnathali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*fre;

	while ((*lst) != 0)
	{
		del((*lst)->content);
		fre = *lst;
		*lst = (*lst)->next;
		free(fre);
	}
	lst = 0;
}
