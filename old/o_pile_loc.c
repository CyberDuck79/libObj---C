/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_pile_loc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 00:43:33 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/15 19:18:57 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "o_pile.h"
#include "o_pile_loc.h"

typedef struct			s_node
{
	void				*content;
	struct s_node		*next;
}						t_node;

typedef struct			s_Private
{
	t_node				*front;
	t_node				*back;
}						t_Private;

t_error		Add_end_list(t_List *this, void *content)
{
	t_node	*new = (t_node *)malloc(sizeof(t_node));
	t_node	**front = &this->Private->front;
	t_node	**back = &this->Private->back;

	if (new == (t_node *)NULL)
		return (MALLOC);
	if (!(new->content = content))
	{
		free(new);
		return (NO_CONTENT);
	}
	if (!(*back)->content)
	{
		
	}
	else
	{
		
	}
	this->length++;
	return (NO_ERROR);
}

t_error		Add_front_list(t_List *this, void *content)
{
	t_node	*new = (t_node *)malloc(sizeof(t_node));
	t_node	**front = &this->Private->front;
	t_node	**back = &this->Private->back;

	if (new == (t_node *)NULL)
		return (MALLOC);
	if (!(new->content = content))
	{
		free(new);
		return (NO_CONTENT);
	}
	if (!(*front)->content)
	{
		free(*front);
		*back = new;
		new->next = NULL;
	}
	else if (!(*back)->next)
	{
		*back = *front;
		(*back)->next = new;
		new->next = *front;
	}
	else
		new->next = *front;
	*front = new;
	this->length++;
	return (NO_ERROR);
}

t_error		Add_at_list(t_List *this, void *content, size_t index)
{
	size_t		local_index = 0;
	t_node	*tmp = this->Private->front;
	t_node	*new = (t_node *)malloc(sizeof(t_node));

	if (!new)
		return (MALLOC);
	else if (!(new->content = content))
	{
		free(new);
		return (NO_CONTENT);
	}
	else if (!index)
		return (Add_front_list(this, content));
	if ((index + 1) == this->length)
		return (Add_end_list(this, content));
	else if (index >= this->length)
		return (RANGE);
	while (tmp)
	{
		if (local_index == (index - 1))
		{
			new->next = tmp->next->next;
			tmp->next = new;
			this->length++;
			return (NO_ERROR);
		}
		tmp = tmp->next;
		local_index++;
	}
	return (RANGE);
}

t_error		Remove_list(t_List *this, void *content)
{
	t_node	*tmp = this->Private->front;
	t_node	*release;

	if (!content)
		return (NO_CONTENT);
	while (tmp)
	{
		if (tmp->content == content)
		{
			if (tmp->next)
				tmp->content = tmp->next->content;
			release = tmp;
			tmp = tmp->next;
			free(release->content);
			free(release);
			this->length--;
		}
		else
			tmp = tmp->next;
	}
	return (NO_ERROR);
}

t_error		Remove_end_list(t_List *this)
{
	t_node	*release;

	if (!(release = this->Private->front))
		return (RANGE);
	if (!release->next)
		return (Remove_start_list(this));
	while (release->next->next)
		release = release->next;
	free(release->next->content);
	free(release->next);
	release->next = NULL;
	this->length--;
	return (NO_ERROR);
}

t_error		Remove_start_list(t_List *this)
{
	t_node	*release;

	if (!(release = this->Private->front))
		return (RANGE);
	this->Private->front = this->Private->front->next;
	free(release->content);
	free(release);
	this->length--;
	return (NO_ERROR);
}

t_error		Remove_at_list(t_List *this, size_t index)
{
	t_node	*tmp = this->Private->front;
	t_node	*release;
	size_t		local_index = 0;

	if (!index)
		return (Remove_start_list(this));
	if ((index + 1) == this->length)
		return (Remove_end_list(this));
	else if (index >= this->length)
		return (RANGE);
	while (tmp)
	{
		if (local_index == (index - 1))
		{
			release = tmp->next;
			tmp->next = tmp->next->next;
			free(release->content);
			free(release);
			this->length--;
			return (NO_ERROR);
		}
		tmp = tmp->next;
		local_index++;
	}
	return (RANGE);
}

void		*Content_at_list(t_List *this, size_t index)
{
	t_node	*tmp = this->Private->front;
	size_t		local_index = 0;

	if (index >= this->length)
		return (NULL);
	while (tmp)
	{
		if (local_index == index)
			return (tmp->content);
		tmp = tmp->next;
		local_index++;
	}
	return (NULL);
}

void		*Content_end_list(t_List *this)
{
	return (this->Private->back->content);
}

void		*Content_start_list(t_List *this)
{
	return (this->Private->front->content);
}

void		Write(t_List *this, int fd, char separator)
{
	t_node	*tmp = this->Private->front;

	if (!tmp->content)
		return ;
	while (tmp != this->Private->back)
	{
		write(fd, tmp->content, strlen((char*)tmp->content));
		write(fd, &separator, 1);
		tmp = tmp->next;
	}
	write(fd, tmp->content, strlen((char*)tmp->content));
}