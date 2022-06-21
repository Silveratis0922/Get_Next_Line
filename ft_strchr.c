/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:03:55 by tchantro          #+#    #+#             */
/*   Updated: 2022/06/21 13:45:57 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

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
/*
int	main(void)
{
	const char	lit[] = "Ploum Ploum";

	printf("%s\n", strchr(lit, 'P' + 256));
	return (0);
}*/
