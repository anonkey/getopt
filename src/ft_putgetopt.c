/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putgetopt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 17:00:32 by tseguier          #+#    #+#             */
/*   Updated: 2015/01/15 18:39:16 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "t_getopt.h"

void	ft_tracegetopt(t_getopt getopt)
{
	if (getopt->ind < 1)
		ft_putendl_fd("Erroneous or ended getopt", 2);
	else
		ft_dprintf(2, "Getopt: Ind: %d pos: %d argc: %d opt:%c param:%s \
act: %s err: %c genlist:%d\n",
					getopt->ind, getopt->pos, getopt->argc, getopt->opt, getopt->arg,
					getopt->argv[getopt->ind], getopt->err, getopt->genlist);
}
