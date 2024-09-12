/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:28:49 by kgalstya          #+#    #+#             */
/*   Updated: 2024/09/12 17:07:25 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

size_t	ft_atoi(const char *nptr)
{
	size_t	num;
	int		n;

	n = 0;
	num = 0;
	while (nptr[n] >= '0' && nptr[n] <= '9')
	{
		num = num * 10 + (nptr[n] - '0');
		n++;
	}
	return (num);
}
