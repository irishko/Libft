/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irishko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 20:42:05 by irishko           #+#    #+#             */
/*   Updated: 2017/12/06 20:42:06 by irishko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	coun(char const *p, char f)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	while (p[i] && p[i] == f)
		i++;
	while (p[i])
	{
		count++;
		while (p[i] && p[i] != f)
			i++;
		while (p[i] && p[i] == f)
			i++;
	}
	return (count);
}

static char		*takeword(char const *s, char d)
{
	int		i;
	int		n;
	char	*res;

	i = 0;
	while (s[i] != d && s[i])
		i++;
	if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	n = i++;
	while (i--)
		res[n - i] = s[n - i];
	res[n] = '\0';
	return (res);
}

static char		**check(char **p)
{
	if (!(p = (char **)malloc(sizeof(char *) * 1)))
		return (0);
	p[0] = NULL;
	return (p);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		k;
	int		word;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	word = coun(s, c);
	if (!(str = (char **)malloc(sizeof(char *) * (word + 1))))
		return (NULL);
	if (word == 0)
		return (check(str));
	while (word--)
	{
		while (s[i] == c && s[i])
			i++;
		str[k++] = takeword(&s[i], c);
		while (s[i] && s[i] != c)
			i++;
	}
	str[k] = NULL;
	return (str);
}
