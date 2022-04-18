/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainga-ri <ainga-ri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:49:30 by ainga-ri          #+#    #+#             */
/*   Updated: 2022/04/17 22:17:07 by ainga-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_len(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

void	ft_writenum(char *dict, int length)
{
	while (dict[length] != '\n')
	{
		write(1, &dict[length], 1);
		length++;
	}
}

int	ft_biglen(char *dict, char *num)
{	
	int	j;
	int	i;
	int	fin_pos;

	j = 0;
	fin_pos = 0;
	i = 0;
	while (*dict != '\0')
	{
		while ((dict[i] == num[i]) && (num[i] != '\0'))
				i++;
		if (num[i] == '\0' && dict[i] == ':')
		{
			fin_pos = i + j + 1;
			return (fin_pos);
		}	
		else
		i = 0;
		j++;
		dict++;
	}
	return (fin_pos);
}

void	ft_search(char *dict, char *num, int i)
{
	int	con_d;

	con_d = 0;
	if (ft_len(num) == 1)
	{
		while (num[0] != dict[con_d])
			con_d++;
		con_d = con_d + 2;
	}
	else if (ft_len(num) == 2)
	{
		while (num[0] != dict[con_d] || num[1] != dict[con_d + 1])
			con_d++;
		con_d = con_d + 3;
	}
	else
		con_d = ft_biglen(dict, num);
	ft_writenum(dict, con_d);
	if (i != 0)
		write(1, " ", 1);
}
