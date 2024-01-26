/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andteixe <andteixe@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:21:21 by andteixe          #+#    #+#             */
/*   Updated: 2024/01/24 18:42:58 by andteixe         ###   ########.fr       */
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

int	ft_base_pos(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (0);
}

int	ft_valid_num(int c, int *res, char *base, int baselen)
{
	if (c >= '!' && c <= '~')
	{
		*res = *res * baselen + ft_base_pos(base, c);
		return (1);
	}
	return (0);
}

int	ft_is_signs(char c, int *neg)
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

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	res;
	int	baselen;
	int	neg;

	baselen = ft_validate_base(base);
	if (baselen)
	{
		i = 0;
		res = 0;
		neg = 0;
		while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
			i++;
		while (ft_is_signs(str[i], &neg))
			i++;
		while (ft_valid_num(str[i], &res, base, baselen))
			i++;
		if (neg % 2 != 0)
			return (-res);
		return (res);
	}
	return (0);
}
