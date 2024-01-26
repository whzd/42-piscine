/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andteixe <andteixe@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:41:45 by andteixe          #+#    #+#             */
/*   Updated: 2024/01/16 18:39:28 by andteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_current_comb(int *comb, int n)
{
	int	i;
	int	aux;

	i = 0;
	while (i < n)
	{
		aux = comb[i] + '0';
		write(1, &aux, 1);
		i++;
	}
}

void	ft_init_comb(int *comb, int n, int *pos)
{
	*pos = 0;
	while (*pos < n)
	{
		comb[*pos] = *pos;
		*pos = *pos + 1;
	}
}

int	ft_find_increase(int *comb, int n)
{
	int	max;
	int	digit;
	int	pos;

	max = 10;
	pos = n;
	while (pos--)
	{
		digit = comb[pos];
		if (digit < --max)
		{
			while (pos < n)
			{
				comb[pos] = ++digit;
				pos++;
			}
			write(1, ", ", 2);
			return (pos);
		}
	}
	return (pos);
}

void	ft_print_combn(int n)
{
	int	comb[10];
	int	pos;

	if (n < 1 || n > 10)
	{
		return ;
	}
	ft_init_comb(comb, n, &pos);
	while (pos > 0)
	{
		ft_print_current_comb(comb, n);
		pos = ft_find_increase(comb, n);
	}
}

/*
int main(void)
{
  ft_print_combn(2);
  return (0);
}
*/
