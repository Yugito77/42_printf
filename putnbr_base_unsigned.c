/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base_unsigned.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:12:45 by hcherpre          #+#    #+#             */
/*   Updated: 2021/12/14 11:38:47 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_size_unsigned(unsigned int nbr, int size)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		len++;
		nbr = nbr / size;
	}
	return (len);
}

int	ft_putnbr_base_unsigned(unsigned int nbr, char *base)
{
	unsigned int	nb;
	unsigned int	size;

	nb = nbr;
	size = ft_strlen(base);
	if (!check_base(base))
		return (0);
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= size)
	{
		ft_putnbr_base_unsigned((nb / size), base);
		ft_putnbr_base_unsigned((nb % size), base);
	}
	if (nb < size && nb >= 0)
		ft_putchar(base[nb]);
	return (ft_size_unsigned(nbr, size));
}
