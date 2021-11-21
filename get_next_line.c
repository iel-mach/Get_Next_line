/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 22:48:27 by iel-mach          #+#    #+#             */
/*   Updated: 2021/11/21 19:40:29 by iel-mach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	chtaibi_line(char *s)
{
	int i;
	i = 0;
	while(str[i])
	{
		if(str[i] == '\n')
			return(1);
		i++;
	}
	return(0);
}
char	*getline(int fd, char *a)
{
	char *str;
	int t;
	str = malloc(BUFFER_SIZE + 1);
	t = 1;
	while(!chtaibi_line(str) && t)
	{
		t = read(fd, str,BUFFER_SIZE);
		if (t == -1)
		{
			free(str);
			return(NULL);
		}
		str[t] = '\0';
		a = ft_strjoin(a,str);
		
	}
	free(str);
	return(a);
}
char	*get_next_line(int fd)
{
	static char *str;
	char *l;
	
}