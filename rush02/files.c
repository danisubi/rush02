/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainga-ri <ainga-ri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 04:50:41 by ainga-ri          #+#    #+#             */
/*   Updated: 2022/04/17 22:21:24 by ainga-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_open(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Dict Error\n", 11);
		exit(0);
	}
	return (fd);
}

int	ft_read(int fd, char *buf, int size)
{	
	int	c;

	c = read(fd, buf, size);
	if (c == -1)
	{
		write(2, "Dict Error\n", 11);
		exit (0);
	}
	return (c);
}

void	ft_close(int fd)
{	
	if (close(fd) == -1)
	{
		write(2, "Dict Error\n", 11);
		exit(0);
	}
}

void	ft_convert(char *dest, char *src)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (src[i] != '\0')
	{
		if (src[i] != ' ' && src[i] != '\t')
		{
			dest[k] = src[i];
			k++;
		}
		i++;
	}
}
