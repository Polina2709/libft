/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jczech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:51:08 by jczech            #+#    #+#             */
/*   Updated: 2019/09/20 20:44:32 by jczech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*copy;
	size_t	len;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	len = ft_strlen(s);
	copy = (char *)malloc(sizeof(char *) * len + 1);
	if (!copy)
		return (NULL);
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		len--;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (i < len)
		copy[j++] = s[i++];
	copy[j] = '\0';
	return (copy);
}
