/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitran <pitran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:24:30 by pitran            #+#    #+#             */
/*   Updated: 2024/12/18 17:33:18 by pitran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char    *ft_strchr(const char s, int c)
{
    while((s))
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if (c == '\0')
        return ((char *)s);
    return (NULL);
}

void    *ft_memset(void *s, int c, size_t n)
{
    unsigned char   *ptr;
    size_t          i;

    ptr = (unsigned char *)s;
    i = 0;
    while (i < n)
    {
        ptr[i] = (unsigned char)c;
        i++;
    }
    return (s);
}

size_t  ft_strlen(char *str)
{
    size_t  i;
    i = 0;

    if(!str)
        return(0);
    while(str[i])
        i++;
    return i;
}

char    *ft_strdup(char *s)
{
    size_t  i;
    size_t  j;
    size_t  size;
    char    *dup;

    if (!s)
        return(NULL);

    size = ft_strlen(s);

    dup = (char *)malloc(sizeof(char) * (size + 1));
    if (!dup)
        return(NULL);
    i = 0;
    j = 0;
    while (s[i])
        dup[i++] = s[j++];
    dup[i] = '\0';
    return (dup);
}

char    *ft_substr(char *str, unsigned int start, size_t len)
{
    size_t  i;
    char    *substr;

    i = 0;
    if(!str)
        return(NULL);
    substr = (char *)malloc(sizeof(char) * (len + 1));
    if (!substr)
        return(NULL);
    while (str[start] && start < len)
        substr[i++] = str[start++];
    substr[i] = '\0';
    return(substr);
}

char    *ft_strjoin(char *base, char *append)
{
    size_t  i;
    size_t  j;
    char    *joint;
    
    if(!base || !append)
        return(!base ? ft_strdup(append) : ft_strdup(base));
    joint = malloc(sizeof(char) * (ft_strlen(base) + ft_strlen(append) + 1));
    if (!joint)
        return(NULL);
    i = -1;
    j = -1;
    while (base[++i])
        joint[i] = base[i];
    while (append[++j])
        joint[i + j] = append[j];
    joint[i + j] = '\0';
    return(joint);
}