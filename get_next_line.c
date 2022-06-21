/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:58:08 by tchantro          #+#    #+#             */
/*   Updated: 2022/06/21 17:01:37 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
        int     i;

        i = 0;
	if (str == NULL)
		return (0);
        while (str[i])
                i++;
        return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] == s2[j])
	{
		if ((s1[i] && s2[j]) == '\0')
			return (0);
		i++;
		j++;
	}
	return (s1[i] - s2[j]);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i + 1);
		i++;
	}
	return (NULL);
}

char	*ft_strdupchr(const char *s, int c)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != c)
		i++;
	dest = malloc(sizeof (char) * i + 2);
	if (!dest)
		return (0);
	while (j < i + 1)
	{
		dest[j] = s[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		a;
	char	*str;

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
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;
	int		j;

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

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;
	size_t		i;

	i = 0;
	str = (void *)s;
	if (c == 0 && n == 0)
		return (0);
	while (i < n)
	{
		if (str[i] == (char)c)
			return ((void *)str + i);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*stash;
	char		*line;
	int		i;
	
	i = 1;	
	while (ft_memchr(stash, '\n', ft_strlen(stash)) == NULL && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);	
		buff[i] = '\0';
		printf("%d\n", i);
		if (stash == NULL)
			stash = ft_strdup(buff);
		else
			stash = ft_strjoin(stash, buff);
	}
	line = ft_strdupchr(stash, '\n');
	if (ft_strcmp(stash, line) != 0)
		stash = ft_strchr(stash, '\n');
	else
		free(stash);
	return (line);	
}

int	main()
{
	int        fd;
	char    *str;
	int        i;

	i = 0;
	fd = open("test", O_RDONLY);
	if (fd == -1)
		return (1);
	while (i++ < 5)
	{
		str = get_next_line(fd);
		printf("%s", str);
	if (str == NULL)
		break ;
	free(str);
	}    
	close(fd);
	return (0);
}
