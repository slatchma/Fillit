/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_delsolve.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/10 04:20:42 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/14 15:55:53 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_delsolve(char **solve)
{
	int i;

	i = 0;
	while (solve[i] != NULL)
	{
		free(solve[i]);
		i++;
	}
	free(solve[i]);
	free(solve);
}
