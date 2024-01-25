/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andteixe <andteixe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:03:17 by andteixe          #+#    #+#             */
/*   Updated: 2024/01/25 16:06:27 by andteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	if (argc > 1)
	{
		while (--argc > 0)
		{
			i = 0;
			while (argv[argc][i])
				i++;
			write(1, argv[argc], i);
			write(1, "\n", 1);
		}
	}
	return (0);
}
