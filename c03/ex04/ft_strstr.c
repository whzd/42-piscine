/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andteixe <andteixe@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 22:11:01 by andteixe          #+#    #+#             */
/*   Updated: 2024/01/22 18:01:44 by andteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] == '\0' && to_find[j] == '\0')
	{
		return (str);
	}
	while (str[i])
	{
		while (to_find[j] && to_find[j] == str[i + j])
		{
			j++;
		}
		if (to_find[j] == '\0')
			return (str + i);
		j = 0;
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	haystack[] = "piscine Benguerir Khouribga";
	char	needle[] = " Beng";
	char	haystack[] = "";
	char	needle[] = "";
	printf("%s\n", ft_strstr(haystack, needle));
	printf("%s\n", strstr(haystack, needle));
}
*/
