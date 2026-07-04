/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 11:29:18 by jonbezer          #+#    #+#             */
/*   Updated: 2026/07/03 18:43:04 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_ptr_hex(unsigned long address)
{
	int		ptr_len;
	char	*base;

	ptr_len = 0;
	base = "0123456789abcdef";
	if (address < 16)
	{
		ft_print_chr(base[address]);
		ptr_len++;
	}
	if (address >= 16)
	{
		ptr_len += ft_print_ptr_hex(address / 16);
		ptr_len += ft_print_ptr_hex(address % 16);
	}
	return (ptr_len);
}

int	ft_print_ptr(void *ptr)
{
	int				ptr_len;
	unsigned long	address;

	address = (unsigned long)ptr;
	if (!ptr)
		return (ft_print_str("(nil)"));
	ft_print_str("0x");
	ptr_len = 2;
	ptr_len += ft_print_ptr_hex(address);
	return (ptr_len);
}
