/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 10:21:46 by jonbezer          #+#    #+#             */
/*   Updated: 2026/06/26 10:25:32 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int nbr)
{
	int	nbr_len;

	nbr_len = 0;
	if (nbr <= 9)
	{
		ft_print_chr(nbr + '0');
		nbr_len++;
	}
	if (nbr > 9)
	{
		nbr_len += ft_print_unsigned(nbr / 10);
		nbr_len += ft_print_unsigned(nbr % 10);
	}
	return (nbr_len);
}
