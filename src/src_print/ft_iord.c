/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iord.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irishko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 20:21:25 by irishko           #+#    #+#             */
/*   Updated: 2018/06/04 20:21:30 by irishko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void		znakchisla(t_lst *ls)
{
	if (ls->negnum)
		ft_putchar('-');
	else if (ls->flg_plus)
		ft_putchar('+');
	else if (ls->flg_space)
		ft_putchar(' ');
	else
		return ;
}

void			dopisatynoly(t_lst *ls, int m, intmax_t *chirik)
{
	int	ret;

	ret = ((ls->flg_plus || ls->flg_space) && !ls->negnum) ?
		(ls->precision + 1) : ls->precision;
	if (ls->width > ret && !ls->flg_minus)
	{
		ls->width -= ret + ls->negnum;
		while (ls->width--)
			ft_putchar(' ');
	}
	znakchisla(ls);
	(ls->negnum) ? *chirik *= -1 : 0;
	while (m--)
		ft_putchar('0');
	ft_putnbrin(*chirik);
	if (ls->width > ret && ls->flg_minus)
	{
		ls->width -= ret + ls->negnum;
		while (ls->width--)
			ft_putchar(' ');
	}
}

void			dopisatyprobel(t_lst *ls, int sko, intmax_t *chis)
{
	sko += ((ls->flg_plus || ls->flg_space) && !ls->negnum) ? 1 : 0;
	sko -= (ls->point && !ls->precision && !(*chis)) ? 1 : 0;
	(ls->flg_zero) ? znakchisla(ls) : 0;
	if (ls->width > sko && !ls->flg_minus)
	{
		ls->width -= sko + ls->negnum;
		while (ls->width--)
			ft_putchar((ls->flg_zero && !ls->point) ? '0' : ' ');
	}
	(ls->flg_zero) ? 0 : znakchisla(ls);
	(ls->negnum) ? *chis *= -1 : 0;
	if (ls->point && !ls->precision && !(*chis))
		;
	else
		ft_putnbrin(*chis);
	if (ls->width > sko && ls->flg_minus)
	{
		ls->width -= sko + ls->negnum;
		while (ls->width--)
			ft_putchar(' ');
	}
}

static intmax_t	typeimod(t_lst *ls, va_list *vl)
{
	intmax_t chil;

	if (ls->spec == 'D')
		ls->md_l = 1;
	chil = va_arg(*vl, intmax_t);
	if (ls->md_j)
		chil = (intmax_t)chil;
	else if (ls->md_ll)
		chil = (long long int)chil;
	else if (ls->md_l)
		chil = (long int)chil;
	else if (ls->md_z)
		chil = (size_t)chil;
	else if (ls->md_hh)
		chil = (signed char)chil;
	else if (ls->md_h)
		chil = (short int)chil;
	else
		chil = (int)chil;
	return (chil);
}

void			ft_intprt(t_lst *ls, va_list *vl)
{
	intmax_t	chislo;
	int			skolko;

	chislo = typeimod(ls, vl);
	skolko = ft_hownbr(chislo, ls);
	if (skolko > ls->precision && skolko > ls->width)
		if (!chislo)
			if (ls->point)
				;
			else
				ls->length++;
		else
			ls->length += skolko;
	else
		ls->length += (ls->precision > ls->width) ? ls->precision : ls->width;
	ft_howlen(ls, skolko);
	if (skolko < ls->precision)
		dopisatynoly(ls, ls->precision - skolko, &chislo);
	else
		dopisatyprobel(ls, skolko, &chislo);
}
