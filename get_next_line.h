/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbagg <mbagg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 22:44:06 by mbagg             #+#    #+#             */
/*   Updated: 2021/11/21 19:36:47 by mbagg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h> 
# include <stdlib.h>
# include <string.h>

char	*get_next_line(int fd);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *src);
char	*ft_strchr(const char *s, int c);
void	ft_strclr(char *s);
char	*ft_strcpy(char *dest, char *src);

#endif
