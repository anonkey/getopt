/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_getopt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 00:13:18 by tseguier          #+#    #+#             */
/*   Updated: 2015/01/15 17:19:59 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "t_getopt.h"
#include "libft.h"

void		ft_getoptclr(t_getopt getopt)
{
	ft_strtabdel(&(getopt->argv), 1);
	return ;
}

void		ft_getoptdel(t_getopt *getopt_p)
{
	if (!getopt_p)
		return ;
	ft_getoptclr(*getopt_p);
	ft_memdel((void **)getopt_p);
}

int			ft_getoptinit(t_getopt getopt, t_getopt_params params)
{
	if (!getopt || !params || !params->opstring || !params->argv)
		return (errno = EINVAL);
	ft_memcpy(getopt, params, sizeof(t_sgetopt_params));
	if (!(getopt->argv = ft_strtabcpy(getopt->argv, 0)))
		return (errno);
	getopt->ind = 1;
	return (0);
}

t_getopt	ft_getoptnew(t_getopt_params params)
{
	t_getopt	getopt;

	if (!(getopt = (t_getopt)ft_memalloc(sizeof(t_sgetopt))))
		return (NULL);
	if (ft_getoptinit(getopt, params))
		ft_getoptdel(&getopt);
	return (getopt);
}
