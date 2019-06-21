/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irishko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:47:19 by irishko           #+#    #+#             */
/*   Updated: 2017/11/07 18:56:46 by irishko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int		i;
	char	*p;

	i = -1;
	p = (char *)str;
	while (p[++i])
	{
		if (p[i] == (unsigned char)ch)
			return (&p[i]);
	}
	if ((unsigned char)ch == '\0')
		return (&p[i]);
	return (NULL);
}
