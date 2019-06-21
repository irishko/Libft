/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irishko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 20:27:17 by irishko           #+#    #+#             */
/*   Updated: 2017/12/13 20:27:19 by irishko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int i;

	i = 2;
	while (i <= (nb / 2))
	{
		if (!(nb % i))
			return (0);
		i++;
	}
	if (nb < 2)
		return (0);
	return (1);
}
