/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andteixe <andteixe@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:16:51 by andteixe          #+#    #+#             */
/*   Updated: 2024/01/14 18:48:21 by andteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	l;

	if (n < 0)
	{
		l = 'N';
	}
	else
	{
		l = 'P';
	}
	write(1, &l, 1);
}

/*
int	main(void)
{
	ft_is_negative(-1);
	ft_is_negative(2);
	return (0);
}
*/
