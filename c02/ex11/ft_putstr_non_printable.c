/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andteixe <andteixe@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:20:01 by andteixe          #+#    #+#             */
/*   Updated: 2024/01/22 17:41:17 by andteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_to_hex(char c, char *hex)
{
	int	tmp;

	if (c / 16 != 0)
		ft_to_hex(c / 16, hex);
	tmp = c % 16;
	write(1, &hex[tmp], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	*hex;

	hex = "0123456789abcdef";
	i = 0;
	while (str[i])
	{
		if (str[i] < ' ' || str[i] > '~')
		{
			write(1, "\\", 1);
			if (str[i] > 16)
				ft_to_hex(str[i], hex);
			else
			{
				write(1, "0", 1);
				ft_to_hex(str[i], hex);
			}
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}
