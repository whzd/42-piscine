/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andteixe <andteixe@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:20:01 by andteixe          #+#    #+#             */
/*   Updated: 2024/02/01 02:46:01 by andteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	*hex;

	hex = "0123456789abcdef";
	i = -1;
	while (str[++i])
	{
		if (str[i] < ' ' || str[i] > '~')
		{
			ft_putchar('\\');
			ft_putchar(hex[str[i] / 16]);
			ft_putchar(hex[str[i] % 16]);
		}
		else
			ft_putchar(str[i]);
	}
}

/*
int	main(void)
{
	char	str[] = "Coucou\ntu vas bien?";
	ft_putstr_non_printable(str);
	return (0);
}
*/
