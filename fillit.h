/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vsteyaer <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/14 15:51:23 by vsteyaer     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/14 21:10:48 by vsteyaer    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 20
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct		s_llist
{
	int				var;
	char			isalpha;
	char			carre[5][5];
	struct s_llist	*nxt;
}					t_llist;

void				ft_putchar(char c);
void				ft_putstr(char *str);
t_llist				*ft_lstend(t_llist *liste, int val, char *buf);
int					ft_hashtcheck(char *buf, int n);
int					ft_squaremin(int patnbr);
int					ft_solve(char **solve, int sqm, t_llist *lstpattern,
					int position);
int					ft_sqrtdecimal(int nb);
void				ft_putsolve(char **solve);
void				ft_delsolve(char **solve);
char				**ft_dotinitialise(char **tab, int sqm);
#endif
