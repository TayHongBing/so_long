/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:17:50 by jchu              #+#    #+#             */
/*   Updated: 2023/01/12 21:11:33 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

unsigned int	abs_val(int x, int *sign)
{	
	if (x < 0)
		*sign = 1;
	else
		*sign = 0;
	if (x == -2147483648)
	{
		*sign = 2;
		return (147483648);
	}
	if (x < 0)
		return (-x);
	else
		return (x);
}

void	ft_strrev(char *str)
{
	char	tmp;
	size_t	len;
	size_t	idx;

	idx = 0;
	len = ft_strlen(str);
	while (idx < len / 2)
	{
		tmp = str[idx];
		str[idx] = str[len - idx - 1];
		str[len - idx - 1] = tmp;
		idx++;
	}
}

int	num_digits(int num)
{
	int	num_digits;

	num_digits = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num_digits++;
		num /= 10;
	}
	return (num_digits);
}

char	*final(int sign, int digits, char *result)
{
	if (sign == 1)
		result[digits - 1] = '-';
	if (sign == 2)
	{
		result[digits - 2] = '2';
		result[digits - 1] = '-';
	}
	result[digits] = '\0';
	ft_strrev(result);
	return (result);
}

char	*ft_itoa(int n)
{
	int		digits;
	char	*result;
	int		sign;
	size_t	idx;

	n = abs_val(n, &sign);
	digits = num_digits(n) + sign;
	result = malloc(sizeof(char) * (digits + 1));
	if (!result)
		return (NULL);
	idx = 0;
	if (n == 0)
		result[0] = '0';
	while (n != 0)
	{
		result[idx++] = '0' + (n % 10);
		n /= 10;
	}
	return (final(sign, digits, result));
}

/*int main(void)
{
	printf ("%s", ft_itoa(-2147483648));
	return (0);
}*/