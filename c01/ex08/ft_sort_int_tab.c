/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andteixe <andteixe@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:45:14 by andteixe          #+#    #+#             */
/*   Updated: 2024/01/16 18:47:47 by andteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *n1, int *n2)
{
	int	temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;

	if (size == 1)
		return ;
	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			ft_swap(&tab[i], &tab[i + 1]);
		}
		i++;
	}
	ft_sort_int_tab(tab, size - 1);
}

/*
int	main(void)
{
	int i = 0;
	//int x[] = {1,2,3,4,5};
	int x[] = {5, 3, 7, -25, 1, 2, -5};
	int s = 7;
	
	ft_sort_int_tab(x, s);
	while (i < 7)
	{
		printf("%d", x[i]);
		i++;
	} 
}
*/
