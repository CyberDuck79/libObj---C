/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_str.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 21:24:55 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/16 11:35:26 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef O_STR_H
# define O_STR_H

/* Header principale de l'objet */
# include <string.h> //----> refaire avec mes fonctions (strlen, strdup, strcpy)
# include <stdlib.h>
/* Header vers les types convertibles */
//# include "o_tab_str.h"
//# include "o_lst_str.h"

/* enum des retours d'erreur des méthodes */
typedef enum		e_str_error
{
	NOERROR,
	MALLOC,
	RANGE
}					t_str_error;

/* déclaration de l'objet */
typedef struct		s_str
{
	/* déclaration des propriétés de l'objet */
	size_t			len;
	char			*value;
	/* déclaration des pointeurs sur méthode de l'objet */
	void			(*free)(struct s_str **this);
	void			(*change_value)(struct s_str *this, const char *value);
	void			(*copy_value)(struct s_str *this, const char *value);
	char			*(*join)(struct s_str *this, const char *value);
	char			*(*rjoin)(struct s_str *this, const char *value);
	char			*(*trim)(struct s_str *this, const char *set);
	char			*(*sub_chr)(struct s_str *this, const char *set);
	char			*(*next_chr)(struct s_str *this, const char *set);
	int				(*next_line)(struct s_str *this, char **ret, const char *set);
	//t_tab_str		*(*to_tab)(struct s_str *this, const char *set);
	//t_lst_str		*(*to_lst)(struct s_str *this, const char *set);
}					t_str;

/* Déclaration du constructeur de l'objet */
extern t_str		*new_str(char *value);

#endif
