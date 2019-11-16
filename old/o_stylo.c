/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_stylo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:35:24 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/11 20:13:30 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "o_stylo.h"

/* --- DESCRIPTION DES VALEURS DEFAUTS PRIVEES --- */

static char		encre[] = "CHINE";

/* --- DESCRIPTION DES PROPRIETES PRIVEES --- */

typedef struct	s_Private
{
	t_Couleur	couleur;
	const char	*encre; /* constante */
	void		(*Lire_encre)(struct s_Stylo *this); /* methodes privees */
}				t_Private;

/* --- DESCRIPTION DES FONCTIONS ASSOCIEES AUX METHODES PRIVEES--- */

static void			Lire_encre_stylo(t_Stylo *this)
{
	printf("Encre : %s\n", this->Private->encre);
	return ;
}

/* --- DESCRIPTION DES FONCTIONS ASSOCIEES AUX METHODES PUBLIQUES--- */

static void			Ecrire_stylo(t_Stylo *this,char *texte)
{
	printf("Texte : \"%s\" couleur : %i\n", texte, this->Private->couleur);
	Lire_encre_stylo(this);
	return ;
}

static void			Change_couleur_stylo(t_Stylo *this, t_Couleur couleur)
{
	this->Private->couleur = couleur;
	return ;
}

static t_Couleur	Lire_couleur_stylo(t_Stylo *this)
{
	return (this->Private->couleur);
}

/* le destructeur */
static void			Liberer_stylo(t_Stylo **this)
{
	free((*this)->Private);
	free(*this);
	*this = (t_Stylo *)NULL;
	return ;
}

/* le constructeur */
t_Stylo				*Instancier_stylo(t_Couleur i_Couleur)
{
	/* allocation d'une instance */
	t_Stylo	*this;
	this = (t_Stylo *)malloc(sizeof(t_Stylo));
	if (this == (t_Stylo *)NULL)
		return ((t_Stylo *)NULL);
	this->Private = (t_Private *)malloc(sizeof(t_Private));
	if (this->Private == (t_Private *)NULL)
	{
		free(this);
		return ((t_Stylo *)NULL);
	}
	/* affectation des méthodes publiques */
	this->Ecrire = Ecrire_stylo;
	this->Change_couleur = Change_couleur_stylo;
	this->Lire_couleur = Lire_couleur_stylo;
	this->Liberer = Liberer_stylo;
	/* affectation des méthodes privees */
	this->Private->Lire_encre = Lire_encre_stylo;
	/* initialisation des propriétés publiques*/
	/* initialisation des propriétés privees */
	this->Private->couleur = i_Couleur;
	this->Private->encre = encre;
	/* retour de l'objet instancié */
	return (this);
}