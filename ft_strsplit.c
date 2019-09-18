/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jczech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:18:52 by jczech            #+#    #+#             */
/*   Updated: 2019/09/18 22:46:48 by jczech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(char *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] != c)
			i++;
		words++;
		while (s[i] == c)
			i++;
	}
	return (words);
}

static int	ft_count_symbols(char *s, char c)
{
	int	symbols;
	int i;

	i = 0;
	symbols = 0;
	while (s[i] == c)
		i++;
	while (s[i++] != c)
		symbols++;
	return (symbols);
}


char	**ft_strsplit(char const *s, char c)
{
	char	**new_arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_arr = (char **)malloc(sizeof(char *) * ft_count_words((char *)s, c) + 1);
	if (!new_arr || !s)
		return (NULL);
	while (i < ft_count_words((char *)s, c) + 1)
	{
		if (!(new_arr[i] = (char *)malloc(sizeof(char) * ft_count_symbols((char *)s, c) + 1)))
		{
			// освободить память циклом
			return (NULL);
		i++;
	}
		
		while ((char)s != (c + '0'))
			new_arr[i][j++] = (char)s++;
		while ((char)s == (c + '0'))
			s++;
		new_arr[i][j] = '\0';
		i++;
		j = 0;
	}
	return (new_arr);
}
