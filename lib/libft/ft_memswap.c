/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kupsyloc <kupsyloc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 22:06:54 by kupsyloc          #+#    #+#             */
/*   Updated: 2020/12/29 22:07:23 by kupsyloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_memswap(void *mem1, void *mem2, size_t size)
{
	unsigned char	*a;
	unsigned char	*b;
	unsigned		c;

	if (!mem1 || !mem2)
		return ;
	a = (unsigned char *)mem1;
	b = (unsigned char *)mem2;
	while (size-- > 0 && a && b)
	{
		c = *a;
		*a = *b;
		*b = c;
		a++;
		b++;
	}
}
