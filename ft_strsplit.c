/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jczech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:18:52 by jczech            #+#    #+#             */
/*   Updated: 2019/09/24 13:25:49 by jczech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(char *s, char c)
{
	int	words;
	int	index;

	index = 0;
    words = 0;
	while (s[index])
	{
		if  (s[index] == c)
			index++;
		else
		{
			while (s[index] != c)
				index++;
			words++;
		}
	}
	return (words);
}

static int	ft_count_symbols(char *s, char c, int i)
{
	int	words;
	int symbols;
	int	index;

	index = 0;
	symbols = 0;
	words = 0;
	while (s[index])
	{
		if  (s[index] == c)
			index++;
		else
		{
			while (s[index] != c)
			{
				if (words == i)
					symbols++;
					index++;
			}
			index++;
			words++;
		}
	}
	return (symbols);
}

static char	*ft_fill_arr(char *s, char *new_arr, char c, int i)
{
	int	words;
	int symbols;
	int	index;

	index = 0;
	symbols = 0;
	words = 0;
	while (s[index])
	{
		if  (s[index] == c)
			index++;
		else
		{
			while (s[index] != c)
			{
				while (words == i && s[index] != c)
				{
					*new_arr = s[index++];
					new_arr++;
				}
                if (words == i)
                {
                    *new_arr = '\0';
                    return (new_arr);
                }
			index++;
			}
            words++;
		}
	}
	return (new_arr);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**new_arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(new_arr = (char **)malloc(sizeof(char *) * ft_count_words((char *)s, c) + 1)))
		return (NULL);
	while (i < ft_count_words((char *)s, c))
	{
/*		if (i == ft_count_words((char *)s, c))
		{
			if (!(new_arr[i] = (char *)malloc(sizeof(char) * 1)))
				return (NULL);
			new_arr[i][0] = '\0';
		}
*/	//	else
	//	{
			if (!(new_arr[i] = (char *)malloc(sizeof(char) * ft_count_symbols((char *)s, c, i) + 1)))
			{
    			ft_memdel((void **)new_arr);
				return (NULL);
			}
			new_arr[i] = ft_fill_arr((char *)s, new_arr[i], c, i);
			i++;
		}
//	}
	if (i == ft_count_words((char *)s, c))
		new_arr[i] = NULL;
	return (new_arr);
}
