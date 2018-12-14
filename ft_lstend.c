/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstend.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 20:01:21 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/14 18:34:16 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_tabfirst(int *tab, int n)
{
	tab[0] = n / 5;
	tab[1] = n / 5;
	tab[2] = n % 5;
	tab[3] = n % 5;
}

void	ft_tablst(char *buf, int *tab)
{
	int n;
	int hasht;

	n = 0;
	hasht = -1;
	while (n <= 19)
	{
		if (buf[n] == '#')
		{
			if (++hasht == 0)
				ft_tabfirst(tab, n);
			else
			{
				if (n / 5 < tab[0])
					tab[0] = n / 5;
				if (n / 5 > tab[1])
					tab[1] = n / 5;
				if (n % 5 < tab[2])
					tab[2] = n % 5;
				if (n % 5 > tab[3])
					tab[3] = n % 5;
			}
		}
		n++;
	}
}

t_llist	*ft_writepatt_two(int *k_l_val_n, t_llist *maillon, int *tab, char *buf)
{
	if ((k_l_val_n[3] % 5) >= tab[2] && (k_l_val_n[3] % 5) <= tab[3])
	{
		maillon->carre[k_l_val_n[0]][k_l_val_n[1]] = buf[k_l_val_n[3]];
		if (buf[k_l_val_n[3]] == '#')
			maillon->carre[k_l_val_n[0]][k_l_val_n[1]] = 'A' + k_l_val_n[2];
		k_l_val_n[1] = k_l_val_n[1] + 1;
	}
	if ((k_l_val_n[3] % 5) == tab[3])
	{
		maillon->carre[k_l_val_n[0]][k_l_val_n[1]] = '\0';
		k_l_val_n[1] = 0;
		k_l_val_n[0] = k_l_val_n[0] + 1;
	}
	return (maillon);
}

t_llist	*ft_writepatt(char *buf, t_llist *maillon, int *tab, int val)
{
	int backslash;
	int k_l_val_n[4];

	k_l_val_n[0] = 0;
	k_l_val_n[1] = 0;
	k_l_val_n[2] = val;
	k_l_val_n[3] = 0;
	backslash = 0;
	while (buf[k_l_val_n[3]] != '\0')
	{
		if (buf[k_l_val_n[3]] == '\n')
			backslash++;
		if (backslash >= tab[0] && backslash <= tab[1])
		{
			ft_writepatt_two(k_l_val_n, maillon, tab, buf);
		}
		k_l_val_n[3] = k_l_val_n[3] + 1;
	}
	maillon->carre[k_l_val_n[0]][0] = '\0';
	return (maillon);
}

t_llist	*ft_lstend(t_llist *liste, int val, char *buf)
{
	t_llist	*maillon;
	t_llist	*tmp;
	int		tab[4];

	maillon = (t_llist*)malloc(sizeof(t_llist));
	ft_tablst(buf, tab);
	maillon = ft_writepatt(buf, maillon, tab, val);
	maillon->var = val;
	maillon->isalpha = 'A' + val;
	maillon->nxt = NULL;
	if (liste == NULL)
	{
		return (maillon);
	}
	else
	{
		tmp = liste;
		while (tmp->nxt != NULL)
		{
			tmp = tmp->nxt;
		}
		tmp->nxt = maillon;
		return (liste);
	}
}
