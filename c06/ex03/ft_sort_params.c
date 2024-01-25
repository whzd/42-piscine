/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andteixe <andteixe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:12:19 by andteixe          #+#    #+#             */
/*   Updated: 2024/01/25 16:55:15 by andteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_argv_swap(char **argv, int pos_i, int pos_j)
{
	char	*tmp;

	tmp = argv[pos_i];
	argv[pos_i] = argv[pos_j];
	argv[pos_j] = tmp;
}

void	ft_prnt_argv(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			j++;
		write(1, argv[i], j);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			j = 1;
			while (j < argc - i)
			{
				if (ft_strcmp(argv[j], argv[j + 1]) > 0)
					ft_argv_swap(argv, j, j + 1);
				j++;
			}
			i++;
		}
		ft_prnt_argv(argc, argv);
	}
	return (0);
}
