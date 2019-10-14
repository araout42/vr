/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 01:57:02 by kicausse          #+#    #+#             */
/*   Updated: 2018/12/05 01:57:03 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char_fd(char c, int amount, int fd)
{
	int n;

	n = amount;
	while (n-- > 0)
		ft_putchar_fd(c, fd);
	return (ft_floor(0, amount));
}
