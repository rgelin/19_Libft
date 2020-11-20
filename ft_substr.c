/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:18:03 by rgelin            #+#    #+#             */
/*   Updated: 2020/11/20 15:27:32 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;
	char	*str;

	i = 0;
	str = (char *)s;
	if (s == 0 || len == 0)
		return (0);
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start >= ft_strlen(s))
	{
		if (!(res = malloc(sizeof(char) * 1)))
			return (NULL);
		res[0] = 0;
		return (res);
	}
	while (i < len)
	{
		res[i] = str[start + i];
		i++;
	}
	res[i] = 0;
	return (res);
}
