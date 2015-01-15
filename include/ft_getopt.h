/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 22:56:53 by tseguier          #+#    #+#             */
/*   Updated: 2015/01/15 17:08:14 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETOPT_H
# define FT_GETOPT_H
#include "t_getopt.h"

t_getopt	ft_getoptnew(t_getopt_params params);
void		ft_getoptdel(t_getopt *getopt_p);
int			ft_getoptinit(t_getopt getopt, t_getopt_params params);
void		ft_getoptclr(t_getopt getopt);
int			ft_getopt(t_getopt getopt);
void		ft_tracegetopt(t_getopt getopt);

#endif
