/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andteixe <andteixe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:40:57 by andteixe          #+#    #+#             */
/*   Updated: 2024/01/25 22:28:19 by andteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	*offset;

	if (min >= max)
		return ((int *) NULL);
	array = malloc(sizeof(int) * (max - min));
	if (array == NULL)
		return ((int *) NULL);
	offset = array;
	while (min < max)
	{
		*offset = min;
		min++;
		offset++;
	}
	return (array);
}

/*
#include <stdio.h>
int	main(void)
{
	int min = 1;
	int max = 25;
	int *range = ft_range(min, max);
	int i = 0;
	while (i < max - 1)
	{
		if (i != max - 2)
			printf("%d ", range[i]);
		else
			printf("%d", range[i]);
		i++;
	}
	free(range);
	return (0);
}
*/
