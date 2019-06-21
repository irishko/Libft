/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irishko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:41:24 by irishko           #+#    #+#             */
/*   Updated: 2018/05/30 20:43:30 by irishko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <wchar.h>
# include <locale.h>

typedef struct		s_lst
{
	int		negnum;
	char	spec;
	int		flg_minus;
	int		flg_plus;
	int		flg_space;
	int		flg_lattice;
	int		flg_zero;
	int		width;
	int		precision;
	int		md_h;
	int		md_hh;
	int		md_l;
	int		md_ll;
	int		md_j;
	int		md_z;
	int		point;
	int		length;
}					t_lst;

int					ft_printf(char *format, ...);
void				second_prog(t_lst *lst, va_list *vl);
void				start_cycle(int *i, char *s, t_lst *lst, va_list *vlst);
void				ft_intprt(t_lst *ls, va_list *vl);
void				ft_unsig(t_lst *ls, va_list *vlt);
unsigned long long	typeunsig_mod(t_lst *ls, va_list *vl);
int					ft_howunsnbr(unsigned long long n);
void				ft_hexade(t_lst *ls, va_list *vl);
int					hexnbr(unsigned long long hexkex, int hex);
int					howbits(wint_t ch);
int					ft_hownbr(intmax_t n, t_lst *ls);
void				ft_putnbrin(long long n);
void				ft_putnbrhex(unsigned long long hexkex, int hex, t_lst *ls);
void				ft_point(t_lst *ls, va_list *vl);
void				ft_charprnt(t_lst *ls, va_list *vl);
void				ft_wchar(t_lst *ls, va_list *vl);
void				ft_putwchar(wint_t wch);
int					how_width(wint_t wch);
void				ft_strprnt(t_lst *ls, va_list *vl);
void				ft_wstrprnt(t_lst *ls, va_list *vl);
size_t				ft_strlen(const char *str);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
void				ft_putchar(char c);
void				ft_printff(t_lst *ls);
void				ft_zero_x(t_lst *ls, unsigned long long *chis);
void				ft_other(t_lst *ls);
void				ft_putnull(t_lst *ls);
void				ft_zero_space(t_lst *ls, int kol);
void				ft_howlen(t_lst *ls, int skoko);

#endif
