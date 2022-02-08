#ifndef VIDEO_H
#define VIDEO_H

#include "media.h"

/**
 * @brief classe derivee de la classe media.
 * videos.
 */
class Video: public Media{

protected:
    int duree;
    /**
     * @brief Video - Constructeur avec les valeurs par defaut.
     * @param objName - Le nom de l'objet.
     * @param path - Le fichier.
     * @param duree - La duree du video.
     * @details Pour eviter l'instanciation de cette classe dans main,
     * on peut mettre le constructeur comme prive et ajouter les classes
     * permises a instancier avec la commande friend.
     */
    Video(string objName = "Untitled", string path = "Undefined", int duree = 0):
        Media(objName,path), duree(duree) {} friend class Gestion;
public:

    /**
     * @brief affiche tous les attributs du video.
     * @param s - - un flux générique de sortie.
     */
    void aff(ostream & s) const override {s << "Object Name:" << objName
                                            << ',' << " Path:" << path
                                            << ',' << " duree:" << duree << ";" ;}
    /**
     * @brief un modifieur de la duree du video.
     * @param _duree - La nouvelle duree.
     */
    void setDuree(int _duree) {duree = _duree;}

    /**
     * @brief un accesseur de la duree du video.
     */
    float getDuree() {return duree;}

    /**
     * @brief pour presenter les videos.
     * mpv: Video Viewer.
     */
    void joue() const override {system(("mpv "+path+" &").c_str());}
    /**
     * @brief le destructeur.
     */
    virtual ~Video() {cout << "Video Detruit\n";}
    /**
     * @brief retourne le type de classe comme video.
     */
    string type() const override{return "Video|";}
};
#endif // VIDEO_H
