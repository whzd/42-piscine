/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andteixe <andteixe@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:12:58 by andteixe          #+#    #+#             */
/*   Updated: 2024/01/20 20:13:17 by andteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nbr)
{
	long	n;

	n = nbr;
	if (n < 0)
	{
		write(1, "-", 1); 
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n/10);
	ft_putnbr(n % 10 + 48);
}

int	main(void)
{
	ft_putnbr(-8);
	ft_putnbr(-2147483648);
}
