#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <string>


using namespace std;

/** @brief la classe de base pour la creation des medias.
 */
class Media
{
protected:
    string objName;
    string path;
public:
    /**
     * @brief Media - Constructeur sans parametres.("Untitled")
     */
    Media();
    /**
     * @brief Media - Constructeur avec parametres.
     * @param objName - representant le nom de l'objet.
     * @param path
     */
    Media(string objName, string path);
    virtual ~Media();
    /// Cette fonction est accesseur pour le nom d'objet.
    string getObjName() const;
    /**
     * @brief Cette fonction est accesseur pour le nom du fichier.
     * Il s'agit du chemin complet permettant d'accéder au fichier.
     */
    string getPath() const;
    /**
     * @brief Cette fonction est un modifieur pour le nom d'objet.
     * @param string - Le nouveau nom d'objet.
     */
    void setObjName(string);
    /**
     * @brief Cette fonction est un modifieur pour le fichier.
     * @param string - le nouveau nom du fichier.
     */
    void setPath(string);
    /**
     * @brief Cette fonction est pour l'affichage des objets.
     * Elle est virtuelle
     * @param s - un flux générique de sortie
     */
    virtual void aff(ostream & s) const ; // fonction d'affichage

    /**
     * @brief Cette fonction donne le nom de la classe correspondante
     */
    virtual string type() const = 0;
    /**
     * @brief Cette methode est utilise pour jouer le media.
     * La classe media n'est pas instancie a cause de cette methode abstraite
     */
    virtual void joue() const = 0;

};

#endif // MEDIA_H
