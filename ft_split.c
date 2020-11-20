/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:34:58 by rgelin            #+#    #+#             */
/*   Updated: 2020/11/20 17:46:29 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nb_words(char *str, char c)
{
	int i;
	int nb_words;

	i = 0;
	nb_words = 0;
	if (str[0] != c)
		nb_words = 1;
	while (str[i])
	{
		if (str[i] == c)
			nb_words++;
		i++;
	}
	return (nb_words);
}

char	**ft_split(char const *s, char c)
{
	
	while (s[i] == c)
		i++;
}
