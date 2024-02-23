#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

void    *ft_calloc(int count, int size);
int             ft_strlen(const char *s);
char    *ft_strchr(char *s, int c);
char    *ft_strdup(char *src);
char    *ft_substr(char const *s, int start, int len);
char    *get_next_line(int fd);
#endif

