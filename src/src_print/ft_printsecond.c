/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printsecond.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irishko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 18:38:22 by irishko           #+#    #+#             */
/*   Updated: 2018/06/26 18:38:23 by irishko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	spec_flag(int *i, char *src, t_lst *spec)
{
	if (*src == '-')
		spec->flg_minus = 1;
	else if (*src == '+')
		spec->flg_plus = 1;
	else if (*src == ' ')
		spec->flg_space = 1;
	else if (*src == '#')
		spec->flg_lattice = 1;
	else if (*src == '0')
		spec->flg_zero = 1;
	(*i)++;
}

static void	spec_width(int *i, char *src, t_lst *sp)
{
	sp->width = ft_atoi(&src[*i]);
	while (ft_isdigit(src[*i]))
		(*i)++;
}

static void	spec_precision(int *i, char *st, t_lst *pr)
{
	(*i)++;
	pr->point = 1;
	pr->precision = ft_atoi(&st[*i]);
	while (ft_isdigit(st[*i]))
		(*i)++;
}

static void	spec_mod(int *i, char *ser, t_lst *mod)
{
	if (ser[*i] == 'h')
		if (ser[*i + 1] == 'h')
		{
			(*i)++;
			mod->md_hh = 1;
		}
		else
			mod->md_h = 1;
	else if (ser[*i] == 'l')
		if (ser[*i + 1] == 'l')
		{
			(*i)++;
			mod->md_ll = 1;
		}
		else
			mod->md_l = 1;
	else if (ser[*i] == 'j')
		mod->md_j = 1;
	else if (ser[*i] == 'z')
		mod->md_z = 1;
	(*i)++;
}

void		start_cycle(int *i, char *s, t_lst *lst, va_list *vlst)
{
	while (s[*i])
	{
		if (s[*i] == '-' || s[*i] == '+' || s[*i] == ' ' || s[*i] == '#'\
		|| s[*i] == '0')
			spec_flag(i, &s[*i], lst);
		else if (ft_isdigit(s[*i]) && *s != '0')
			spec_width(i, s, lst);
		else if (s[*i] == '.')
			spec_precision(i, s, lst);
		else if (s[*i] == 'h' || s[*i] == 'l' || s[*i] == 'j' || s[*i] == 'z')
			spec_mod(i, s, lst);
		else
		{
			lst->spec = s[*i];
			second_prog(lst, vlst);
			break ;
		}
	}
}
