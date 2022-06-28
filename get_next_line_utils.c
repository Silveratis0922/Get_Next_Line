/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:58:08 by tchantro          #+#    #+#             */
/*   Updated: 2022/06/28 00:09:10 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     ft_strlen(char *str)
{
        int     i;

        i = 0;
        if (str == NULL)
                return (0);
        while (str[i])
                i++;
        return(i);
}

char    *ft_strdup(char *s)
{
        char    *dest;
        int             i;
        int             j;

        i = ft_strlen(s);
        j = 0;
        dest = malloc(sizeof (char) * i + 1);
        if (!dest)
                return (0);
        while (j < i)
        {
                dest[j] = s[j];
                j++;
        }
        dest[j] = '\0';
        return (dest);
}

char    *ft_strjoin(char *s1, char *s2)
{
        int             i;
        int             j;
        int             a;
        char    *str;

        i = ft_strlen(s1);
        j = ft_strlen(s2);
        a = 0;
        str = malloc(sizeof (char) * (i + j) + 1);
        if (!str)
                return (0);
        i = 0;
        while (s1[i])
                str[a++] = s1[i++];
        j = 0;
        while (s2[j])
                str[a++] = s2[j++];
        str[a] = '\0';
	free(s1);
        return (str);
}

char    *ft_substr(char *s, unsigned int start, size_t len)
{
        char                    *str;
        unsigned int    i;
        unsigned int    j;

        i = 0;
        j = ft_strlen(s);
        if (len > (j - start))
                str = malloc(sizeof (char) * (j - start) + 1);
        else
                str = malloc(sizeof (char) * len + 1);
        if (!str)
                return (NULL);
        while (s[start] && i < len)
        {
                str[i] = s[start];
                start++;
                i++;
        }
        str[i] = '\0';
        free(s);
        return (str);
}

