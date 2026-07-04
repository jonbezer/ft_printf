/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 12:30:44 by jonbezer          #+#    #+#             */
/*   Updated: 2026/07/03 18:25:38 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char specifier, va_list *args)
{
	char	*lower_hex;
	char	*upper_hex;

	lower_hex = "0123456789abcdef";
	upper_hex = "0123456789ABCDEF";
	if (specifier == 'c')
		return (ft_print_chr(va_arg(*args, int)));
	if (specifier == 's')
		return (ft_print_str(va_arg(*args, char *)));
	if (specifier == 'p')
		return (ft_print_ptr(va_arg(*args, void *)));
	if (specifier == 'd' || specifier == 'i')
		return (ft_print_nbr(va_arg(*args, int)));
	if (specifier == 'u')
		return (ft_print_unsigned(va_arg(*args, unsigned int)));
	if (specifier == 'x')
		return (ft_print_hex(va_arg(*args, unsigned int), lower_hex));
	if (specifier == 'X')
		return (ft_print_hex(va_arg(*args, unsigned int), upper_hex));
	if (specifier == '%')
		return (ft_print_chr('%'));
	return (0);
}
