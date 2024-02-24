/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:05:05 by delim             #+#    #+#             */
/*   Updated: 2024/02/24 17:41:11 by delim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	ch;

	i = 0;
	ch = c;
	while (s[i])
	{
		if (s[i] == ch)
			return (&s[i]);
		i++;
	}
	if (ch == '\0')
		return (&s[i]);
	return (NULL);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*point;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(src) + 1;
	point = (char *)malloc(sizeof(char) * len);
	if (!point)
		return (NULL);
	while (src[i])
	{
		point[i] = src[i];
		i ++;
	}
	point[i] = '\0';
	return (point);
}

char	*ft_substr(char const *s, int start, int len)
{
	char	*new_str;
	int		i;
	int		s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (!s)
		return (NULL);
	if (start + len > s_len)
		len = s_len - start;
	new_str = (char *)malloc(len + 1);
	if (!new_str)
		return (NULL);
	while (i < len && s[start + i])
	{
		new_str[i] = s[start + i];
		i ++;
	}
	new_str[i] = '\0';
	return (new_str);
}

void	*ft_memmove(void *dest, const void *src, int n)
{
	int	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	if (dest > src)
	{
		i = n;
		while (i > 0)
		{
			((unsigned char *)dest)[i - 1] = ((unsigned char *)src)[i - 1];
			i--;
		}
	}
	else
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
