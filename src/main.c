/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/18 23:56:12 by tseguier          #+#    #+#             */
/*   Updated: 2015/01/15 18:32:12 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getopt.h"

int		main(int argc, char **argv)
{
	t_getopt			opt;
	t_sgetopt_params	params;

	if (argc < 2 || !argv)
		return (-1);
	params.opstring = argv[1];
	params.usage = argv[1];
	params.argv = argv;
	params.argc = argc;
	params.genlist = 1;
	if (!(opt = ft_getoptnew(&params)))
		return (-1);
	while (-1 != ft_getopt(opt) && !opt->err)
		ft_tracegetopt(opt);
		ft_tracegetopt(opt);
	ft_putnbr(ft_ldcdsize(opt->arglist));
	ft_putldcd(opt->arglist, (t_putretgen)&ft_putendl);
	return (0);
}