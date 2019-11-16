/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_pile.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:22:49 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/13 14:21:04 by fhenrion         ###   ########.fr       */
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

static void	free_list(t_List **this, void (*del)(void *content))
{
	t_node	*tmp;

	while ((*this)->Private->front->next)
	{
		tmp = (*this)->Private->front->next;
		del((*this)->Private->front->content);
		free((*this)->Private->front);
		(*this)->Private->front = tmp;
	}
	del((*this)->Private->front->content);
	free((*this)->Private->front);
	free((*this)->Private);
	free((*this));
	*this = (t_List *)NULL;
	return ;
}

static void	assign_functions(t_List *this)
{
	this->Free = free_list;
	this->Add_end = Add_end_list;
	this->Add_front = Add_front_list;
	this->Add_at = Add_at_list;
	this->Remove = Remove_list;
	this->Remove_at = Remove_at_list;
	this->Remove_end = Remove_end_list;
	this->Remove_start = Remove_start_list;
	this->Content_at = Content_at_list;
	this->Content_end = Content_end_list;
	this->Content_start = Content_start_list;
	this->Write = Write;
}

t_List		*New_list(void *content)
{
	t_List	*this;

	if (!(this = (t_List *)malloc(sizeof(t_List))))
		return ((t_List *)NULL);
	if (!(this->Private = (t_Private *)malloc(sizeof(t_Private))))
	{
		free(this);
		return ((t_List *)NULL);
	}
	if (!(this->Private->front = (t_node *)malloc(sizeof(t_node))))
	{
		free(this->Private);
		free(this);
		return ((t_List *)NULL);
	}
	assign_functions(this);
	this->Private->front->content = content;
	this->Private->front->next = NULL;
	this->Private->back = this->Private->front;
	this->length = content ? 1 : 0;
	return (this);
}
