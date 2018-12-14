/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dotinitialise.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 14:40:15 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/14 18:33:35 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_dotinitialise(char **tab, int sqm)
{
	int			i;
	int			j;

	i = 0;
	while (i < sqm)
	{
		j = 0;
		if (!(tab[i] = (char*)(malloc(sizeof(char) * (sqm + 1)))))
			return (NULL);
		while (j < sqm)
		{
			tab[i][j] = '.';
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
