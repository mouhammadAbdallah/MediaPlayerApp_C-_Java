#ifndef GESTION_H
#define GESTION_H

#include <algorithm>
#include <map>
#include "groupe.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "tcpserver.h"
#include <sstream>
#include <vector>


using Ptr_obj = std::shared_ptr<Media>;
using Ptr_grp = std::shared_ptr<Groupe>;
typedef std::map<string, Ptr_obj> Obj;
typedef std::map<string, Ptr_grp> Grp;
using namespace cppu;

/**
 * @brief classe est utilise pour la gestion coherente des donnees.
 */
class Gestion
{
private:
    Obj obj;
    Grp grp;
public:
    /**
     * @brief Gestion - Constructeur.
     */
    Gestion();
    /**
     * @brief pour la creation d'un photo dans la table des objets.
     * @param objName - Le nom de l'objet.
     * @param path - Le fichier.
     * @param lon - La longitude du photo.
     * @param lat - La latitude du photo.
     * @details affiche "Photo Existant!" si la photo existe deja.
     */
    void create_photo(string objName, string path,
                      float lon, float lat);
    /**
     * @brief pour la creation d'un video dans la table des objets.
     * @param objName - Le nom de l'objet.
     * @param path - Le nom du fichier.
     * @param duree - La duree du video.
     * @details affiche "Video Existant!" si le video existe deja.
     */
    void create_video(string objName, string path, int duree);
    /**
     * @brief pour la creation d'un film dans la table des objets.
     * @param objName - Le nom de l'objet.
     * @param path - Le fichier.
     * @param duree - La table des durees des chapitres du film.
     * @param taille - La taille de la table correspondante.
     * @details affiche "Film Existant!" si le film existe deja.
     */
    void create_film(string objName, string path,
                     int * duree, int taille);
    /**
     * @brief pour la creation d'un groupe dans la table des groupes.
     * @param name - Le nom du groupe.
     * @details affiche "Groupe Existant!" si le groupe existe deja.
     */
    void create_groupe(string name);
    /**
      * @brief destructeur.
      */
    ~ Gestion();
    /**
     * @brief Cette fonction est utilisee pour la presentation des attributs des constituants.
     * @param name - Le nom de l'objet/groupe a rechercher et a presenter.
     * @param s - un flux générique de sortie.
     * @details affiche "Pas trouve" si l'objet/groupe recherche n'est pas trouve.
     */
    void affich_ges(string name, ostream& s) const;
    /**
     * @brief pour la presentation des attributs des constituants dans le cas du serveur.
     * @param name - Le nom de l'objet/groupe a rechercher et a presenter.
     * @param s - un flux générique de sortie.
     * @details affiche "Pas trouve" si l'objet/groupe recherche n'est pas trouve.
     */
    void affich_ges_serv(string name, ostream& s) const;
    /**
     * @brief pour jouer l'objet correspondant.
     * @param objname - le nom de l'objet.
     * @details affiche "Pas trouve" si l'objet/groupe recherche n'est pas trouve.
     */
    void play(string objname) const;
    /**
     * @brief Cette fonction ajoute un objet exisant a un groupe existant.
     * @param name - le nom de l'objet "existant".
     * @param grpname - le nom du groupe "existant".
     * @details affiche "impossible" si l'un des groupe ou/objet n'existe pas.
     */
    void add_to_grp(string name, string grpname);
    /**
     * @brief Cette fonction est utilisee pour supprimer le groupe.
     * @param name - le nom du groupe.
     */
    void supp_grp(string name);
    /**
     * @brief pour supprimer l'objet correspondant.
     * @param objname - le nom de l'objet.
     * @details supprime aussi l'objet existant dans tous les groupes.
     */
    void supp_obj(string objname);
    /**
     * @brief méthode est appelée chaque fois qu'il y a une requête à traiter.
     * @param cnx
     * @param request - contient la requête.
     * @param response - indiquer la réponse qui sera renvoyée au client.
     * @return si la fonction renvoie false la connexion est close.
     */
    bool processRequest(TCPConnection& cnx, const string& request, string& response);
    /**
     * @brief Cette fonction est une fabrique d'objets selon le type de sa classe.
     * @param lis1 - string correspondant a chaque ligne dans le fichier.
     */
    void object(string lis1);
    /**
     * @brief Cette fonction est utilisee pour la lecture des objets sauvegardes dans le fichier.
     * @param f - ifstream correspondant au fichier.
     */
    void read(istream& f);
    /**
     * @brief Cette fonction est utilisee pour l'ecriture des objets dans le fichier correspondant.
     * @param f - ofstream correspondant au fichier.
     */
    void write(ostream& f);

};

#endif // GESTION_H
