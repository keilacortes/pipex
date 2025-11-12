/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kqueiroz <kqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 20:36:51 by kqueiroz          #+#    #+#             */
/*   Updated: 2025/09/03 17:37:31 by kqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_fd(unsigned int n, char format, int fd)
{
	unsigned int	count;
	char			*base;

	count = 0;
	if (fd < 0)
		return (0);
	if (format == 'x')
		base = "0123456789abcdef";
	if (format == 'X')
		base = "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthex_fd(n / 16, format, fd);
	count += ft_putchar_fd(base[n % 16], fd);
	return (count);
}
