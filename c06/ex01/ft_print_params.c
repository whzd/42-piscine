/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andteixe <andteixe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:53:39 by andteixe          #+#    #+#             */
/*   Updated: 2024/01/25 16:07:31 by andteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			j = 0;
			while (argv[i][j])
				j++;
			write(1, argv[i], j);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
