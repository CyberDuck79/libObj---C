/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_str.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 22:04:12 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/16 10:59:45 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclure les headers de l'objet et des méthodes */
#include "o_str.h"
#include "o_str_methods.h"

/* Destructeur de l'objet */
static void	free_str(t_str **this)
{
	if (!this || !*this)
		return ;
	free((*this)->value);
	free(*this);
	*this = NULL;
}

/* Méthodes de l'objet : remplacer le pointeur sur valeur */
static void	change_value_str(t_str *this, const char *value)
{
	if (!this || !value)
		return ;
	if (this->value)
		free(this->value);
	this->value = (char*)value;
	this->len = strlen(this->value);
}

/* Méthodes de l'objet : copier la nouvelle valeur */
static void	copy_value_str(t_str *this, const char *value)
{
	if (!this || !value)
		return ;
	if (this->value)
		free(this->value);
	this->value = strdup(value);
	this->len = strlen(this->value);
}

/* Assignation des méthodes de l'objet */
static void	set_methods(t_str *this)
{
	this->free = free_str;
	this->change_value = change_value_str;
	this->copy_value = copy_value_str;
	this->join = join_str;
	this->rjoin = rjoin_str;
	this->trim = trim_str;
}

/* Constructeur de l'objet */
t_str		*new_str(char *value)
{
	t_str	*new;

	if (!(new = (t_str*)malloc(sizeof(t_str))))
		return (NULL);
	if (!value)
	{
		new->len = 0;
		new->value = NULL;
	}
	else
	{
		new->len = strlen(value);
		new->value = strdup(value);
	}
	set_methods(new);
	return (new);
}