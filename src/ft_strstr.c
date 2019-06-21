/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irishko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:17:09 by irishko           #+#    #+#             */
/*   Updated: 2017/11/07 20:43:52 by irishko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	int i;

	if (*str2 == '\0')
		return ((char *)str1);
	i = 0;
	while (*str1)
	{
		i = 0;
		if (*str1 == str2[i])
		{
			while (str1[i] == str2[i] && str1[i] && str2[i])
				i++;
			if (str2[i] == '\0')
				return ((char *)str1);
		}
		str1++;
	}
	return (NULL);
}
