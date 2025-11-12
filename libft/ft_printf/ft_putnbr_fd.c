/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kqueiroz <kqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 22:31:11 by kqueiroz          #+#    #+#             */
/*   Updated: 2025/09/02 19:32:39 by kqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	count;

	if (fd < 0)
		return (0);
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	count = 0;
	if (n < 0)
	{
		count += ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n >= 10)
		count += ft_putnbr_fd(n / 10, fd);
	count += ft_putchar_fd((n % 10) + '0', fd);
	return (count);
}
