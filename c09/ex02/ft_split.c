/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andteixe <andteixe@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:42:06 by andteixe          #+#    #+#             */
/*   Updated: 2024/01/29 23:33:43 by andteixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_char_is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_word(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!ft_char_is_sep(str[i], charset)
			&& (ft_char_is_sep(str[i + 1], charset)
				|| str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	*ft_create_word(char *str, int count, int i)
{
	char	*word;

	word = malloc(count + 1);
	word[count] = 0;
	while (--count >= 0)
		word[count] = str[--i];
	return (word);
}

int	ft_split_aux(char *str, char *charset, char **res, int *k)
{
	auto int count = 0, i = 0;
	while (str[i] && ft_char_is_sep(str[i], charset))
		i++;
	while (str[i])
	{
		if (ft_char_is_sep(str[i], charset))
		{
			res[*k] = ft_create_word(str, count, i);
			count = 0;
			*k += 1;
			while (str[i] && ft_char_is_sep(str[i], charset))
				i++;
		}
		else
		{
			count++;
			i++;
		}
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	auto int k = 0, i = 0, count = 0;
	auto char **res;
	res = malloc((sizeof(char *) * ft_count_word(str, charset) + 1));
	count = ft_split_aux(str, charset, res, &k);
	if (count)
	{
		while (str[i])
			i++;
		res[k++] = ft_create_word(str, count, i);
	}
	res[k] = 0;
	return (res);
}
/*
int	main(void)
{
	//char	*str = " oneyeettwoo yeet thyree";
	//char	*charset = "yeet";
	//char	*str = "A#cadeia@que#sera+transmitida#nao+sera@editavel";
	//char	*charset = "#@+";
	char	*str = "aacccaa";
	char	*charset = "aa";
	int	i = 0;
	char	**res;
	res = ft_split(str, charset);
	while (res[i])
	{
		printf("%s\n", res[i]);
		i++;
	}
	return (0);
}
*/
