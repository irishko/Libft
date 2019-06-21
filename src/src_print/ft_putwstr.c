/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irishko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 18:33:42 by irishko           #+#    #+#             */
/*   Updated: 2018/06/15 18:33:44 by irishko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_wstrlen(wchar_t *schto)
{
	int nmb;

	nmb = 0;
	while (*schto)
	{
		nmb += how_width(*schto);
		schto++;
	}
	return (nmb);
}

static void	ft_putwstr(wchar_t *gh, int precision)
{
	while (*gh && precision >= 0)
		if ((precision -= how_width(*gh)) >= 0)
		{
			ft_putwchar(*gh);
			gh++;
		}
		else
			break ;
}

static int	pre_minus(wchar_t *gh, int precision)
{
	while (*gh && precision > 0)
		if ((precision >= how_width(*gh)))
		{
			precision -= how_width(*gh);
			gh++;
		}
		else
			break ;
	return (precision);
}

void		ft_wstrprnt(t_lst *ls, va_list *vl)
{
	wchar_t	*hj;
	int		kol;

	hj = va_arg(*vl, wchar_t *);
	if (!hj)
	{
		ft_putnull(ls);
		return ;
	}
	kol = ft_wstrlen(hj);
	if (ls->point && ls->precision < kol)
	{
		kol = ls->precision;
		kol -= pre_minus(hj, kol);
	}
	ls->length += (kol > ls->width) ? kol : ls->width;
	ft_zero_space(ls, kol);
	ft_putwstr(hj, kol);
	if (ls->width > kol && ls->flg_minus)
	{
		ls->width -= kol + ls->negnum;
		while (ls->width--)
			ft_putchar(' ');
	}
}

void		ft_strprnt(t_lst *ls, va_list *vl)
{
	char	*hj;
	int		kol;

	hj = va_arg(*vl, char *);
	if (!hj)
	{
		ft_putnull(ls);
		return ;
	}
	kol = ft_strlen(hj);
	if (ls->point && ls->precision < kol)
		kol = ls->precision;
	ls->length += (ls->width > kol) ? ls->width : kol;
	ft_zero_space(ls, kol);
	write(1, hj, kol);
	if (ls->width > kol && ls->flg_minus)
	{
		ls->width -= kol + ls->negnum;
		while (ls->width--)
			ft_putchar(' ');
	}
}
