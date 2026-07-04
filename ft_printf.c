/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 15:37:26 by jonbezer          #+#    #+#             */
/*   Updated: 2026/07/03 18:27:40 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		printf_len;
	va_list	args;

	printf_len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			printf_len += ft_format(*(format + 1), &args);
			format++;
		}
		else
			printf_len += ft_print_chr(*format);
		format++;
	}
	va_end(args);
	return (printf_len);
}
