/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irishko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:48:35 by irishko           #+#    #+#             */
/*   Updated: 2017/11/14 15:58:22 by irishko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	countnbr(int n)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (n < 0)
	{
		k = 1;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i + 1 + k);
}

static void	putstr(char *str, int n, int nb)
{
	if (n > 9)
		putstr(str, n / 10, nb - 1);
	str[nb] = (n % 10 + 48);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		k;

	k = countnbr(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	res = ft_strnew(k);
	if (!res)
		return (NULL);
	if (n >= 0)
		putstr(res, n, k - 1);
	if (n < 0)
	{
		res[0] = '-';
		putstr(res, -n, k - 1);
	}
	res[k] = '\0';
	return (res);
}
