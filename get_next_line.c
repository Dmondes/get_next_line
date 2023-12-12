#include "get_next_line.h"

#define BUFFER_SIZE 32

static char *ft_strchr(const char *s, int c)
{
    while (*s != c)
    {
        if (!*s)
            return (NULL);
        s++;
    }
    return ((char *)s);
}

static char *extract_line(char **saved, int fd)
{
    char    *temp;
    char    *line;
    char    *newline_pos;

    if (!saved[fd] || *saved[fd] == '\0')
        return (NULL);
    newline_pos = ft_strchr(saved[fd], '\n');
    if (newline_pos)
    {
        *newline_pos = '\0';
        line = ft_strdup(saved[fd]);
        temp = ft_strdup(newline_pos + 1);
        free(saved[fd]);
        saved[fd] = temp;
    }
    else
    {
        line = ft_strdup(saved[fd]);
        free(saved[fd]);
        saved[fd] = NULL;
    }
    return (line);
}

static int read_line(int fd, char **saved)
{
    char    buffer[BUFFER_SIZE + 1];
    int     bytes_read;
    char    *temp;

    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read == -1)
        return (-1);
    buffer[bytes_read] = '\0';
    if (!saved[fd])
        saved[fd] = ft_strdup("");
    temp = ft_strjoin(saved[fd], buffer);
    free(saved[fd]);
    saved[fd] = temp;
    return (bytes_read);
}

char *get_next_line(int fd)
{
    static char *saved[256];

    if (fd < 0 || fd > 255 || BUFFER_SIZE <= 0)
        return (NULL);
    while (1)
    {
        if (read_line(fd, saved) == -1)
            return (NULL);
        if (ft_strchr(saved[fd], '\n') || (!ft_strchr(saved[fd], '\n') && !saved[fd][0]))
            return (extract_line(saved, fd));
    }
}
