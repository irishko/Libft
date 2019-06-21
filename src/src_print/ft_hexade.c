/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexade.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irishko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 23:17:46 by irishko           #+#    #+#             */
/*   Updated: 2018/06/08 23:17:49 by irishko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void		ft_putnbrhex(unsigned long long hexkex, int hex, t_lst *ls)
{
	if (hexkex > (unsigned long long)(hex - 1))
		ft_putnbrhex((hexkex / hex), hex, ls);
	if ((hexkex % hex) > 9 && !(ls->spec == 'X'))
		ft_putchar(hexkex % hex + 87);
	else if ((hexkex % hex) > 9)
		ft_putchar(hexkex % hex + 55);
	else
		ft_putchar(hexkex % hex + 48);
}

int			hexnbr(unsigned long long hexkex, int hex)
{
	int i;

	i = 1;
	while (hexkex > (unsigned long long)(hex - 1))
	{
		hexkex /= hex;
		i++;
	}
	return (i);
}

static void	probelhex(t_lst *ls, int sko, unsigned long long *chis)
{
	sko += ((ls->flg_plus || ls->flg_space) && !ls->negnum) ? 1 : 0;
	sko -= (ls->point && !ls->precision && !(*chis)) ? 1 : 0;
	if (ls->width > sko && !ls->flg_minus)
	{
		ls->width -= sko + ls->negnum;
		(ls->flg_lattice && ls->flg_zero && *chis) ? ft_zero_x(ls, chis) : 0;
		while (ls->width--)
			ft_putchar((ls->flg_zero && !ls->point) ? '0' : ' ');
	}
	if (ls->flg_lattice && !(ls->flg_zero) && *chis)
		ft_zero_x(ls, chis);
	if (!((ls->point && !ls->precision) && !(*chis)))
		ft_putnbrhex(*chis, (ls->spec == 'o' || ls->spec == 'O') ? 8 : 16, ls);
	else if (ls->flg_lattice && (ls->spec == 'o' || ls->spec == 'O') && !*chis)
	{
		ft_putchar('0');
		ls->length++;
	}
	if (ls->width > sko && ls->flg_minus)
	{
		ls->width -= sko + ls->negnum;
		while (ls->width--)
			ft_putchar(' ');
	}
}

static void	nolyhex(t_lst *ls, int m, unsigned long long *chirik)
{
	int	ret;

	ret = ls->precision;
	if (ls->width > ret && !ls->flg_minus)
	{
		ls->width -= ret + ls->negnum;
		while (ls->width--)
			ft_putchar(' ');
	}
	if (ls->flg_lattice && *chirik)
		ft_zero_x(ls, chirik);
	while (m--)
		ft_putchar('0');
	ft_putnbrhex(*chirik, (ls->spec == 'o' || ls->spec == 'O') ? 8 : 16, ls);
	if (ls->width > ret && ls->flg_minus)
	{
		ls->width -= ret + ls->negnum;
		while (ls->width--)
			ft_putchar(' ');
	}
}

void		ft_hexade(t_lst *ls, va_list *vl)
{
	unsigned long long	hexchis;
	int					hexkol;

	hexchis = typeunsig_mod(ls, vl);
	hexkol = hexnbr(hexchis, (ls->spec == 'o' || ls->spec == 'O') ? 8 : 16);
	ls->flg_zero = (ls->flg_minus) ? 0 : ls->flg_zero;
	if (ls->flg_lattice && hexchis)
	{
		ls->width -= (ls->spec == 'o' || ls->spec == 'O') ? 0 : 2;
		hexkol += (ls->spec == 'o' || ls->spec == 'O') ? 1 : 0;
	}
	if (hexkol > ls->precision && hexkol > ls->width)
	{
		ls->length += (hexchis) ? hexkol : 0;
		ls->length += (!hexchis && !ls->point) ? 1 : 0;
	}
	else
		ls->length += (ls->precision > ls->width) ? ls->precision : ls->width;
	if (hexkol < ls->precision)
		nolyhex(ls, ls->precision - hexkol, &hexchis);
	else
		probelhex(ls, hexkol, &hexchis);
}
