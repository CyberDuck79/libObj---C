/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:47:33 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/16 10:20:50 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "o_str.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/* tests unitaires */

int		main(void)
{
	t_str		*str;
	char		*value;
	//t_tab_str	*str_tab;
	//t_lst_str	*str_lst;

	/* Construction de l'objet de type t_str avec une chaine litterale */
	str = new_str("str = new_str(\"c'est partis mon kiki !\\n\");\n");
	write(1, str->value, str->len);

	/* Copie une valeur et libere l'espace memoire de l'ancienne valeur */
	str->copy_value(str, "str->copy_value(char*) : je peut mettre une chaine litterale.\n");
	write(1, str->value, str->len);

	/* Copie le pointeur et libère l'espace mémoire de l'ancienne valeur pointée */
	value = strdup("str->change_value(char*) : pas besoin de free ce pointer !\n");
	str->change_value(str, value);
	write(1, str->value, str->len);

	/* Joint deux chaines en copiant la valeur et en liberant l'espace memoire de l'ancienne valeur */
	str->join(str, "str->join(char*) : c'est pour ça que c'est en double en haut !\n");
	write(1, str->value, str->len);

	str->copy_value(str, "//::00//::str->trim(char*):://00:://");
	write(1, str->value, str->len);
	write(1, "\n", 1);
	write(1, str->trim(str, "/:0"), str->len);
	write(1, "\n", 1);

	/* Libère l'espace memoire de l'objet et met son pointeur à NULL */
	str->copy_value(str, "str->free(&str) : Destroy !\n");
	write(1, str->value, str->len);
	str->free(&str);
	
	//str_tab = str->to_tab(str, ' ');
	//str_lst = str->to_lst(str, ' ');
	return (0);
}