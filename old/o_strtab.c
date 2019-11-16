/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_strtab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:22:41 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/15 19:21:17 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "o_strtab.h"
#include <string.h>

typedef struct	s_private
{
	char		**tab;
	char		*end;
	size_t		length;
	size_t		size;
}				t_private;

static void		release_strtab(o_strtab *this)
{
	size_t	index = 0;

	free(this->private->tab);
	free(this->private);
	free(this);
}

static size_t	length_strtab(o_strtab *this)
{
	return (this->private->length);
}

static size_t	size_strtab(o_strtab *this)
{
	return (this->private->size);
}

static char		*at_index_strtab(o_strtab *this, size_t index)
{
	if (index >= length_strtab(this))
		return (OVERFLOW);
	return (this->private->tab[index]);
}

static e_strtab	add_strtab(o_strtab *this, char *str)
{
	if (this->private->size < this->private->length)
	{
		this->private->end = str;
		this->private->tab[this->private->size++] = str;
		return (NOERROR);
	}
	return (FULL);
}

static e_strtab	add_at_strtab(o_strtab *this, char *str, size_t index)
{
	size_t l_index = size_strtab(this);
	
	if (index >= length_strtab(this))
		return (OVERFLOW);
	if (size_strtab(this) < length_strtab(this))
	{
		this->private->end = at_index_strtab(this, l_index);
		while (l_index > index)
		{
			this->private->tab[l_index] = this->private->tab[l_index - 1];
			l_index--;
		}
		this->private->tab[l_index] = str;
		this->private->size++;
		return (NOERROR);
	}
	return (FULL);
}

static e_strtab	remove(o_strtab *this, char *str)
{
	size_t	index = size_strtab(this);
	char	*tmp = at_index_strtab(this, index - 1);

	while (index > 0)
	{
		if (!strcmp(str, tmp))
		{
			while (index != size_strtab(this))
			{
				this->private->tab[index - 1] = this->private->tab[index];
				index++;
			}
			this->private->tab[index - 1] = NULL;
			
		}
		index--;
		tmp = at_index_strtab(this, index - 1);
	}
}

static e_strtab	write_strtab(o_strtab *this, int fd, char separator)
{
	size_t	index = 0;
	char	*tmp;
	while (index < size_strtab(this) - 1)
	{
		tmp = at_index_strtab(this, index);
		if (write(fd, tmp, strlen(tmp)) < 0)
			return (WRITE);
		if (write(fd, &separator, 1) < 0)
			return (WRITE);
		index++;
	}
	tmp = at_index_strtab(this, index);
	if (write(fd, tmp, strlen(tmp)) < 0)
		return (WRITE);
	return (NOERROR);
}

static void		set_functions(o_strtab *new)
{
	new->release = release_strtab;
	new->add = add_strtab;
	new->add_at = add_at_strtab;
	new->at_index = at_index_strtab;
	//new->remove = remove_tabstr;
	//new->remove_at = remove_at_tabstr;
	//new->sort = sort_tabstr;
	//new->reverse = reverse_tabstr;
	new->length = length_strtab;
	new->size = size_strtab;
	new->write = write_strtab;
}

o_strtab		*new_strtab(size_t length)
{
	o_strtab	*new = (o_strtab*)malloc(sizeof(o_strtab));

	if (!new)
		return (NULL);
	if (!(new->private = (o_private*)malloc(sizeof(o_private))))
	{
		free(new);
		return (NULL);
	}
	if (!(new->private->tab = (char**)malloc(sizeof(char*) * length)))
	{
		free(new->private);
		free(new);
		return (NULL);
	}
	new->private->length = length;
	while (length--)
		new->private->tab[length] = NULL;
	new->private->size = 0;
	new->private->end = *new->private->tab;
	set_functions(new);
	return (new);
}