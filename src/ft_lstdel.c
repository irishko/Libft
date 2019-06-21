/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irishko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:44:53 by irishko           #+#    #+#             */
/*   Updated: 2017/12/12 18:44:54 by irishko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*dva;
	t_list	*adin;

	dva = *alst;
	while (dva)
	{
		adin = dva->next;
		del(dva->content, dva->content_size);
		free(dva);
		dva = adin;
	}
	*alst = NULL;
}
