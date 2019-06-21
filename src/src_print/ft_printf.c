/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irishko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 23:27:50 by irishko           #+#    #+#             */
/*   Updated: 2018/06/08 23:27:52 by irishko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_lst	fillstruct(void)
{
	t_lst v;

	v.spec = 0;
	v.width = 0;
	v.precision = 0;
	v.md_h = 0;
	v.md_hh = 0;
	v.md_l = 0;
	v.md_ll = 0;
	v.md_j = 0;
	v.md_z = 0;
	v.point = 0;
	v.flg_minus = 0;
	v.flg_plus = 0;
	v.flg_space = 0;
	v.flg_lattice = 0;
	v.flg_zero = 0;
	v.negnum = 0;
	v.point = 0;
	v.length = 0;
	return (v);
}

void	cleanstruct(t_lst *l)
{
	l->spec = 0;
	l->width = 0;
	l->precision = 0;
	l->md_h = 0;
	l->md_hh = 0;
	l->md_l = 0;
	l->md_ll = 0;
	l->md_j = 0;
	l->md_z = 0;
	l->point = 0;
	l->flg_minus = 0;
	l->flg_plus = 0;
	l->flg_space = 0;
	l->flg_lattice = 0;
	l->flg_zero = 0;
	l->negnum = 0;
	l->point = 0;
}

void	second_prog(t_lst *lst, va_list *vl)
{
	if (lst->spec == 'i')
		ft_intprt(lst, vl);
	else if (lst->spec == 'd' || lst->spec == 'D')
		ft_intprt(lst, vl);
	else if (lst->spec == 'u' || lst->spec == 'U')
		ft_unsig(lst, vl);
	else if (lst->spec == 'p')
		ft_point(lst, vl);
	else if (lst->spec == 'o' || lst->spec == 'O')
		ft_hexade(lst, vl);
	else if (lst->spec == 'x' || lst->spec == 'X')
		ft_hexade(lst, vl);
	else if (lst->spec == 'c' || lst->spec == 'C')
		(lst->spec == 'c' && !lst->md_l) ? ft_charprnt(lst, vl)
		: ft_wchar(lst, vl);
	else if (lst->spec == 's' || lst->spec == 'S')
		(lst->spec == 's' && !lst->md_l) ? ft_strprnt(lst, vl)
		: ft_wstrprnt(lst, vl);
	else if (lst->spec == '%')
		ft_printff(lst);
	else
		ft_other(lst);
}

void	start_prog(va_list *vlst, t_lst *lst, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] == '%')
			i++;
		else if (s[i] == '%')
		{
			i++;
			start_cycle(&i, s, lst, vlst);
			cleanstruct(lst);
			(s[i]) ? i++ : 0;
			continue ;
		}
		ft_putchar(s[i++]);
		lst->length += 1;
	}
}

int		ft_printf(char *format, ...)
{
	va_list	vlst;
	t_lst	lst;

	lst = fillstruct();
	va_start(vlst, format);
	if (ft_strlen(format))
	{
		start_prog(&vlst, &lst, format);
	}
	va_end(vlst);
	return (lst.length);
}
