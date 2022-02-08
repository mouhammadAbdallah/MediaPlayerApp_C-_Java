#ifndef FILM_H
#define FILM_H
#include "video.h"

/**
 * @brief une classe derivee de la classe video.
 * films.
 */
class Film: public Video
{
private:
    int nbChap;
    int * tabDuree;
    /**
     * @brief Film - Constructeur avec les valeurs par defaut.
     * @param objName - Le nom de l'objet.
     * @param path - Le fichier.
     * @param duree - La table des durees des chapitres du film.
     * @param taille - La taille de la table.
     * @details Pour eviter l'instanciation de cette classe dans main,
     * on peut mettre le constructeur comme prive et ajouter les classes
     * permises a instancier avec la commande friend.
     * Il important d'utiliser la copie profonde (avec new) pour respecter les regles de l'oriente objet.
     */
    Film(string objName = "Untitled", string path = "Untitled",
         int * duree = nullptr, int taille = 0); friend class Gestion;
public:

    /**
     * @brief redefinition du constructeur de copie.
     * @param from
     */
    Film(const Film& from);
    /**
     * @brief pour adapter la table des durees.
     * @param duree - La nouvelle table passee par reference.
     * @param taille - La taille de la nouvelle table.
     * @details Il est important de rechanger la table(delete/new) pour s'adapter a la taille.
     */
    void setTabDuree(int * duree, int taille);
    /**
     * @brief un accesseur au nombre des chapitres.
     */
    int getNbChap() const;
    /**
     * @brief un accesseur a la table des durees.
     * @details Il important d'avoir une valeur de retour constante pour empecher
     * les changements(Il necessite une copie pour changer le contenu).
     */
    const int * getTabDuree() const;
    /**
     * @brief affiche tous les attributs du film.
     * @param s - - un flux générique de sortie.
     * @details La formulation de l'affichage est au respect du critere d'echanges entre le client et le serveur.
     */
    void aff(ostream & s) const override;
    /**
     * @brief le destructeur.
     * @details Il faut supprimer la table des durees cree par new pour empecher les trous de memoire.
     */
    virtual ~Film();
    /**
     * @brief une redefinition de l'operateur = (pour la copie profonde).
     * @param from - source
     */
    Film& operator=(const Film& from);
    /**
     * @brief retourne le type de classe comme film.
     */
    string type() const override;
};

#endif // FILM_H
