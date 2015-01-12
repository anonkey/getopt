/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 22:56:54 by tseguier          #+#    #+#             */
/*   Updated: 2015/01/13 00:17:33 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_getopt.h"

static int	getopt_refresh(t_getopt)
{
	
}

int			ft_getopt(t_getopt getopt);
{
	if (getopt->ind < 1)
		return (-1);
	while (getopt->ind < getopt->argc && getopt->argv[getopt->ind]
			&& *(getopt->argv[getopt->ind]) != OPT_CHAR)
		++getopt->ind;
	if (getopt->ind == getopt->argc || !getopt->argv[getopt->ind]
		|| !ft_strcmp(getopt->argv[getopt->ind], ENDOPT_STR))
		return ((getopt->ind = -1));
	if (getopt->argv[getopt->ind][++getopt->pos])
		return (getopt_refresh(getopt));
	++getopt->ind;
	getopt->pos = 0;
	return (ft_getopt(getopt));
}
