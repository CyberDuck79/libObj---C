/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_pile.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:22:36 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/15 19:18:52 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "o_obj.h"

typedef struct	s_node t_node;

typedef struct	s_List
{
	void		(*Free)(struct s_List **this, void (*del)(void *elem));
	t_error		(*Add_end)(struct s_List *this, void *content);
	t_error		(*Add_front)(struct s_List *this, void *content);
	t_error		(*Add_at)(struct s_List *this, void *content, size_t index);
	t_error		(*Remove)(struct s_List *this, void *content);
	t_error		(*Remove_at)(struct s_List *this, size_t index);
	t_error		(*Remove_end)(struct s_List *this);
	t_error		(*Remove_start)(struct s_List *this);
	void		*(*Content_at)(struct s_List *this, size_t index);
	void		*(*Content_end)(struct s_List *this);
	void		*(*Content_start)(struct s_List *this);
	void		(*Write)(struct s_List *this, int fd, char separator);
	//void		(*Write_at)(struct s_List *this, int fd, size_t index);
	//void		(*Clear)(struct s_List *this);
	//void		(*Reverse)(struct s_List *this);
	//void		(*Sort)(struct s_List *this);
	t_Private	*Private;
	size_t		length;
}				t_List;

extern t_List *New_list(void *content);
