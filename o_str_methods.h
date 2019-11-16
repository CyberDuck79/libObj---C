/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_str_methods.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:46:18 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/16 11:28:05 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef O_STR_METHODS_H
# define O_STR_METHODS_H

/* Inclure le header de l'objet */
# include "o_str.h"

/* Liste de propriétés privées indexées par pointeur sur objet */
typedef struct			s_str_line
{
	char				*line;
	size_t				next_line;
	struct s_str_priv	*next;
	t_str				*index;
}						t_str_line;

/* Declaration des méthodes de l'objet */
int						isset(const char c, const char *set);
char					*join_str(t_str *this, const char *value);
char					*rjoin_str(t_str *this, const char *value);
char					*trim_str(t_str *this, const char *set);
int						next_line(t_str *this, char **ret, const char *set);

#endif
