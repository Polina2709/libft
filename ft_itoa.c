/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jczech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:52:45 by jczech            #+#    #+#             */
/*   Updated: 2019/09/17 20:20:44 by jczech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_revstr(char *s)
{
	char	*rev_s;
	int		len;
	int		i;
	int		j;

	j = 1;
	i = 0;
	len = ft_strlen(s) - 1;
	rev_s = (char *)malloc(sizeof(char) * len + 1);
	if (s[j] == '-')
	{
		rev_s[i++] = '-';
		j++;
	}
	while (len >= j)
	{
		rev_s[i] = s[len--];
		i++;
	}
	return (rev_s);
}

char	*ft_itoa_helper(char *s, int n)
{
	int i;

	i = 0;
	s[i++] = ' ';
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
	s[i] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * 15);
	if (n == -2147483648)
		s = "-2147483648\0";
	else
		s = ft_itoa_helper(s, n);
	return (s);
}
