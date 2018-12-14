/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_hashtcheck.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 16:21:34 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/14 15:56:18 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int			ft_hashtcheck(char *buf, int n)
{
	int link_hasht[2];

	link_hasht[0] = 0;
	link_hasht[1] = 0;
	while (n <= 19)
	{
		if (buf[n] == '#')
		{
			link_hasht[1] = link_hasht[1] + 1;
			if (buf[n - 1] == '#')
				link_hasht[0] = link_hasht[0] + 1;
			if (buf[n + 1] == '#')
				link_hasht[0] = link_hasht[0] + 1;
			if (buf[n - 5] == '#')
				link_hasht[0] = link_hasht[0] + 1;
			if (buf[n + 5] == '#')
				link_hasht[0] = link_hasht[0] + 1;
		}
		n++;
		if (n % 5 == 4 && buf[n] != '\n')
			return (0);
	}
	if (link_hasht[0] >= 6)
		return (link_hasht[1]);
	return (0);
}
