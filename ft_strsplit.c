/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jczech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 16:51:43 by jczech            #+#    #+#             */
/*   Updated: 2019/09/24 19:33:20 by jczech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t words;
	size_t index;

	index = 0;
	words = 0;
	while (s[index] != '\0')
	{
		while (s[index] == c)
			index++;
		while (s[index] != c && s[index] != '\0')
		{
			words++;
			while (s[index] != c && s[index] != '\0')
				index++;
		}
	}
	return (words);
}

static size_t	ft_start_word(char const *s, char c, size_t index)
{
	size_t start;

	start = index;
	while (index != 0)
	{
		index--;
		start--;
		if (s[index] == c)
			return (start + 1);
	}
	return (start);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	len_string;
	size_t	index;
	char	**new_arr;

	len_string = 0;
	index = 0;
	if (!s || !c || !(new_arr = (char **)malloc(sizeof(char *) *
					(ft_count_words(s, c) + 1))))
		return (NULL);
	while (len_string < ft_count_words(s, c))
	{
		while (s[index] == c)
			index++;
		while (s[index] && s[index] != c)
			index++;
		if (!(new_arr[len_string++] = ft_strsub(s,
						(unsigned int)ft_start_word(s, c, index),
						index - ft_start_word(s, c, index))))
		{
			free(new_arr);
			return (NULL);
		}
	}
	new_arr[len_string] = 0;
	return (new_arr);
}
