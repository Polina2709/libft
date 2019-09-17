/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jczech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:13:39 by jczech            #+#    #+#             */
/*   Updated: 2019/09/17 18:22:51 by jczech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen((char *)s);
	while (i < len)
		ft_putchar(s[i++]);
	ft_putchar('\n');
}
