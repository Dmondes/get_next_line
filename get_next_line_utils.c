#include "get_next_line.h"

size_t ft_strlen(const char *str)
{
    size_t len;

    len = 0;
    while (str[len])
        len++;
    return (len);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    char    *result;
    size_t  i;
    size_t  j;

    if (!s1 || !s2)
        return (NULL);
    result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!result)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        result[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j])
    {
        result[i + j] = s2[j];
        j++;
    }
    result[i + j] = '\0';
    return (result);
}

char *ft_strdup(const char *s)
{
    char    *str;
    size_t  len;
    size_t  i;

    len = ft_strlen(s);
    str = (char *)malloc(len + 1);
    if (!str)
        return (NULL);
    i = 0;
    while (i < len)
    {
        str[i] = s[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
