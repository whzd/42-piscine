/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andteixe <andteixe@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 23:37:03 by andteixe          #+#    #+#             */
/*   Updated: 2024/01/22 14:23:33 by andteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_valid_alphanum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (2);
	else if (c >= 'a' && c <= 'z')
		return (3);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0) 
		{
			if (ft_valid_alphanum(str[i]) == 3)
				str[i] -= 32;
		}
		else 
		{
			if (ft_valid_alphanum(str[i - 1]) == 0)
			{
				if (ft_valid_alphanum(str[i]) == 3)
					str[i] -= 32;
			}
			else if (ft_valid_alphanum(str[i]) == 2)
				str[i] += 32; 
		}
		i++;
	}
	return (str);
}
