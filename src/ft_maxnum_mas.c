/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxnum_mas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irishko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 20:39:24 by irishko           #+#    #+#             */
/*   Updated: 2017/12/13 20:39:26 by irishko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_maxnum_mas(int *num, int len)
{
	int i;
	int j;

	i = 0;
	j = num[i];
	while (i < len - 1)
	{
		if (num[i] > j)
			j = num[i];
		i++;
	}
	return (j);
}
