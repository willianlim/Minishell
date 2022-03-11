/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:43:50 by rogerio           #+#    #+#             */
/*   Updated: 2022/03/11 14:26:40 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char *ft_print_out(char *buffer, va_list args)
{
	int				i;
	char			*new_string;
	t_params		parameters;
	char			*tmp;
	char			*tmp2;

	i = -1;
	new_string = ft_strdup("");
	while (buffer[++i])
	{
		if (buffer[i] == '%' && ft_isvalid(&parameters, &buffer[i + 1]))
		{
			tmp = ft_convert(&parameters, args);
			tmp2 = new_string;
			new_string = ft_strjoin(new_string, tmp);
			i += ft_move_forward(&buffer[i]);
		}
		else
		{
			tmp2 = (char *)malloc(sizeof(char) * 2);
			tmp2[0] = buffer[i];
			tmp2[1] = 0;
			tmp = new_string;
			new_string = ft_strjoin(new_string, tmp2);
		}
		free(tmp);
		free(tmp2);
	}
	return (new_string);
}

char	*ft_printf(const char *input, ...)
{
	va_list	args;
	char	*buffer;
	char	*printed;

	buffer = ft_strdup((char *)input);
	va_start(args, input);
	printed = ft_print_out(buffer, args);
	va_end(args);
	free(buffer);
	return (printed);
}
