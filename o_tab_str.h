/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_tab_str.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 21:40:18 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/16 09:21:01 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef O_TAB_STR_H
# define O_TAB_STR_H

# include <string.h>
# include <stdlib.h>
//# include "o_str.h"

/* déclaration de l'objet */
typedef struct		s_tab_str
{
	/* déclaration des propriétés de l'objet */
	size_t			len;
	size_t			size;
	char			**value;
	/* déclaration des pointeurs sur méthode de l'objet */
	//void			(*free)(const struct s_tab_str *this);
	//t_str_error		(*change_value)(const struct s_tab_str *this, const char *value);
	//t_str_error		(*copy_value)(const struct s_tab_str *this, const char *value);
}					t_tab_str;

/* Déclaration du constructeur de l'objet */
//extern t_tab_str	*new_tab_str(char **value);

#endif
