/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irishko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:23:18 by irishko           #+#    #+#             */
/*   Updated: 2018/06/26 19:38:37 by irishko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	probelpoi(t_lst *ls, int sko, long long *chis)
{
	sko -= (ls->point && !ls->precision && !(*chis)) ? 1 : 0;
	if (ls->width > sko && !ls->flg_minus)
	{
		ls->width -= sko + ls->negnum;
		while (ls->width--)
			ft_putchar(' ');
	}
	ft_putchar('0');
	ft_putchar('x');
	if (ls->point && !ls->precision && !(*chis))
		;
	else
		ft_putnbrhex(*chis, 16, ls);
	if (ls->width > sko && ls->flg_minus)
	{
		ls->width -= sko + ls->negnum;
		while (ls->width--)
			ft_putchar(' ');
	}
}

static void	nolypoi(t_lst *ls, int m, long long *chirik)
{
	int	ret;

	ret = ls->precision + 2;
	if (ls->width > ret && !ls->flg_minus)
	{
		ls->width -= ret + ls->negnum;
		while (ls->width--)
			ft_putchar(' ');
	}
	ft_putchar('0');
	ft_putchar('x');
	while (m-- > 0)
		ft_putchar('0');
	ft_putnbrhex(*chirik, 16, ls);
	if (ls->width > ret && ls->flg_minus)
	{
		ls->width -= ret + ls->negnum;
		while (ls->width--)
			ft_putchar(' ');
	}
}

void		ft_point(t_lst *ls, va_list *vl)
{
	long long	chir;
	int			skl;

	chir = va_arg(*vl, long long);
	skl = hexnbr(chir, 16);
	(!ls->width || skl + 2 > ls->width) ? (ls->length += 2) : 0;
	if (skl > ls->precision && skl + 2 > ls->width)
	{
		ls->length += (chir) ? skl : 0;
		ls->length += (!chir && !ls->point) ? 1 : 0;
	}
	else
		ls->length += (ls->precision > ls->width) ? ls->precision : ls->width;
	if (skl < ls->precision)
		nolypoi(ls, (ls->precision - skl), &chir);
	else if (ls->flg_zero && !ls->point && !ls->flg_minus)
	{
		ls->precision = ls->width;
		nolypoi(ls, ls->width - skl - 2, &chir);
	}
	else
		probelpoi(ls, skl + 2, &chir);
}
