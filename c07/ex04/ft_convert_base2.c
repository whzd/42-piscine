/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andteixe <andteixe@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:35:44 by andteixe          #+#    #+#             */
/*   Updated: 2024/01/28 20:23:13 by andteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_validate_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] < ' ' || base[i] > '~')
			return (0);
		j = 0 ;
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

int	ft_valid_digit(char c, char *base_from)
{
	int	i;

	i = -1;
	while (base_from[++i])
		if (c == base_from[i])
			return (1);
	return (0);
}

int	ft_valid_sign(char c, int *neg)
{
	if (c == '-')
	{
		*neg += 1;
		return (1);
	}
	if (c == '+')
		return (1);
	return (0);
}
