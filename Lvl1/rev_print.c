/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lliberal <lliberal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:05:36 by lliberal          #+#    #+#             */
/*   Updated: 2023/02/09 19:11:39 by lliberal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Assignment name  : rev_print
// Expected files   : rev_print.c
// Allowed functions: write
// ---------------------------
// Write a program that takes a string, and displays the string in reverse
// followed by a newline.

// If the number of parameters is not 1, the program displays a newline.

// Examples:

// $> ./rev_print "zaz" | cat -e
// zaz$
// $> ./rev_print "dub0 a POIL" | cat -e
// LIOP a 0bud$
// $> ./rev_print | cat -e
// $

#include <unistd.h>

int	main(int ar, char **av)
{
	int	i;

	i = 0;
	if (av == NULL)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (ar == 2)
	{
		while (av[1][i])
			i++;
		while (--i >= 0)
		{
			write(1, &av[1][i], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
