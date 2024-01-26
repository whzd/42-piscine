/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andteixe <andteixe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 20:32:22 by andteixe          #+#    #+#             */
/*   Updated: 2024/01/25 21:40:23 by andteixe         ###   ########.fr       */
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

char	*ft_strdup(char *src)
{
	char	*str;
	char	*offset;

	str = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (str == NULL)
		return ((char *) NULL);
	offset = str;
	while (*src)
		*offset++ = *src++;
	*offset = '\0';
	return (str);
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char str[] = "onetwothree";
	char *dup;
	char *dup2;
	dup = ft_strdup(str);
	if (dup)
	{
		printf("%s\n", dup);
		free(dup);
	}
	dup2 = strdup(str);
	if (dup2)
	{
		printf("%s\n", dup2); 
		free(dup2);
	}
	return (0);
}
*/
