/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irishko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 19:54:34 by irishko           #+#    #+#             */
/*   Updated: 2017/11/05 20:39:11 by irishko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*p1;
	char	*p2;
	size_t	i;
	size_t	k;

	k = n - 1;
	i = 0;
	p1 = (char *)s1;
	p2 = (char *)s2;
	while (p2 > p1 && i < n)
	{
		p1[i] = p2[i];
		i++;
	}
	while (i < n)
	{
		p1[k] = p2[k];
		i++;
		k--;
	}
	return (s1);
}
