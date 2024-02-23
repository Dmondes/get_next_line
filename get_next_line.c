#include "get_next_line.h"

char    *get_next_line(int fd)
{
        int             bytes_read;
        char    buffer[BUFFER_SIZE];
        char    *line;
        char    *nl_pointer;

        if (fd < 0 || BUFFER_SIZE <= 0)
                return (0);
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
                return (NULL);
        buffer[bytes_read] = '\0';
        nl_pointer = ft_strchr(buffer, '\n');
        if (!nl_pointer)
        {
                line = ft_strdup(buffer);
                return (line);
        }
        line = ft_substr(buffer, 0, nl_pointer - buffer);
        if (!line)
                return (NULL);
        return (line);
}
