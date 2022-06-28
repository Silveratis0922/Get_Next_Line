/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:00:34 by tchantro          #+#    #+#             */
/*   Updated: 2022/06/28 04:08:49 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_gnlen(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if (str == NULL)
		return (0);
	while (str[i++] != '\n')
	{
		if ( i > len)
			return (0);
	}
	return (i);
}

char	*ft_strndup(char *s, int size)
{
	char	*dest;
	int		j;

	j = 0;
	dest = malloc(sizeof (char) * size + 1);
	if (!dest)
		return (0);
	while (j < size)
	{
		dest[j] = s[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*gnl_bis(char *buff, char *stash, int i, int fd)
{
	while (ft_gnlen(stash) == 0 && i != 0)
        {
                i = read(fd, buff, BUFFER_SIZE);
                buff[i] = '\0';
                if (i <= 0 && stash == NULL)
                        return (NULL);
                else if (i <= 0 && stash != NULL)
                        break ;
                else
                {
                        if (stash == NULL)
                                stash = ft_strdup(buff);
                        else
                                stash = ft_strjoin(stash, buff);
                }
        }
	return (stash);
}

/*char	*return_value(char **stash, char *line)
{
	line = ft_strdup(*stash);
	free(*stash);
	*stash = NULL;
	return (line);
}*/

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*stash;
	char		*line;
	int		i;
	int		len;

	i = 1;
	if (fd == -1 || fd > 1024 || BUFFER_SIZE == 0)
		return (NULL);
	stash = gnl_bis(buff, stash, i, fd);
	if (stash == NULL)
		return (NULL);
	len = ft_gnlen(stash);
	if (ft_strlen(stash) == len || len == 0)
		//return (return_value(&stash, line));
	{
		line = ft_strdup(stash);
		free(stash);
		stash = NULL;
	}
	else
	{
		line = ft_strndup(stash, len);
		stash = ft_substr(stash, len, ft_strlen(stash) - len);
	}
	return (line);
}
/*
int	main()
{
	int        fd;
	char    *str;
	int        i;

	i = 0;
	fd = open("test", O_RDONLY);
	if (fd == -1)
		return (1);
	while (i++ < 28)
	{
		str = get_next_line(fd);
		printf("%s", str);
//		if (str == NULL)
//			break ;
		free(str);
	} 
	close(fd);
	return (0);
}*/
