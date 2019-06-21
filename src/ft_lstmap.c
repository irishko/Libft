/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irishko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:47:19 by irishko           #+#    #+#             */
/*   Updated: 2017/12/12 18:47:21 by irishko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*movelist;

	if (lst)
	{
		movelist = f(lst);
		new = movelist;
		while (lst->next)
		{
			lst = lst->next;
			if (!(movelist->next = f(lst)))
			{
				free(movelist->next);
				return (NULL);
			}
			movelist = movelist->next;
		}
		return (new);
	}
	return (NULL);
}
