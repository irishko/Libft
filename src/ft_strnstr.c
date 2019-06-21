/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irishko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:44:31 by irishko           #+#    #+#             */
/*   Updated: 2017/11/07 20:47:25 by irishko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t k;
	size_t l;
	size_t save;

	i = 0;
	l = 0;
	k = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	l = ft_strlen(s2);
	while (s1[i])
	{
		save = i;
		while (s1[save] == s2[k] && save < len)
		{
			save++;
			k++;
			if (k == l)
				return ((char *)&s1[save - l]);
		}
		k = 0;
		i++;
	}
	return (NULL);
}
