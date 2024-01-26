/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andteixe <andteixe@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:55:04 by andteixe          #+#    #+#             */
/*   Updated: 2024/01/18 18:59:34 by andteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_valid_alpha(char *str)
{
	if (*str >= 'A' && *str <= 'Z')
		return (1);
	else if (*str >= 'a' && *str <= 'z')
		return (1);
	else
		return (0);
}

int	ft_str_is_alpha(char *str)
{
	while (*str)
	{
		if (ft_valid_alpha(str) == 0)
			return (0);
		str++;
	}
	return (1);
}
