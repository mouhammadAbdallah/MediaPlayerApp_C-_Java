#ifndef GROUPE_H
#define GROUPE_H

#include <memory>
#include "media.h"
#include <list>
#include <string>
using namespace std;
using Ptr = std::shared_ptr<Media>;

/**
 * @brief classe derivee de la classe template <list>.
 * groupes.
 */
class Groupe: public list<Ptr>
{
private:
    string name;

public:
    /**
     * @brief Groupe - Constructeur avec les valeurs par defaut.
     * @param name - Le nom du groupe.
     */
    Groupe(string name="Untitled"); //friend class Gestion;
    /**
     * @brief un accesseur au nom du groupe.
     */
    string getName() const;
    /**
     * @brief presente les attributs des constituants du groupe.
     * @param s - un flux générique de sortie.
     */
    void affGrp(ostream & s) const;
    /**
     * @brief le destructeur.
     * @details Les constituants ne sont pas supprimes.
     */
    ~Groupe();
};

#endif // GROUPE_H
