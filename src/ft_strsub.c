/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irishko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:22:02 by irishko           #+#    #+#             */
/*   Updated: 2017/11/07 21:37:32 by irishko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	i = 0;
	if (s)
	{
		if (len == 0)
			return (ft_strnew(1));
		if (!s || (res = ft_strnew(len)) == 0)
			return (NULL);
		while (len--)
			res[i++] = s[start++];
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}
