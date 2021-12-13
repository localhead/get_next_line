/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbagg <mbagg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:42:26 by mbagg             #+#    #+#             */
/*   Updated: 2021/11/16 22:06:26 by mbagg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*sht;
	int		i;
	int		sz;

	i = 0;
	sz = 0;
	while (str[sz])
		sz++;
	sht = malloc(sizeof(char) * (sz + 1));
	if (!sht)
		return ((void *)0);
	while (str[i])
	{
		sht[i] = str[i];
		i++;
	}
	sht[i] = '\0';
	return (sht);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*re;
	unsigned int	i;
	unsigned int	total;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	total = ft_strlen((char *)s1) + ft_strlen ((char *)s2);
	re = (char *)malloc(sizeof(*re) * (total + 1));
	if (!re)
		return ((void *)0);
	while (*s1 != '\0')
		re[i++] = *s1++;
	while (*s2 != '\0')
		re[i++] = *s2++;
	re[i] = '\0';
	return (re);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == 0)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
