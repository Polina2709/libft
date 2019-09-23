/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jczech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:52:45 by jczech            #+#    #+#             */
/*   Updated: 2019/09/21 22:34:10 by jczech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_revstr(char *s)
{
	char	*rev_s;
	size_t	len;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	len = ft_strlen((const char *)s) - 1;
	if (!(rev_s = (char *)malloc(sizeof(char) * len + 2)))
		return (NULL);
	if (s[j] == '-')
	{
		rev_s[i++] = '-';
		j++;
	}
	while (len >= j)
	{
		rev_s[i] = s[len];
		i++;
        if (len == 0)
            break;
        len--;
	}
	rev_s[i] = '\0';
	return (rev_s);
}

static char	*ft_itoa_helper(char *s, int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		s[i++] = '-';
		n = n * -1;
	}
	while (n > 9)
	{
		s[i++] = n % 10 + '0';
		n /= 10;
	}
	if (n >= 0 && n <= 9)
		s[i++] = n + '0';
	s[i] = '\0';
	s = ft_revstr(s);
	return (s);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		len;

	len = ft_nbrlen(n);
	if (n == -2147483648)
	{
		if (!(s = (char *)malloc(sizeof(char) * 12)))
			return (NULL);
		s = "-2147483648\0";
	}
	else
	{
		if (!(s = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		s = ft_itoa_helper(s, n);
	}
	return (s);
}
