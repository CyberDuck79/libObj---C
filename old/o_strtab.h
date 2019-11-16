/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_strtab.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:20:30 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/15 19:21:53 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "o_obj.h"

typedef enum	e_strtab
{
	NOERROR,
	FULL,
	OVERFLOW,
	WRITE
}				e_strtab;

/* voir plus tard pour regrouper certaines fonctions tab ? */
typedef struct	s_strtab
{
	/* destructeur */
	void		(*release)(struct s_strtab *this);
	/* getter */
	size_t		(*length)(struct s_strtab *this);
	size_t		(*size)(struct s_strtab *this);
	char		*(*at_index)(struct s_strtab *this, size_t index);
	/* setter */
	e_strtab	(*add)(struct s_strtab *this, char *str);
	e_strtab	(*add_at)(struct s_strtab *this, char *str, size_t index);
	e_strtab	(*remove)(struct s_strtab *this, char *str);		//TODO
	e_strtab	(*remove_at)(struct s_strtab *this, size_t index);	//TODO
	/* methodes */
	e_strtab	(*sort)(struct s_strtab *this);						//TODO
	e_strtab	(*reverse)(struct s_strtab *this);					//TODO
	e_strtab	(*write)(struct s_strtab *this, int fd, char separator);
	/* proprietes */
	t_private	*private;
}				o_strtab;

extern o_strtab	*new_strtab(size_t len);