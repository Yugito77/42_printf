/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:24:30 by hcherpre          #+#    #+#             */
/*   Updated: 2021/12/14 11:38:35 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_size(long long nbr, int size)
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

int	ft_strlen(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		if (ft_strlen(base) < 2)
			return (0);
		if (base[i] == '+' || base[i] == '-' || base[i] < 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_base(long long nbr, char *base)
{
	int		size;
	int		len;

	size = ft_strlen(base);
	len = ft_size(nbr, size);
	if (!check_base(base))
		return (0);
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
		len += 1;
	}
	if (nbr >= size)
	{
		ft_putnbr_base((nbr / size), base);
		ft_putnbr_base((nbr % size), base);
	}
	if (nbr < size && nbr >= 0)
		ft_putchar(base[nbr]);
	return (len);
}
