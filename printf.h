/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:31:07 by hcherpre          #+#    #+#             */
/*   Updated: 2021/12/14 13:27:42 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr_base(long long nbr, char *base);
int		check_base(char *base);
int		ft_strlen(char *base);
int		ft_putnbr_base_unsigned(unsigned int nbr, char *base);
int		ft_putnbr_ptr(uintptr_t nb);
void	put_point(uintptr_t nb);
int		ft_size_unsigned(unsigned int nbr, int size);
int		ft_size(long long nbr, int size);
int		ft_size_ptr(uintptr_t nb);
int		ft_convert(char c, va_list ap);

#endif