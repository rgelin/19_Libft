/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 21:27:01 by rgelin            #+#    #+#             */
/*   Updated: 2020/11/27 13:03:52 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(char const *str, char c)
{
	int i;
	int nb_words;

	i = 1;
	nb_words = 0;
	if (str[1] != c)
		nb_words = 1;
	while (str[i])
	{
		if (str[i - 1] == c && str[i] != c)
			nb_words++;
		i++;
	}
	return (nb_words);
}

static char		**malloc_error(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static char		**fill_tab(char const *str, char c, char **res)
{
	int		i;
	int		index;
	int		j;
	int		nb_words;

	i = 0;
	index = 0;
	nb_words = count_words(str, c);
	while (index < nb_words)
	{
		j = 0;
		if (!(res[index] = malloc(sizeof(char) * (ft_strlen(str)))))
			return (malloc_error(res));
		while (str[i] && str[i] == c)
			i++;
		while (str[i] && str[i] != c)
			res[index][j++] = str[i++];
		res[index][j] = '\0';
		index++;
	}
	res[index] = NULL;
	return (res);
}

char			**ft_split(char const *s, char c)
{
	char	**res;
	int		nb_words;

	if (!s || !c)
		return (NULL);
	nb_words = count_words(s, c);
	if (!(res = malloc(sizeof(char *) * (nb_words + 1))))
		return (NULL);
	res = fill_tab(s, c, res);
	return (res);
}
