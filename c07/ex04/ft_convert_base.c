/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andteixe <andteixe@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:48:21 by andteixe          #+#    #+#             */
/*   Updated: 2024/01/29 03:40:56 by andteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_validate_base(char *base);
int	ft_valid_digit(char c, char *base_from);
int	ft_valid_sign(char c, int *neg);

int	ft_nr_digits(long int nbr, int to_base_radix)
{
	int	nr;

	nr = 0;
	while (nbr / to_base_radix != 0)
	{
		nr++;
		nbr /= to_base_radix;
	}
	return (nr + 1);
}

char	*ft_itoa(long int nbr, int neg, int to_base_radix, char *base_to)
{
	char	*res;
	int		flag;
	int		size;
	int		len;

	size = ft_nr_digits(nbr, to_base_radix);
	if (neg % 2 != 0)
		flag = 1;
	else
		flag = 0;
	printf("%d\n", flag);
	len = size + 1 + flag;
	res = malloc(len);
	if (!res)
		return (NULL);
	if (flag)
		res[0] = '-';
	res[--len] = '\0';
	while (nbr > 0)
	{
		res[--len] = base_to[nbr % to_base_radix];
		nbr /= to_base_radix;
	}
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*res;
	int		i;
	int		j;
	int		size;
	int		end;
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
		size = 0;
		j = i;
		while (ft_valid_digit(nbr[i], base_from))
		{
			i++;
			size++;
		}
		end = size + j;
		num = 0;
		while (j < end)
		{
			num = num * from_base_radix + (nbr[j] - base_from[0]);
			j++;
		}
		return (ft_itoa(num, neg, to_base_radix, base_to));
	}
	return (NULL);
}
/*
int	main(void)
{
	printf("%s\n", ft_convert_base("-21474836491", "0123456789", "0123456789"));
	return (0);
}
*/
