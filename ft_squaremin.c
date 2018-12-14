/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_squaremin.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/30 16:19:07 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/14 15:57:34 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int			ft_squaremin(int patnbr)
{
	int		squaremin[26];

	if (patnbr == 1)
		squaremin[patnbr] = 2;
	else if (patnbr == 2)
		squaremin[patnbr] = 3;
	else if (patnbr == 3 || patnbr == 4)
		squaremin[patnbr] = 4;
	else if (patnbr == 5 || patnbr == 6)
		squaremin[patnbr] = 5;
	else if (patnbr == 7 || patnbr == 8 || patnbr == 9)
		squaremin[patnbr] = 6;
	else if (patnbr == 10 || patnbr == 11 || patnbr == 12)
		squaremin[patnbr] = 7;
	else if (patnbr == 13 || patnbr == 14 || patnbr == 15 || patnbr == 16)
		squaremin[patnbr] = 8;
	else if (patnbr == 17 || patnbr == 18 || patnbr == 19 || patnbr == 20)
		squaremin[patnbr] = 9;
	else if (patnbr == 21 || patnbr == 22 || patnbr == 23 || patnbr == 24
		|| patnbr == 25)
		squaremin[patnbr] = 10;
	else if (patnbr == 26)
		squaremin[patnbr] = 11;
	return (squaremin[patnbr]);
}
