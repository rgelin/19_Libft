/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 21:27:01 by rgelin            #+#    #+#             */
/*   Updated: 2020/11/23 13:25:40 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int      nb_words(char *str, char c)
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

static int		*size_words(char *str, char c)
{
	int i;
	int j;
	int count;
	int *size_words;

	j = 0;
	i = 0;
	if (!(size_words = malloc(sizeof(int) * (nb_words(str, c)))))
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
		{
			count = 0;
			j++;
			i++;
		}
		while(str[i] != c && str[i])
		{
			count++;
			i++;
		}
		size_words[j] = count;
	}
	return (size_words);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		index;
	int		j;
	char	**res;
	char	*str;
	int		*size;

	str = (char *)s;
	size= size_words(str, c);
	i = 0;
	index = 0;
	if (!(res = malloc(sizeof(char*) * (nb_words(str, c) + 1)))
		|| !str[0])
		return (0);
	while (index < nb_words(str, c))
	{
		j = 0;
		if (!(res[index] = malloc(sizeof(char) * size[index] + 1)))
			return (NULL);
		if (str[i] && str[i] == c)
			i++;
		while (str[i] && str[i] != c)
			res[index][j++] = str[i++];
		res[index][j] = '\0';
		index++;
	}
	res[index] = 0;
	return (res);
}