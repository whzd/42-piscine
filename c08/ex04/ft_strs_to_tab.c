/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andteixe <andteixe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:07:56 by andteixe          #+#    #+#             */
/*   Updated: 2024/01/31 15:05:46 by andteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_create_cpy(char *str)
{
	int		i;
	char	*cpy;

	cpy = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*s_stock;

	s_stock = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!s_stock)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		s_stock[i].size = ft_strlen(av[i]);
		s_stock[i].str = av[i];
		s_stock[i].copy = ft_create_cpy(av[i]);
		i++;
	}
	s_stock[i].size = 0;
	s_stock[i].str = 0;
	s_stock[i].copy = 0;
	return (s_stock);
}
