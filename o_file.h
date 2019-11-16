/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_file.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:55:40 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/16 09:22:27 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef O_FILE_H
# define O_FILE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

/* enum d'options */
typedef enum	e_open_flag
{
	RD_ONLY,
	WR_ONLY,
	CREATE
}				t_open_flag;

/* déclaration de l'objet */
typedef struct	s_file
{
	/* déclaration des propriétés de l'objet */
	int		fd;
	int		buffer_size;
	int		count;
	char	*value;
	/* déclaration des pointeurs sur méthode de l'objet */
	void	(*free)(struct s_file *this);
	char	*(*get_line)(struct s_file *this, const char *set);
	//t_tab_str		*(*to_tab)(const struct s_str *this, const char *set);
	//t_lst_str		*(*to_lst)(const struct s_str *this, const char *set);
	int		(*open_new)(struct s_file *this, const char *path, t_open_flag flag);
	void	(*close)(struct s_file *this);
}				t_file;

/* Déclaration du constructeur de l'objet */
extern t_file	*new_file(char *path, t_open_flag flag);

#endif
