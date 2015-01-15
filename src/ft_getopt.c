/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 22:56:54 by tseguier          #+#    #+#             */
/*   Updated: 2015/01/15 18:37:43 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_getopt.h"
#include "libft.h"

static char	opterror(t_getopt getopt, char error)
{
		if (error == BAD_OPT)
			ft_dprintf(2, "%s: illegal option -- %c\n", getopt->argv[0],
						getopt->argv[getopt->ind][getopt->pos]);
		else if (error == MISSING_PARAM)
			ft_dprintf(2, "%s: missing parameter for -- %c\n", getopt->argv[0],
						getopt->argv[getopt->ind][getopt->pos]);
		if (getopt->usage)
			ft_dprintf(2, "usage: %s %s", getopt->argv[0], getopt->usage);
		return (error);
}

static int	getopt_refresh(t_getopt getopt)
{
	char	*opt;

	if (!(opt = ft_strchr(getopt->opstring,
			getopt->argv[getopt->ind][getopt->pos])))
		return (getopt->err = opterror(getopt, BAD_OPT));
	if (opt[1] == MISSING_PARAM)
	{
		if (getopt->argv[getopt->ind][getopt->pos + 1]
			|| getopt->ind + 1 >= getopt->argc)
			return ((getopt->err = opterror(getopt, MISSING_PARAM)));
		getopt->arg = getopt->argv[++getopt->ind];
		getopt->pos = 0;
		++getopt->ind;
	}
	getopt->opt = *opt;
	return (0);
}

int			ft_getopt(t_getopt getopt)
{
	if (getopt->ind < 1)
		return (-1);
	while (getopt->ind < getopt->argc && getopt->argv[getopt->ind]
			&& *(getopt->argv[getopt->ind]) != OPT_CHAR)
	{
		if (getopt->genlist)
			ft_ldcdpush_back(getopt->arglist, getopt->argv[getopt->ind], 0);
		++getopt->ind;
	}
	if (getopt->ind == getopt->argc || !getopt->argv[getopt->ind]
		|| getopt->argv[getopt->ind][1] == OPT_CHAR)
		return ((getopt->ind = -1));
	if (getopt->argv[getopt->ind][++getopt->pos])
		return (getopt_refresh(getopt));
	++getopt->ind;
	getopt->pos = 0;
	return (ft_getopt(getopt));
}
