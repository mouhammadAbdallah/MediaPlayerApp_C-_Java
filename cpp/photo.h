#ifndef PHOTO_H
#define PHOTO_H

#include "media.h"
/**
 * @brief classe derivee de la classe media.
 * photos.
 */
class Photo: public Media{

private:
    float lon, lat;
    /**
     * @brief Photo - Constructeur avec les valeurs par defaut.
     * @param objName - Le nom de l'objet.
     * @param path - Le fichier.
     * @param lon - La longitude.
     * @param lat - La latitude.
     * @details Pour eviter l'instanciation de cette classe dans main,
     * on peut mettre le constructeur comme prive et ajouter les classes
     * permises a instancier avec la commande friend.
     */
    Photo(string objName = "Untitled", string path = "Undefined",
          float lon = 0 , float lat = 0 ):
        Media(objName,path), lon(lon), lat(lat) {} friend class Gestion;
public:

    /**
     * @brief fonction  affiche tous les attributs du photo.
     * @param s - un flux générique de sortie.
     */
    void aff(ostream & s) const override {s << "Object Name:" << objName
                                          << ',' << " Path:" << path
                                          << ',' << " Longitude:" << lon
                                          << ',' << " Latidue:" << lat << ";" ;}
                                          
    float getLat() {return lat;}
    /**
     * @brief modifieur de la longitude.
     * @param _lon - la nouvelle longitude du photo.
     */
    void setLong(float _long) {lon = _long;}
    /**
     * @brief un modifieur de la latitude.
     * @param _lat - la nouvelle latitude du photo.
     */
    void setLat(float _lati) {lat = _lati;}

    /**
     * @brief accesseur pour la longitude.
     */
    float getLong() {return lon;}
    /**
     * @brief accesseur pour la latitude.
     */

    /**
     * @brief pour presenter les photos.
     * eog: Image Viewer.
     */
    void joue() const override {system(
                    ("imagej "+path+" &").c_str());}
    /**
     * @brief destructeur.
     */
    virtual ~Photo() {cout << "Photo killed\n";}
    /**
     * @brief retourne le type de classe comme photo.
     */
    string type() const override{return "Photo|";}

};

#endif // PHOTO_H
