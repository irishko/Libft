/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irishko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 20:54:39 by irishko           #+#    #+#             */
/*   Updated: 2018/06/26 20:54:41 by irishko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_printff(t_lst *ls)
{
	int sko;

	sko = 1;
	ls->length += (ls->width > 1) ? ls->width : 1;
	if (ls->width > sko && !ls->flg_minus)
	{
		ls->width -= sko;
		while (ls->width--)
			ft_putchar((ls->flg_zero) ? '0' : ' ');
	}
	ft_putchar('%');
	if (ls->width > sko && ls->flg_minus)
	{
		ls->width -= sko + ls->negnum;
		while (ls->width--)
			ft_putchar(' ');
	}
}

void	ft_zero_x(t_lst *ls, unsigned long long *chis)
{
	ft_putchar('0');
	ls->length += (ls->spec == 'x' || ls->spec == 'X') ? 2 : 0;
	if (ls->spec == 'x' || ls->spec == 'X')
		ft_putchar((ls->spec == 'x') ? 'x' : 'X');
	else if (!*chis)
		ls->length++;
}

void	ft_other(t_lst *ls)
{
	ls->length += (ls->width) ? ls->width : 1;
	if (ls->width > 1 && !ls->flg_minus)
	{
		ls->width -= 1;
		while (ls->width--)
			ft_putchar((ls->flg_zero) ? '0' : ' ');
	}
	ft_putchar(ls->spec);
	if (ls->width > 1 && ls->flg_minus)
	{
		ls->width -= 1;
		while (ls->width--)
			ft_putchar((ls->flg_zero) ? '0' : ' ');
	}
}

void	ft_putnull(t_lst *ls)
{
	int kol;

	kol = 6;
	(ls->point && ls->precision < kol) ? kol = ls->precision : 0;
	ls->length += (kol > ls->width) ? kol : ls->width;
	if ((ls->width > 6 || ls->point) && !ls->flg_minus)
	{
		ls->width -= (ls->point && ls->precision < 6) ? ls->precision : 6;
		while (ls->width--)
			ft_putchar((ls->flg_zero) ? '0' : ' ');
	}
	write(1, "(null)", (ls->point && ls->precision < 6) ? ls->precision : 6);
	if ((ls->width > 6 || ls->point) && ls->flg_minus)
	{
		ls->width -= (ls->point && ls->precision < 6) ? ls->precision : 6;
		while (ls->width--)
			ft_putchar(' ');
	}
}

void	ft_zero_space(t_lst *ls, int kol)
{
	if (ls->width > kol && !ls->flg_minus)
	{
		ls->width -= kol;
		while (ls->width--)
			ft_putchar((ls->flg_zero) ? '0' : ' ');
	}
}
