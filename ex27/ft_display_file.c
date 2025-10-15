/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:46:24 by viceda-s          #+#    #+#             */
/*   Updated: 2025/06/03 23:32:15 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 4096

void	ft_putstr_fd(char *str, int fd)
{
	while (*str)
		write(fd, str++, 1);
}

int	main(int argc, char **argv)
{
	int		fd;
	ssize_t	bytes;
	char	buffer[BUF_SIZE];

	if (argc < 2)
		return (write(2, "File name missing.\n", 19), 1);
	if (argc > 2)
		return (write(2, "Too many arguments.\n", 20), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (write(2, "Cannot read file.\n", 18), 1);
	bytes = read(fd, buffer, BUF_SIZE);
	while (bytes > 0)
	{
		write(1, buffer, bytes);
		bytes = read(fd, buffer, BUF_SIZE);
	}
	close(fd);
	return (0);
}
