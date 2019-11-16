/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_pile_loc.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 00:45:21 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/13 14:11:10 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

t_error	Add_end_list(t_List *this, void *content);
t_error	Add_front_list(t_List *this, void *content);
t_error	Add_at_list(t_List *this, void *content, size_t index);
t_error	Remove_list(t_List *this, void *content);
t_error	Remove_end_list(t_List *this);
t_error	Remove_start_list(t_List *this);
t_error	Remove_at_list(t_List *this, size_t index);
void	*Content_end_list(t_List *this);
void	*Content_start_list(t_List *this);
void	*Content_at_list(t_List *this, size_t index);
void	Write(t_List *this, int fd, char separator);
