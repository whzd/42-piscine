/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andteixe <andteixe@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:48:21 by andteixe          #+#    #+#             */
/*   Updated: 2024/01/28 20:36:26 by andteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_validate_base(char *base);
int	ft_valid_digit(char c, char *base_from);
int	ft_valid_sign(char c, int *neg);

int	ft_power(int nbr, int pow)
{
	int	res;

	res = 1;
	if (pow <= 0)
		return (0);
	while (pow > 0)
	{
		res *= nbr;
		pow--;
	}
	return (res);
}

int	ft_nr_digits(long int nbr)
{
	int	nr;

	nr = 0;
	while (nbr / 10)
		nr++;
	return (nr + 1);
}

char	*ft_itoa(long int nbr, int neg, int to_base_radix, char *base_to)
{
	char	*res;
	int		flag;
	int		size;
	int		len;

	size = ft_nr_digits(nbr);
	if (neg % 2 != 0)
		flag = 1;
	else
		flag = 0;
	len = size + 1 + flag;
	res = malloc(len);
	if (!res)
		return (NULL);
	if (flag)
		res[0] = '-';
	res[len] = '\0';
	while (--len > 0)
	{
		res[len] = base_to[nbr % to_base_radix];
		nbr /= to_base_radix;
	}
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*res;
	int		i;
	int		neg;
	int		from_base_radix;
	int		to_base_radix;
	long int		num;

	from_base_radix = ft_validate_base(base_from);
	to_base_radix = ft_validate_base(base_to);
	if (from_base_radix && to_base_radix)
	{
		i = 0;
		while ((nbr[i] >= '\t' && nbr[i] <= '\r') || nbr[i] == ' ')
			i++;
		while (ft_valid_sign(nbr[i], &neg))
			i++;
		while (ft_valid_num(nbr[i], base_from))
		{
			num += j * ft_power(from_base_radix, (size - j - 1));
			j++;
			i++;
		}
		return (ft_itoa(num, neg, to_base_radix, base_to));
	}
	return (NULL);
}

#include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_convert_base("4", "0123456789", "01");
}
