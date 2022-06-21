/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:45:26 by tchantro          #+#    #+#             */
/*   Updated: 2022/06/21 13:48:35 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

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
