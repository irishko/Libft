/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irishko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:46:42 by irishko           #+#    #+#             */
/*   Updated: 2017/11/07 21:51:45 by irishko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static size_t			copyuntil(char **dst, char *src)
{
	size_t		i;

	i = -1;
	while (src[++i] != '\n')
		if (src[i] == '\0')
			break ;
	if (!(*dst = ft_strsub(src, 0, i)))
		return (0);
	return (i);
}

static t_list			*get_file(t_list **file, int fd, size_t *ter,\
char *ssr)
{
	t_list				*tmp;
	char				bf[BUFF_SIZE + 1];

	tmp = *file;
	while (tmp)
		if ((int)tmp->content_size == fd)
			break ;
		else
			tmp = tmp->next;
	if (!tmp)
	{
		tmp = ft_lstnew("\0", fd);
		ft_lstadd(file, tmp);
		tmp = *file;
	}
	while ((*ter = read(fd, bf, BUFF_SIZE)))
	{
		bf[*ter] = '\0';
		ssr = tmp->content;
		tmp->content = ft_strjoin(ssr, bf);
		free(ssr);
		if (ft_strchr(tmp->content, '\n') || !*ter)
			break ;
	}
	return (tmp);
}

int						get_next_line(const int fd, char **line)
{
	char				buf[BUFF_SIZE + 1];
	static t_list		*file;
	char				*tmp;
	size_t				ret;
	t_list				*curr;

	ret = 0;
	tmp = NULL;
	if ((fd < 0 || line == NULL || BUFF_SIZE < 1 || BUFF_SIZE > 10000000
	|| read(fd, buf, 0) < 0))
		return (-1);
	curr = get_file(&file, fd, &ret, tmp);
	if (ret < BUFF_SIZE && !ft_strlen(curr->content) && ((*line = NULL) || 1))
		return (0);
	tmp = curr->content;
	ret = copyuntil(line, tmp);
	if (ret < ft_strlen(curr->content))
		curr->content = ft_strdup(&curr->content[ret + 1]);
	else
		curr->content = ft_strdup(&curr->content[ret]);
	free(tmp);
	return (1);
}
