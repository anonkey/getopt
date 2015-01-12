/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_getopt.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 22:56:53 by tseguier          #+#    #+#             */
/*   Updated: 2015/01/12 23:46:43 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_GETOPT_H
# define T_GETOPT_H
# define OPT_CHAR '-'
# define ENDOPT_STR '-'

typedef int (*t_optcmp_fn)(char *, char *);

typedef struct		s_getopt_params
{
	char			**argv;
	int				argc;
	char			*opstring;
	char			*usage;
	t_optcmp_fn		cmp;
}					t_sgetopt_params;

typedef t_sgetopt_params		*t_getopt_params;

typedef struct		s_getopt
{
	t_getopt_param	params;
	char			*arg;
	int				ind;
	char			opt;
	char			err;
}					t_sgetopt;

typedef t_sgetopt		*t_getopt;

#endif /* !T_GETOPT_H */
