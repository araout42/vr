/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:45:23 by kicausse          #+#    #+#             */
/*   Updated: 2018/11/06 14:45:24 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memset(void *ptr, int value, size_t num)
{
	while (num-- != 0)
	{
		((unsigned char*)ptr)[num] = value;
	}
	return (ptr);
}
