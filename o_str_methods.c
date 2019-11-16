/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_str_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:46:15 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/16 11:28:56 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Inclure le header des méthodes */
#include "o_str_methods.h"

/*
	Méthode interne (non référencée dans l'objet) :
	Retourne l'index du char dans le set si char le set sinon -1.
*/
int					isset(const char c, const char *set)
{
	int	index;

	index = 0;
	while (set[index])
	{
		if (set[index] == c)
			return (index);
		index++;
	}
	return (-1);
}

/*
	Méthodes de l'objet :
	Ajoute la valeur d'entrée a la suite de la valeur interne.
	Libère l'ancienne valeur et retourne pointeur sur nouvelle valeur interne.
*/
char				*join_str(t_str *this, const char *value)
{
	size_t	value_len;
	size_t	join_len;
	char	*new_value;

	if (!this || !value || !*value)
		return (NULL);
	value_len = strlen(value);
	join_len = value_len + this->len;
	if (!(new_value = (char*)malloc((sizeof(char) * join_len) + 1)))
		return (NULL);
	if (this->value)
	{
		strcpy(new_value, this->value);
		free(this->value);
	}
	strcpy(new_value + this->len, value);
	this->value = new_value;
	this->len = join_len;
	return (new_value);
}

/*
	Méthodes de l'objet : 
	Ajoute la valeur d'entrée devant la valeur interne.
	Libère l'ancienne valeur et retourne pointeur sur nouvelle valeur interne.
*/
char				*rjoin_str(t_str *this, const char *value)
{
	size_t	value_len;
	size_t	join_len;
	char	*new_value;

	if (!this || !value || !*value)
		return (NULL);
	value_len = strlen(value);
	join_len = value_len + this->len;
	if (!(new_value = (char*)malloc((sizeof(char) * join_len) + 1)))
		return (NULL);
	strcpy(new_value, value);
	if (this->value)
	{
		strcpy(new_value + value_len, this->value);
		free(this->value);
	}
	this->value = new_value;
	this->len = join_len;
	return (new_value);
}

/*
	Méthode de l'objet :
	Nouvelle valeur sans le set de char au début et a la fin.
	Libère l'ancienne valeur et retourne pointeur sur nouvelle valeur interne.
*/
char				*trim_str(t_str *this, const char *set)
{
	size_t	index;
	size_t	len;
	char	*new_value;

	if (!this || !set || !*set)
		return (NULL);
	index = 0;
	while (isset(this->value[index], set) != -1)
		index++;
	if (!this->value[index])
	{
		free(this->value);
		this->value = strdup("");
		this->len = 0;
		return (this->value);
	}
	len = strlen(this->value + index);
	while (isset(this->value[len + index - 1], set) != -1)
		len--;
	if (!(new_value = (char*)malloc((sizeof(char) * len) + 1)))
		return (NULL);
	strncpy(new_value, this->value + index, len);
	free(this->value);
	this->value = new_value;
	this->len = len;
	return (this->value);
}
