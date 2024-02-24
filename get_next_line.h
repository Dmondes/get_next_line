/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:06:38 by delim             #+#    #+#             */
/*   Updated: 2024/02/24 17:45:47 by delim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_strlen(const char *s);
char	*ft_strdup(char *src);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char const *s, int start, int len);
char	*get_next_line(int fd);
void	*ft_memmove(void *dest, const void *src, int n);
#endif
