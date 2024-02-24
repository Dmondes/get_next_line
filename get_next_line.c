/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:06:38 by delim             #+#    #+#             */
/*   Updated: 2024/02/24 17:55:26 by delim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*nl_point;
	char	*line;
	int		bytes_read;
	int		len;
	int		remainder;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	nl_point = ft_strchr(buffer, '\n');
	if (nl_point != NULL)
	{
		len = nl_point - buffer + 1;
		line = ft_substr(buffer, 0, len);
		remainder = bytes_read - len;
		ft_memmove(buffer, nl_point + 1, remainder);
	}
	else
		line = NULL;
	return (line);
}

int	main(void)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open("filename.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Open file Error");
		return (1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		count ++;
		printf("[%d]:%s\n", count, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	line = NULL;
	close(fd);
	return (0);
}
