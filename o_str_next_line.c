/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_str_next_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 11:26:08 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/16 11:27:09 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclure le header des méthodes */
#include "o_str_methods.h"

/* Liste de propriétés privées indexées par pointeur sur objet */
static t_str_line	*g_priv_lst;

static t_str_line		*new_str_line(t_str *this)
{
	t_str_line	*new;

	if (!(new = (t_str_line*)malloc(sizeof(t_str_line))))
			return (NULL);
	new->index = this;
	new->line = NULL;
	new->next = g_priv_lst;
	new->next_line = 0;
	return (new);
}

static t_str_line		*get_str_line(t_str *this)
{
	t_str_line	*tmp;

	tmp = g_priv_lst;
	while (tmp)
	{
		if (tmp->index == this)
			return (tmp);
		tmp = tmp->next;
	}
	g_priv_lst = new_str_line(this);
	return (g_priv_lst);
}

int						next_line(t_str *this, char **ret, const char *set)
{
	t_str_line	*line_lst;
	char		*next;

	if (!this || !ret || !set)
		return (-1);
	line_lst = get_str_line(this);
	// faire un subsrtchr et substrrchr en interne
}