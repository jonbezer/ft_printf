/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonbezer <jonbezer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 18:29:33 by jonbezer          #+#    #+#             */
/*   Updated: 2026/07/03 18:42:42 by jonbezer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_format(char specifier, va_list *args);
int	ft_print_chr(char c);
int	ft_print_str(char *str);
int	ft_print_nbr(int nbr);
int	ft_print_unsigned(unsigned int nbr);
int	ft_print_hex(unsigned int nbr, char *base);
int	ft_print_ptr(void *ptr);

#endif
