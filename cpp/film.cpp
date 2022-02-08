#include "film.h"

Film::Film(string _objName, string _path, int * _duree, int taille): Video(_objName, _path)
{
    int dure = 0;
    tabDuree = new int [taille];
    nbChap = taille;
    for(int i = 0; i < taille; ++i)
    {
       tabDuree[i] = _duree[i];
        dure += _duree[i];
    }

    duree = dure;
}

Film::Film(const Film& from):Video(from)
{
    nbChap = from.getNbChap();
    if(from.getTabDuree())
    {
        tabDuree = new int[nbChap];
        for(int k = 0; k < from.getNbChap(); ++k)
        {
            tabDuree[k] = from.getTabDuree()[k];
        }
    }
    else tabDuree = nullptr;
}

void Film::setTabDuree(int * _duree, int taille)
{
    delete [] tabDuree;
    tabDuree = new int[taille];
    int dure = 0;
    for(int k = 0; k < taille; ++k)
    {
        tabDuree[k] = _duree[k];
        dure += _duree[k];
    }
    nbChap = taille;
    duree = dure;
}

int Film::getNbChap() const
{
    return nbChap;
}

const int * Film::getTabDuree() const
{
return tabDuree;
}

void Film::aff(ostream & s) const
{
    s << "Object Name:" << objName << ','
      << " Path:" << path << ','
      << " Duree:" << duree << ',';
    for(int k = 0; k < nbChap; ++k)
    {
        if(k != nbChap - 1)
        {
            s << to_string(tabDuree[k]) << "-";
        }
        else
        {
            s << to_string(tabDuree[k]) << ";";
        }
    }
}

Film& Film::operator=(const Film& from)
{
    Video::operator=(from);
    nbChap = from.getNbChap();
        delete [] tabDuree;

        if(from.getTabDuree())
        {
            tabDuree = new int[nbChap];
            for(int k = 0; k < nbChap; ++k)
            {
                tabDuree[k]=from.getTabDuree()[k];
            }
        }
        else tabDuree = nullptr;
    return *this;
}

string Film::type() const
{
    return "Film|";
}


Film::~Film()
{
    cout << "Film killed\n";
    delete [] tabDuree;
}
