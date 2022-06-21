/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:45:26 by tchantro          #+#    #+#             */
/*   Updated: 2022/05/13 14:38:13 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

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
