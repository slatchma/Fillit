/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/10 01:26:20 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/14 15:57:49 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_checkandcpy(char *buf, int i, int backslashn)
{
	int			n;
	int			hasht;

	hasht = 0;
	n = i % 19;
	while (n <= 19)
	{
		if (buf[n] != '#' && buf[n] != '.' && buf[n] != '\n')
			return (0);
		if (buf[n] == '\n')
			backslashn++;
		if (buf[n] == '#' && hasht == 0)
		{
			if (!(hasht = ft_hashtcheck(buf, n)))
				return (0);
		}
		n++;
	}
	if (backslashn != 4 || hasht != 4)
		return (0);
	backslashn = 0;
	return (n);
}

static int		ft_pattern(char *buf)
{
	int			i;
	int			backslashn;
	int			counter;

	i = 0;
	backslashn = 0;
	counter = 0;
	while (i < 20)
	{
		if (buf[i] != '#' && buf[i] != '.' && buf[i] != '\n')
			return (0);
		if (buf[i] == '\n')
			backslashn++;
		else if (buf[i] == '#')
		{
			counter++;
			if (!(i = ft_checkandcpy(buf, i, backslashn)))
				return (0);
		}
		i++;
	}
	if (counter == 0)
		return (0);
	return (1);
}

t_llist			*ft_readandcheck(char **av, t_llist *lstpattern,
		int *result, int *comp)
{
	int			fd;
	int			ret;
	char		buf[BUF_SIZE + 1];
	char		separate[2];

	ret = -1;
	fd = open(av[1], O_RDONLY, S_IRUSR);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		if ((ret = read(fd, separate, 1)))
			*comp = *comp + 1;
		if ((ret && separate[0] != '\n') || buf[0] == '\n')
			return (NULL);
		if (*buf)
		{
			if ((ft_pattern(buf)) == 0)
				return (NULL);
			lstpattern = ft_lstend(lstpattern, *result, buf);
			*result = *result + 1;
		}
	}
	close(fd);
	return (lstpattern);
}

static int		ft_recursive(int sqm, char **solve, t_llist *lstpattern)
{
	int test;
	int result;

	test = 0;
	result = 0;
	while (test != 1)
	{
		sqm++;
		if (result == 1)
		{
			ft_delsolve(solve);
		}
		if (!(solve = (char**)(malloc(sizeof(char *) * (sqm + 1)))))
			return (0);
		solve = ft_dotinitialise(solve, sqm);
		test = ft_solve(solve, sqm, lstpattern, 0);
		result = 1;
	}
	ft_putsolve(solve);
	return (1);
}

int				main(int ac, char **av)
{
	t_llist		*lstpattern;
	int			sqm;
	char		**solve;
	int			result;
	int			comp;

	lstpattern = NULL;
	solve = NULL;
	result = 0;
	comp = 0;
	if (ac != 2)
	{
		ft_putstr("usage: ./fillit [Tetriminos file]\n");
		return (0);
	}
	if (!(lstpattern = ft_readandcheck(av, lstpattern, &result, &comp))
			|| (comp + 1) != result)
	{
		ft_putstr("error\n");
		return (0);
	}
	sqm = (ft_sqrtdecimal((result * 4)) - 1);
	if (sqm != 0)
		ft_recursive(sqm, solve, lstpattern);
	return (0);
}
