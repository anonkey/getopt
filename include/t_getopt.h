/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_getopt.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 22:56:53 by tseguier          #+#    #+#             */
/*   Updated: 2015/01/15 17:11:00 by tseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_GETOPT_H
# define T_GETOPT_H
# define OPT_CHAR '-'
# define BAD_OPT '?'
# define MISSING_PARAM ':'

typedef int (*t_optcmp_fn)(char *, char *);

typedef struct		s_getopt_params
{
	char			**argv;
	int				argc;
	char			*opstring;
	char			*usage;
}					t_sgetopt_params;

typedef t_sgetopt_params		*t_getopt_params;

typedef struct		s_getopt
{
	char			**argv;
	int				argc;
	char			*opstring;
	char			*usage;
	int				ind;
	int				pos;
	char			opt;
	char			*arg;
	char			err;
}					t_sgetopt;

typedef t_sgetopt				*t_getopt;

#endif
