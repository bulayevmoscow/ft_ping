/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 22:23:53 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/11/02 19:48:29 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				gnl_check(char **str, char **ln)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = *str;
	while (tmp[i] != '\n')
	{
		if (!(tmp[i++]))
			return (0);
	}
	tmp[i] = '\0';
	*ln = ft_strdup(*str);
	*str = ft_strdup(&tmp[i] + 1);
	free(tmp);
	return (1);
}

int				gnl_read(int fd, char **str, char *tmp, char **ln)
{
	int		i;
	char	*tmp_str;

	while ((i = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[i] = '\0';
		if (*str)
		{
			tmp_str = *str;
			*str = ft_strjoin(tmp_str, tmp);
			free(tmp_str);
			tmp_str = NULL;
		}
		else
			*str = ft_strdup(tmp);
		if (gnl_check(str, ln))
			break ;
	}
	return ((i > 0) ? 1 : 0);
}

int				get_next_line(int const fd, char **line)
{
	int			i;
	static char	*stack[1024];
	char		*tmp;

	if ((fd < 0 || fd > 1024) || !line || (read(fd, stack[fd], 0) < 0))
		return (-1);
	if (stack[fd] && (gnl_check(&stack[fd], line)))
		return (1);
	if (!(tmp = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	i = gnl_read(fd, &stack[fd], tmp, line);
	free(tmp);
	if (i != 0 || stack[fd] == NULL || stack[fd][0] == '\0')
	{
		if (!i && *line)
			*line = NULL;
		return (i);
	}
	*line = stack[fd];
	stack[fd] = NULL;
	return (1);
}
