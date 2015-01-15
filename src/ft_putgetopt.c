/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putgetopt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 17:00:32 by tseguier          #+#    #+#             */
/*   Updated: 2015/01/15 17:16:43 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "t_getopt.h"

void	ft_tracegetopt(t_getopt getopt)
{
		ft_dprintf(2, "Getopt: Ind: %d opt:%c param:%s act: %s err: %c\n",
					getopt->ind, getopt->opt, getopt->arg,
					getopt->argv[getopt->ind], getopt->err);
}
