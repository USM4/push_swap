/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:10:40 by oredoine          #+#    #+#             */
/*   Updated: 2023/06/17 02:10:12 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putchar_fd(char c, int fd)

{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)

{
	if (n <= -2147483648)
		write (fd, "-2147483648", 11);
	else
	{
		if (n >= 0 && n <= 9)
			ft_putchar_fd(n + 48, fd);
		else if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putchar_fd(n % 10 + 48, fd);
		}
		else
		{
			write (fd, "-", 1);
			ft_putnbr_fd(n * -1, fd);
		}
	}
}
