/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andteixe <andteixe@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:12:58 by andteixe          #+#    #+#             */
/*   Updated: 2024/02/01 02:15:03 by andteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(-(nbr % 10));
	}
	else if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-');
		ft_putnbr(nbr);
	}
	else if (nbr / 10 != 0)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}

/*
int	main(void)
{
	ft_putnbr(0);
	ft_putchar('\n');
	ft_putnbr(-8);
	ft_putchar('\n');
	ft_putnbr(-2147483648);
	ft_putchar('\n');
	return (0);
}
*/
