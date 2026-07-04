/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:40:02 by jonbezer          #+#    #+#             */
/*   Updated: 2026/06/21 18:25:37 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	str_len;

	str_len = 0;
	if (!str)
		str = "(null)";
	while (str[str_len])
		str_len++;
	write(1, str, str_len);
	return (str_len);
}
