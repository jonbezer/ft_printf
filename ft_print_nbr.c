/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 18:30:27 by jonbezer          #+#    #+#             */
/*   Updated: 2026/06/26 10:09:50 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int nbr)
{
	int		nbr_len;
	long	long_nbr;

	nbr_len = 0;
	long_nbr = nbr;
	if (long_nbr < 0)
	{
		ft_print_chr('-');
		long_nbr *= -1;
		nbr_len++;
	}
	if (long_nbr >= 0 && long_nbr <= 9)
	{
		ft_print_chr(long_nbr + '0');
		nbr_len++;
	}
	if (long_nbr > 9)
	{
		nbr_len += ft_print_nbr(long_nbr / 10);
		nbr_len += ft_print_nbr(long_nbr % 10);
	}
	return (nbr_len);
}
