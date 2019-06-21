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

int		ft_strequ(char const *s1, char const *s2)
{
	size_t	i;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i] || s2[i])
		{
			if (s1[i] == s2[i])
				;
			else
				return (0);
			i++;
		}
	}
	return (1);
}