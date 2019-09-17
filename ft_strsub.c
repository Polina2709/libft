/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jczech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:45:25 by jczech            #+#    #+#             */
/*   Updated: 2019/09/17 14:54:54 by jczech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*sub_str;
	unsigned int	i;

	i = 0;
	sub_str = malloc(ft_strlen((char *)s));
	if (!sub_str)
		return (NULL);
	while (i < len)
		sub_str[i++] = s[start++];
	return (sub_str);
}
