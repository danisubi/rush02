/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsubiran <dsubiran@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 22:41:58 by dsubiran          #+#    #+#             */
/*   Updated: 2022/04/17 22:42:09 by dsubiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <unistd.h>

void	ft_search(char *buf, char *str, int i);

void	putn0(int i, char *buf)
{
	int		a;
	char	res[42];

	a = 0;
	while (a <= i)
	{
		if (a == 0)
			res[a] = '1';
		else
			res[a] = '0';
		a++;
	}
	res[a] = '\0';
	ft_search(buf, res, i);
}

void	mod0(char *str, int i, char *buf)
{
	int		a;
	char	res[42];

	a = 0;
	if (i != 0 && str[i] != '0' && str[i + 1] != '1')
	{
		res[a] = str[i];
		res[++a] = '\0';
		ft_search(buf, res, i);
	}
	else if (str[i +1] == '1')
	{
		res[a++] = '1';
		res[a] = str[i];
		res[++a] = '\0';
		ft_search(buf, res, i);
	}
	else if (str[i] != '0')
	{
		res[a] = str[i];
		res[++a] = '\0';
		ft_search(buf, res, i);
	}
	if (i != 0 && str[i + 2] != '0')
		putn0(i, buf);
}

void	mod1(char n, char *buf, int i)
{
	char	res[5];

	res[0] = n;
	res[1] = '0';
	res[2] = '\0';
	ft_search(buf, res, i);
}

void	mod3(char n, char *buf, int i)
{
	char	res[2];

	res[0] = n;
	res[1] = '\0';
	ft_search(buf, res, i);
	putn0(2, buf);
}

void	ft_array(char *str, char *buf, int i)
{
	char	res[2];

	if (i > 1)
	{
		i--;
		while (i >= 0)
		{
			if (i % 3 == 0)
				mod0(str, i, buf);
			else if (i % 3 == 1 && str[i] > '1')
				mod1(str[i], buf, i);
			else if (i % 3 == 2 && str[i] > '0')
				mod3(str[i], buf, i);
			i--;
		}
	}
	else
	{
		i--;
		res[0] = str[i];
		res[1] = '\0';
		ft_search(buf, res, i);
	}
	write(1, "\n", 1);
}
