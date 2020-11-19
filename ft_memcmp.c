/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:02:54 by rgelin            #+#    #+#             */
/*   Updated: 2020/11/19 16:19:08 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*a;
	char	*b;
	size_t	i;

	i = 0;
	a = (char *)s1;
	b = (char *)s2;
	while (i < n)
	{
		if (a[i] != b[i])
			return (((unsigned char *)a)[i] - ((unsigned char *)b)[i]);
		i++;
	}
	return (0);
}
