/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_str.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:26:20 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/15 19:40:46 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "o_obj.h"

typedef struct	s_str
{
	void	(*free)(const struct s_str *this);
	char	obj[sizeof(unsigned long)];
}				o_str;
