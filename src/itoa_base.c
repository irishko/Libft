/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irishko <irishko@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 21:24:07 by irishko           #+#    #+#             */
/*   Updated: 2019/02/18 21:24:09 by irishko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	conv_nb(size_t i)
{
	if (10 <= i)
		return (i - 10 + 'a');
	else
		return (i + '0');
}

char			*itoa_base(ssize_t i, size_t base)
{
	int		len;
	char	*str;
	size_t	j;

	len = 0;
	j = (size_t)i;
	while (j >= base)
	{
		j = j / base;
		len++;
	}
	if (!(str = ft_strnew((size_t)len)))
		return (NULL);
	str[len + 1] = '\0';
	while (len >= 0)
	{
		j = i % base;
		str[len] = (char)conv_nb(j);
		i /= base;
		len--;
	}
	return (str);
}

static size_t	ft_size(ssize_t n)
{
	size_t	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa_d(ssize_t n)
{
	ssize_t					len;
	char					*str;
	unsigned long long int	k;

	len = ft_size(n);
	k = n;
	if (k == 0)
		return (ft_strsub("0", 0, 1));
	if (n < 0)
	{
		k = -n;
		len++;
	}
	if (!(str = ft_strnew((size_t)len)))
		return (NULL);
	str[--len] = (char)(k % 10 + '0');
	while (k /= 10)
		str[--len] = (char)(k % 10 + '0');
	if (n < 0)
		*(str + 0) = '-';
	if (k - 1 == 9223372036854775807)
		return ("-9223372036854775808\0");
	return (str);
}

ssize_t			ft_atoi_x(const char *str)
{
	int					i;
	ssize_t				result;
	int					is_neg;

	i = 0;
	result = 0;
	while (ft_isspace(*str))
		str++;
	is_neg = (*str == '-');
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str++ - '0';
		i++;
		if (result >= 9223372036854775807 && is_neg == 0)
			return (-1);
		if (result > 9223372036854775807 && is_neg == 1)
			return (0);
	}
	return (is_neg ? -result : result);
}
