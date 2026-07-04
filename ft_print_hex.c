/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 12:30:45 by jonbezer          #+#    #+#             */
/*   Updated: 2026/06/26 14:24:31 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int nbr, char *base)
{
	int	nbr_len;

	nbr_len = 0;
	if (nbr < 16)
	{
		ft_print_chr(base[nbr]);
		nbr_len++;
	}
	if (nbr >= 16)
	{
		nbr_len += ft_print_hex(nbr / 16, base);
		nbr_len += ft_print_hex(nbr % 16, base);
	}
	return (nbr_len);
}
