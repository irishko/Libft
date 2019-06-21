/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsig.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irishko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 23:27:50 by irishko           #+#    #+#             */
/*   Updated: 2018/06/08 23:27:52 by irishko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void			ft_putnbrun(unsigned long long n)
{
	if (n > 9)
		ft_putnbrun(n / 10);
	ft_putchar(n % 10 + 48);
}

static void			ft_probelun(t_lst *ls, int sko, unsigned long long *chis)
{
	sko += ((ls->flg_plus || ls->flg_space) && !ls->negnum) ? 1 : 0;
	sko -= (ls->point && !ls->precision && !(*chis)) ? 1 : 0;
	if (ls->width > sko && !ls->flg_minus)
	{
		ls->width -= sko + ls->negnum;
		while (ls->width--)
			ft_putchar((ls->flg_zero && !ls->point) ? '0' : ' ');
	}
	if (ls->point && !ls->precision && !(*chis))
		;
	else
		ft_putnbrun(*chis);
	if (ls->width > sko && ls->flg_minus)
	{
		ls->width -= sko + ls->negnum;
		while (ls->width--)
			ft_putchar(' ');
	}
}

static void			ft_nolyun(t_lst *ls, int m, unsigned long long *chirik)
{
	int	ret;

	ret = ls->precision;
	if (ls->width > ret && !ls->flg_minus)
	{
		ls->width -= ret + ls->negnum;
		while (ls->width--)
			ft_putchar(' ');
	}
	while (m--)
		ft_putchar('0');
	ft_putnbrun(*chirik);
	if (ls->width > ret && ls->flg_minus)
	{
		ls->width -= ret + ls->negnum;
		while (ls->width--)
			ft_putchar(' ');
	}
}

unsigned long long	typeunsig_mod(t_lst *ls, va_list *vl)
{
	unsigned long long chil;

	if (ls->spec == 'U' || ls->spec == 'O')
		ls->md_l = 1;
	chil = va_arg(*vl, unsigned long long);
	if (ls->md_l)
		chil = (unsigned long int)chil;
	else if (ls->md_hh)
		chil = (unsigned char)chil;
	else if (ls->md_h)
		chil = (unsigned short int)chil;
	else if (ls->md_ll)
		chil = (unsigned long long)chil;
	else if (ls->md_j)
		chil = (uintmax_t)chil;
	else if (ls->md_z)
		chil = (ssize_t)chil;
	else
		chil = (unsigned int)chil;
	return (chil);
}

void				ft_unsig(t_lst *ls, va_list *vlt)
{
	unsigned long long	uchis;
	int					kol;

	uchis = typeunsig_mod(ls, vlt);
	kol = ft_howunsnbr(uchis);
	if (kol > ls->precision && kol > ls->width)
	{
		ls->length += (uchis) ? kol : 0;
		ls->length += (!uchis && !ls->point) ? 1 : 0;
	}
	else
		ls->length += (ls->precision > ls->width) ? ls->precision : ls->width;
	if (kol < ls->precision)
		ft_nolyun(ls, ls->precision - kol, &uchis);
	else
		ft_probelun(ls, kol, &uchis);
}
