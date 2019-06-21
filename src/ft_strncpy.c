/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irishko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:04:28 by irishko           #+#    #+#             */
/*   Updated: 2017/11/07 17:14:06 by irishko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	cpy;

	cpy = 0;
	i = -1;
	while (++i < n)
		if (src[i] && !cpy)
			dst[i] = src[i];
		else
		{
			dst[i] = '\0';
			cpy = 1;
		}
	return (dst);
}
