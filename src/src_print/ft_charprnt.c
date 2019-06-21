/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charprnt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irishko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 16:33:54 by irishko           #+#    #+#             */
/*   Updated: 2018/06/15 16:33:55 by irishko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	wcharmask(wint_t wch, int k, int bit[])
{
	int i;

	i = 0;
	if (k <= 7)
		bit[i] = wch;
	else if (k <= 11)
	{
		bit[i] = wch >> 6 | 0xC0;
		bit[++i] = (wch & 0x3F) | 0x80;
	}
	else if (k <= 16)
	{
		bit[i] = wch >> 12 | 0xE0;
		bit[++i] = (wch >> 6 & 0x3F) | 0x80;
		bit[++i] = (wch & 0x3F) | 0x80;
	}
	else
	{
		bit[i] = (wch >> 18 | 0xF0) & ~(1 << 3);
		bit[++i] = (wch >> 12 & 0x3F) | 0x80;
		bit[++i] = (wch >> 6 & 0x3F) | 0x80;
		bit[++i] = (wch & 0x3F) | 0x80;
	}
	return (i + 1);
}

void		ft_putwchar(wint_t wch)
{
	int		k;
	int		nbr;
	int		bin[4];

	nbr = 0;
	nbr = howbits(wch);
	k = wcharmask(wch, nbr, bin);
	nbr = 0;
	while (nbr < k)
		ft_putchar(bin[nbr++]);
}

static void	ft_chrnul(t_lst *ls)
{
	ls->length += (ls->width) ? ls->width : 1;
	if (ls->width > 1 && !ls->flg_minus)
	{
		ls->width -= 1;
		while (ls->width--)
			ft_putchar((ls->flg_zero) ? '0' : ' ');
	}
	ft_putchar(0);
	if (ls->width > 1 && ls->flg_minus)
	{
		ls->width -= 1;
		while (ls->width--)
			ft_putchar((ls->flg_zero) ? '0' : ' ');
	}
}

void		ft_charprnt(t_lst *ls, va_list *vl)
{
	unsigned char hj;

	hj = va_arg(*vl, unsigned);
	if (!hj)
	{
		ft_chrnul(ls);
		return ;
	}
	if ((1 > ls->precision && 1 > ls->width))
		ls->length += 1;
	else
		ls->length += (1 > ls->width) ? 1 : ls->width;
	if (ls->width > 1 && !ls->flg_minus)
	{
		ls->width -= 1;
		while (ls->width--)
			ft_putchar((ls->flg_zero) ? '0' : ' ');
	}
	ft_putchar(hj);
	if (ls->width > 1 && ls->flg_minus)
	{
		ls->width -= 1;
		while (ls->width--)
			ft_putchar(' ');
	}
}

void		ft_wchar(t_lst *ls, va_list *vl)
{
	wint_t	wch;
	int		skoko;

	wch = va_arg(*vl, wint_t);
	if (!wch)
	{
		ft_chrnul(ls);
		return ;
	}
	skoko = how_width(wch);
	if (ls->point && ls->precision < skoko && ls->precision)
		skoko = ls->precision;
	ls->length += (skoko > ls->width) ? skoko : ls->width;
	ft_zero_space(ls, skoko);
	ft_putwchar(wch);
	if (ls->width > skoko && ls->flg_minus)
	{
		ls->width -= skoko;
		while (ls->width--)
			ft_putchar(' ');
	}
}
