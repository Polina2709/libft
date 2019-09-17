/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jczech <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:35:59 by jczech            #+#    #+#             */
/*   Updated: 2019/09/17 18:41:26 by jczech           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int	len;
	int i;

	i = 0;
	len = ft_strlen((char *)s);
	while (i < len)
		ft_putchar_fd(s[i++], fd);
	ft_putchar_fd('\n', fd);
}
