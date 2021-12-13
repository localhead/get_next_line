/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbagg <mbagg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 19:39:08 by mbagg             #+#    #+#             */
/*   Updated: 2021/11/21 19:34:43 by mbagg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_basic_rec(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*str;
	int		b;

	b = read(fd, buffer, BUFFER_SIZE);
	if (b <= 0)
		return (NULL);
	buffer[b] = '\0';
	str = ft_strdup(buffer);
	return (str);
}

static void	ft_mid_rec(char **tmp_line, int fd)
{
	char	*temp;
	char	*str;

	while (ft_strchr(*tmp_line, '\n') == 0)
	{
		str = ft_basic_rec(fd);
		temp = *tmp_line;
		if (str == 0)
			break ;
		else
			*tmp_line = ft_strjoin(*tmp_line, str);
		free (temp);
		free (str);
	}
}

static char	*ft_final_rec(char **tmp_line)
{
	char	*flag;
	char	*str;
	char	*temp;

	if (ft_strlen(*tmp_line) == 0)
	{
		free(*tmp_line);
		*tmp_line = NULL;
		return (NULL);
	}
	flag = ft_strchr(*tmp_line, '\n');
	if (flag == 0)
	{
		str = ft_strdup(*tmp_line);
		free(*tmp_line);
		*tmp_line = NULL;
		return (str);
	}
	*flag = '\0';
	str = ft_strjoin(*tmp_line, "\n");
	flag++;
	temp = *tmp_line;
	*tmp_line = ft_strdup(flag);
	free(temp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*tmp_line;
	char		*res_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (tmp_line == 0)
	{
		tmp_line = ft_basic_rec(fd);
		if (tmp_line == 0)
			return (NULL);
	}
	ft_mid_rec(&tmp_line, fd);
	res_line = ft_final_rec(&tmp_line);
	return (res_line);
}
