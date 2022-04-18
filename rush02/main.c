/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ainga-ri <ainga-ri@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 04:36:38 by ainga-ri          #+#    #+#             */
/*   Updated: 2022/04/17 22:36:10 by dsubiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

int		get_size(char *file);
char	*create_buf(char *buf, char *file, int size);
int		ft_open(char *file);
int		ft_read(int fd, char *buf, int size);
void	ft_close(int fd);
void	ft_array(char *str, char *res, int i);
void	reverse(char *str, char *buf);
void	ft_search(char *buf, char *str, int i);
int		ft_check(char *str);
int		ft_len(char *str);
int		ft_convert(char *dest, char *size);

int	main(int argc, char **argv)
{
	int		size;
	char	*buf;

	buf = "";
	if (argc > 1 && argc <= 3)
	{
		if (argc == 2 && ft_check(argv[1]))
		{
			size = get_size("numbers.dict");
			buf = create_buf(buf, "numbers.dict", size);
			reverse(argv[1], buf);
		}
		else if (ft_check(argv[2]))
		{
			size = get_size(argv[1]);
			buf = create_buf(buf, argv[1], size);
			reverse(argv[2], buf);
		}
		free(buf);
	}
	else
	{
		write(1, "Error", 5);
	}
	return (0);
}

int	get_size(char *file)
{
	ssize_t	size_b;
	int		c;
	char	dummy;
	int		fd;

	fd = ft_open(file);
	size_b = 1;
	c = 0;
	while (size_b != 0)
	{
		size_b = ft_read(fd, &dummy, 1);
		c++;
	}
	ft_close(fd);
	return (c);
}

char	*create_buf(char *buf, char *file, int size)
{
	int		fd;
	char	*fake_buf;

	buf = (char *)malloc (size);
	if (buf == NULL)
	{
		write(1, "Error", 5);
	}
	fake_buf = (char *)malloc (size);
	if (fake_buf == NULL)
	{
		write(1, "Error", 5);
	}
	fd = ft_open(file);
	ft_read(fd, fake_buf, size);
	ft_convert(buf, fake_buf);
	ft_close(fd);
	free(fake_buf);
	return (buf);
}

void	reverse(char *str, char *buf)
{
	int		a;
	int		i;
	int		j;
	char	*dest;

	dest = (char *)malloc (40);
	if (dest == NULL)
	{
		write(1, "Error", 5);
		exit (0);
	}
	a = 0;
	j = 0;
	while (str[a] != '\0')
			a++;
	i = a;
	a--;
	while (a >= 0)
	{
		dest[j] = str[a];
		a--;
		j++;
	}	
	ft_array(dest, buf, i);
	free(dest);
}

int	ft_check(char *ch_number)
{
	int		val;
	int		i;
	int		length;

	i = 0;
	val = 1;
	length = ft_len(ch_number);
	while (ch_number[i] != '\0' && val == 1)
	{
		if (!((ch_number[i] >= '0' && ch_number[i] <= '9')
				|| ch_number[i] == ' ' || ch_number[i] == '\t'))
		{
			val = 0;
			write(1, "Error\n", 6);
			exit (0);
		}
		if (length > 39)
		{
			val = 0;
			write(1, "Error Dict\n", 11);
			exit (0);
		}
		i++;
	}
	return (val);
}
