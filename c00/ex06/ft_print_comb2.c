/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andteixe <andteixe@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:57:19 by andteixe          #+#    #+#             */
/*   Updated: 2024/01/15 22:34:45 by andteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(int i, int j)
{
	int	k;
	int	l;

	k = i;
	while (k <= '9')
	{
		if (k == i)
			l = j + 1;
		else
			l = '0';
		while (l <= '9')
		{
			write(1, &i, 1);
			write(1, &j, 1);
			write(1, " ", 1);
			write(1, &k, 1);
			write(1, &l, 1);
			if (!(i == '9' && j == '8' && k == '9' && l == '9'))
				write(1, ", ", 2);
			l++;
		}
		k++;
	}
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = '0';
	while (i <= '9')
	{
		j = '0';
		while (j <= '9')
		{
			ft_print_comb(i, j);
			j++;
		}
		i++;
	}
}
/*
int	main(void)
{
	ft_print_comb2();
	return (0);
}
*/
