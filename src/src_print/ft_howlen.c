/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_howlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irishko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 17:44:27 by irishko           #+#    #+#             */
/*   Updated: 2018/06/29 17:44:30 by irishko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_howlen(t_lst *ls, int skoko)
{
	if (ls->negnum)
		;
	else if (ls->flg_plus)
		;
	else if (ls->flg_space)
		;
	else
		return ;
	(ls->width < skoko || ls->width < ls->precision) ? ls->length++ : 0;
}
