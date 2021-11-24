/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 03:01:30 by iel-mach          #+#    #+#             */
/*   Updated: 2021/11/24 03:10:34 by iel-mach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_before_line(char *s)
{
	int	i;

	if (!s[0])
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (ft_substr(s, 0, i + 1));
}

char	*ft_after_line(char *s)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '\n')
		{
			str = ft_substr(s, i + 1, ft_strlen(s));
			free (s);
			return (str);
		}
		i++;
	}
	free (s);
	return (NULL);
}

char	*ft_getline(int fd, char *a)
{
	char	*str;
	int		t;

	str = malloc (BUFFER_SIZE + 1);
	t = 1;
	while (!check_line(a) && t)
	{
		t = read(fd, str,BUFFER_SIZE);
		if (t == -1)
		{
			free(str);
			return (NULL);
		}
		str[t] = '\0';
		a = ft_strjoin(a, str);	
	}
	free(str);
	return (a);
}

char	*get_next_line(int fd)
{
	static char	*red[10240];
	char		*l;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	red[fd] = ft_getline(fd, red[fd]);
	if (!red[fd])
		return (NULL);
	l = ft_before_line (red[fd]);
	red[fd] = ft_after_line(red[fd]);
	return (l);
}