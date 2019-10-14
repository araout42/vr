/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_buffer.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kicausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 00:26:23 by kicausse          #+#    #+#             */
/*   Updated: 2019/03/04 00:26:23 by kicausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_BUFFER_H
# define PRINTF_BUFFER_H
# define PRINTF_BUFSIZE (2048)
# include <string.h>

void	write_buffer(int fd, char *str, int len);
size_t	ft_putnstr_buffer(char *str, size_t n, int fd);
size_t	ft_putstr_buffer(char *str, int fd);
int		ft_putchar_buffer(char c, int fd);
int		ft_print_char_buffer(char c, int count, int fd);

#endif
