/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_obj.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:46:29 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/15 19:21:43 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

/* --- DECLARATION STRUCT DE PROPRIETES PRIVEE --- */

typedef struct	s_private t_private;

/* --- DECLARATION ERREUR --- */

typedef enum	e_error
{
	NO_ERROR,
	MALLOC,
	WRITE,
	RANGE,
	NO_CONTENT
}				t_error;
