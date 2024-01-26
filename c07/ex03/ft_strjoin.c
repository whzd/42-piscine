/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andteixe <andteixe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 23:05:43 by andteixe          #+#    #+#             */
/*   Updated: 2024/01/26 00:54:26 by andteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		*s1 = s2[i];
		s1++;
		i++;
	}
	return (s1);
}

int	ft_newstr_len(int size, char **strs, char *sep)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < size)
	{
		res += ft_strlen(strs[i]);
		i++;
	}
	res += ft_strlen(sep) * (size - 1);
	return (res);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		str_len;
	char	*str;
	char	*offset;

	if (size == 0)
		return ((char *) malloc(sizeof(char) * size));
	str_len = ft_newstr_len(size, strs, sep);
	str = malloc(str_len + 1);
	if (str == NULL)
		return ((char *) NULL);
	offset = str;
	i = 0;
	while (i < size)
	{
		offset = ft_strcpy(offset, strs[i]);
		if (i < size - 1)
			offset = ft_strcpy(offset, sep);
		i++;
	}
	*offset = '\0';
	return (str);
}

/*
#include <stdio.h>
int	main(void)
{
	char *strs[] = {"one", "two", "three"};
	char sep[] = "AND";
	int size = 3;
	char *res = ft_strjoin(size, strs, sep);
	printf("Size res: %d\n", ft_strlen(res));
	printf("Content res: %s\n", res);
	free(res);
	return (0);
}
*/
