/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:12:38 by hcherpre          #+#    #+#             */
/*   Updated: 2021/12/14 11:42:42 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_size_ptr(uintptr_t nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

void	put_point(uintptr_t nb)
{
	if (nb >= 16)
	{
		put_point(nb / 16);
		put_point(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar(nb + '0');
		else
			ft_putchar(nb - 10 + 'a');
	}
}

int	ft_putnbr_ptr(uintptr_t nb)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	put_point(nb);
	return (ft_size_ptr(nb) + len);
}
