/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:21:57 by tchantro          #+#    #+#             */
/*   Updated: 2022/06/21 15:00:25 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETNEXTLINE_H
# define GETNEXTLINE_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <fcntl.h>

char	*get_next_line(int fd);

#endif
