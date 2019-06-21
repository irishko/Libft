/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irishko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:47:10 by irishko           #+#    #+#             */
/*   Updated: 2017/11/25 18:08:52 by irishko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char *s;

	if (size == 0)
		size = 1;
	if (size < 1)
		return (NULL);
	s = (char *)malloc(size + 1);
	if (s != NULL)
		ft_bzero(s, size + 1);
	else
		return (NULL);
	return (s);
}
