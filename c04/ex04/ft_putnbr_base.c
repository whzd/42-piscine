/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andteixe <andteixe@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:45:24 by andteixe          #+#    #+#             */
/*   Updated: 2024/01/23 22:18:33 by andteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_validate_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] < ' ' || base[i] > '~')
			return (0);
		j = 0;
		while (j < i)
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_putnbr_aux(int nb, char *base, int baselen)
{
	if (nb == -2147483648)
	{
		ft_putnbr_aux(nb / baselen, base, baselen);
		ft_putnbr_aux(-(nb % baselen), base, baselen);
	}
	else if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
		ft_putnbr_aux(nb, base, baselen);
	}
	else if (nb / baselen != 0)
	{
		ft_putnbr_aux(nb / baselen, base, baselen);
		ft_putnbr_aux(nb % baselen, base, baselen);
	}
	else
		ft_putchar(base[nb]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	baselen;

	baselen = ft_validate_base(base);
	if (!baselen)
		return ;
	ft_putnbr_aux(nbr, base, baselen);
}

/*
int	main(void)
{
	ft_putnbr_base(25, "01");
	return (0);
}
*/
