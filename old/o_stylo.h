/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_stylo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:33:56 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/11 19:51:16 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "o_obj.h"

/* --- DESCRIPTION DES VALEURS PUBLIQUES --- */

typedef enum	e_Couleur
{
	ROUGE,
	VERT,
	BLEU
}				t_Couleur;

/* --- DESCRIPTION DE LA CLASSE STYLO --- */

typedef struct	s_Stylo
{
	/* le destructeur */
	void (*Liberer)(struct s_Stylo **this);
	/* les méthodes */
	void (*Ecrire)(struct s_Stylo *this, char *texte);
	void (*Change_couleur)(struct s_Stylo *this, t_Couleur couleur);
	t_Couleur (*Lire_couleur)(struct s_Stylo *this);
	/* les propriétés privés */
	t_Private *Private;
	/* des propriétés publique si besoin */
}				t_Stylo;

extern t_Stylo *Instancier_stylo(t_Couleur);
