/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-mach <iel-mach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 22:50:16 by iel-mach          #+#    #+#             */
/*   Updated: 2021/11/24 02:12:07 by iel-mach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		ft_strlen( char *s);
char	*ft_strjoin(char 	*s1, char 	*s2);
char	*get_next_line(int fd);
char	*ft_substr(char  *s, int start, int len);
int		check_line(char *s);
char	*ft_getline(int fd, char *a);
char	*ft_after_line(char *s);
char	*ft_before_line(char *s);
#endif