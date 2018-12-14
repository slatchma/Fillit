/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: slatchma <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 22:46:22 by slatchma     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/12 14:42:09 by slatchma    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
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

t_llist				*ft_lstend(t_llist *liste, int val, char *buf);
int					ft_hashtcheck(char *buf, int n);
void				ft_putstr(char *str);
int					ft_squaremin(int patnbr);
int					ft_solve(char **solve, int sqm, t_llist *lstpattern,
					int position);
int					ft_sqrtdecimal(int nb);
void				ft_putchar(char c);
void				ft_putsolve(char **solve);
void				ft_delsolve(char **solve);
char				**ft_dotinitialise(char **tab, int sqm);
#endif
