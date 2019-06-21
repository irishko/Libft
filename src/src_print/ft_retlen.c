/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irishko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 18:46:25 by irishko           #+#    #+#             */
/*   Updated: 2018/06/26 18:46:27 by irishko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			howbits(wint_t ch)
{
	int i;
	int ret;

	i = 0;
	while (++i < 32)
	{
		ch & 0x01 ? ret = i : 0;
		ch >>= 1;
	}
	return (ret);
}

int			how_width(wint_t wch)
{
	int che;

	che = howbits(wch);
	if (che <= 7)
		return (1);
	else if (che <= 11)
		return (2);
	else if (che <= 16)
		return (3);
	else
		return (4);
}

int			ft_howunsnbr(unsigned long long n)
{
	int	i;

	i = 0;
	while (n > 9)
	{
		i++;
		n = (n / 10);
	}
	return (++i);
}

void		ft_putnbrin(long long n)
{
	if (n < -9223372036854775807)
	{
		ft_putchar('9');
		n = 223372036854775808;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
		ft_putnbrin(n / 10);
	ft_putchar(n % 10 + 48);
}

int			ft_hownbr(intmax_t n, t_lst *ls)
{
	int	i;

	i = 0;
	if (n < -9223372036854775807)
	{
		ls->negnum = 1;
		return (19);
	}
	if (n < 0)
	{
		ls->negnum = 1;
		n *= -1;
	}
	while (n > 9)
	{
		i++;
		n = (n / 10);
	}
	return (++i);
}
