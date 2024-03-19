/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luz-mjur <luz-mjur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:06:54 by luz-mjur          #+#    #+#             */
/*   Updated: 2023/07/12 18:05:44 by luz-mjur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_print_char(char c);
int	ft_print_u_int(unsigned int n);
int	ft_print_decimal_int(int n);
int	ft_print_hex(unsigned int n, char c);
int	ft_print_str(char *str);
int	ft_print_punt(long unsigned int n);
int	ft_print_ppunt(long unsigned int n);

#endif