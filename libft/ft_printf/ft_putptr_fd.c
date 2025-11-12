/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kqueiroz <kqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 20:59:49 by kqueiroz          #+#    #+#             */
/*   Updated: 2025/09/03 17:50:07 by kqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_ptr_fd(uintptr_t n, char format, int fd)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthex_ptr_fd(n / 16, format, fd);
	count += ft_putchar_fd(base[n % 16], fd);
	return (count);
}

int	ft_putptr_fd(void *ptr, int fd)
{
	int			count;

	if (fd < 0)
		return (0);
	if (!ptr)
	{
		ft_putstr_fd("(nil)", fd);
		return (5);
	}
	count = 2;
	ft_putstr_fd("0x", fd);
	count += ft_puthex_ptr_fd((unsigned long)ptr, 'x', fd);
	return (count);
}
