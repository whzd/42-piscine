/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andteixe <andteixe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:08:10 by andteixe          #+#    #+#             */
/*   Updated: 2024/01/25 22:52:56 by andteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*array;
	int	*offset;
	int	array_len;

	if (min >= max)
	{
		*range = (int *) NULL;
		return (0);
	}
	array_len = (max - min);
	array = malloc(sizeof(int) * array_len);
	if (array == NULL)
		return (-1);
	offset = array;
	while (min < max)
	{
		*offset = min;
		min++;
		offset++;
	}
	*range = array;
	return (array_len);
}

/*
#include <stdio.h>
int	main(void)
{
	int	**range;
	int	max = 25;
	int	min = 4;
	int	i = 0;
	int	range_len;

	range_len = ft_ultimate_range(range, min, max);
	printf("Size of range: %d\n", range_len); 
	while ( i < range_len)
	{
		if (i != range_len - 1)
			printf("%d ", range[0][i]);
		else
			printf("%d", range[0][i]);
		i++;
	}
	free(*range);
	return (0);
}
*/
