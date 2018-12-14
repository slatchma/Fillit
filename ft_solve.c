/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_solve.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 18:53:28 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/14 15:57:09 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_writetetri(char **solve, t_llist *lstpattern, int z, int sqm)
{
	int	i;
	int	j;
	int	tmpi;
	int	tmpj;

	i = 0;
	tmpi = z / sqm;
	while (lstpattern->carre[i][0] != '\0' && (i + tmpi < sqm))
	{
		j = 0;
		tmpj = z % sqm;
		while (lstpattern->carre[i][j] != '\0')
		{
			if (solve[tmpi + i][tmpj + j] == '.' && (j + tmpj < sqm))
			{
				solve[tmpi + i][tmpj + j] = lstpattern->carre[i][j];
			}
			j++;
		}
		i++;
	}
}

static void		ft_deltetri(char **solve, t_llist *lstpattern, int z, int sqm)
{
	int		i;
	int		j;
	int		tmpi;
	int		tmpj;
	char	c;

	i = 0;
	c = lstpattern->isalpha;
	tmpi = z / sqm;
	while (lstpattern->carre[i][0] != '\0' && (i + tmpi < sqm))
	{
		j = 0;
		tmpj = z % sqm;
		while (lstpattern->carre[i][j] != '\0')
		{
			if (solve[tmpi + i][tmpj + j] == c)
				solve[tmpi + i][tmpj + j] = '.';
			j++;
		}
		i++;
	}
}

static int		ft_checkpos(char **solve, t_llist *lstpattern, int z, int sqm)
{
	int i;
	int j;
	int tmpi;
	int tmpj;

	i = 0;
	tmpi = z / sqm;
	while (lstpattern->carre[i][0] != '\0')
	{
		j = 0;
		tmpj = z % sqm;
		while (lstpattern->carre[i][j] != '\0')
		{
			if ((j + tmpj > sqm - 1) || (i + tmpi) > sqm - 1)
				return (0);
			if (lstpattern->carre[i][j] != '.' &&
					solve[tmpi + i][tmpj + j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int				ft_solve(char **solve, int sqm, t_llist *lstpattern,
				int position)
{
	int result;

	result = 0;
	if (lstpattern == NULL)
		return (1);
	while (position < sqm * sqm)
	{
		if (ft_checkpos(solve, lstpattern, position, sqm))
		{
			ft_writetetri(solve, lstpattern, position, sqm);
			result = 1;
			if (ft_solve(solve, sqm, lstpattern->nxt, 0))
				return (1);
		}
		if (result == 1)
		{
			result = 0;
			ft_deltetri(solve, lstpattern, position, sqm);
		}
		position++;
	}
	return (0);
}
