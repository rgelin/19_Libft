/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgelin <rgelin@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:54:07 by rgelin            #+#    #+#             */
/*   Updated: 2020/11/23 13:15:28 by rgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void     rev_tab(char *tab, int neg)
{
	int     i;
	char    t;
	int     len;

	i = 0;
	len = ft_strlen(tab);
	while (i < len / 2)
	{
		t = tab[i + neg];
		tab[i + neg] = tab[len - 1 - i];
		tab[len - 1 - i] = t;
		i++;
	}

}

static int  size_nb(int nb)
{
	int count;

	count = 0;
	if (nb < 0)
	{
		count = 1;
		nb = -nb;
	}
	while (nb % 10 != 0)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

char    *ft_test(int nb)
{
	char    *res;
	int     sign;
	int     i;
	long    n;

	sign = 0;
	i = 0;
	n = nb;
	if (!(res = malloc(sizeof(char) * size_nb(n) + 1)))
		return (NULL);
	if (n < 0)
	{
		res[i++] = '-';
		n = -n;
		sign = 1;
	}
	if (n == 0)
	{
		res[0] = 0 + '0';
		return (res);
	}
	while (n > 0)
	{
		res[i++] = n % 10 + '0';
		n /= 10;
	}
	res[i] = 0;
	rev_tab(res, sign);
	return (res);
}
