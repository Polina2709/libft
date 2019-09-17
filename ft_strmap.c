/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jczech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:16:17 by jczech            #+#    #+#             */
/*   Updated: 2019/09/17 13:44:13 by jczech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = malloc(ft_strlen((char *)s));
	while (s[i] != '\0')
	{
		new_str[i] = f((char)s[i]);
		i++;
	}
	return (new_str);
}
