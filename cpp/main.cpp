//
// author: Mohamad ABDALLAH
// main.cpp
// on 10/11/2020
//
#include <sstream>
#include <fstream>
#include "photo.h"
#include "film.h"
#include "groupe.h"
#include "gestion.h"
#include "tcpserver.h"


#define VERSION_FINAL

using namespace cppu;
const int PORT = 3331;

int main(int argc, const char *argv[])
{

    #ifdef VERSION_FINAL

    int * tabn = new int[5]{1,2,3,4,5};
    shared_ptr<Gestion> ges(new Gestion());
    ges->create_groupe("Vacances");
    ges->create_photo("download", "/home/Mohamad/Pictures/download.png", 20.25, 40.5);
    ges->create_photo("icon", "/home/Mohamad/Pictures/icon.xpm", 20.25, 40.5);
    ges->create_video("123","/home/Mohamad/Videos/123.mp4",25);
    ges->add_to_grp("download","Vacances");
    ges->add_to_grp("123","Vacances");
    ges->create_film("Friend", "/home/Mohamad/films/Friend", tabn, 5);
    ges->add_to_grp("Friend","Vacances");

    shared_ptr<TCPServer> server(new TCPServer());
    server->setCallback(*ges, &Gestion::processRequest);
    cout << "Starting Server on port " << PORT << endl;
    int status = server->run(PORT);
    if (status < 0) {
      cerr << "Could not start Server on port " << PORT << endl;
      return 1;
    }

    #endif // VERSION_FINAL

    #ifdef VERSION_Q4

    Photo *p = new Photo("fleur", "./fleur.jpeg", 20.25, 40.5);
    p->aff(cout);
    p->joue();
    Video *v = new Video("shortVideo", "./shortVideo");
    v->aff(cout);
    v->joue();
    delete v;
    delete p;

    #endif // VERSION_Q4

    #ifdef VERSION_Q5

    int count = 0;
    Media ** medias = new Media * [10];
    medias[count++] = new Photo("Image "+to_string(count),
                             "/home/Mohamad/Pictures",count,count*2);
    medias[count++] = new Video("Video "+to_string(count),
                             "/home/Mohamad/Videos",count);
    medias[count++] = new Photo("Image "+to_string(count),
                             "/home/Mohamad/Pictures",count,count*2);
    medias[count++] = new Video("Video "+to_string(count),
                             "/home/Mohamad/Videos",count);
    for(int k = 0; k < count; ++k)
    {
        medias[k]->aff(cout);
    }

    for(int k = 0; k < count; ++k)
    {
        delete medias[k];
    }
    delete [] medias;

    #endif // VERSION_Q5

    #ifdef VERSION_Q6

    int * tab = new int[5]{1,2,3,4,5};
    Film * f = new Film("Friends","/home/Mohamad/inf224",tab,5);
    f->aff(cout);
    const int * tab1 = f->getTabDuree();
    //tab1[1]=-65; // on ne peut pas modifier le tableau car la valeur
                 // de retour est const
    // Pour etre capable de modifier le tableau sans aucun changement
    // sur l'original, on doit avoir une copie du tableau
    int * tabt = new int[f->getNbChap()];
    for(int k = 0; k < f->getNbChap(); ++k)
    {
        tabt[k] = f->getTabDuree()[k];
    }
    delete [] tab;
    int * tab2 = new int[7]{56,64,98,37,14,25,16};
    f->setTabDuree(tab2,7);
    f->aff(cout);
    delete [] tab2;
    delete [] tabt;
    delete f;

    #endif // VERSION_Q6

    #ifdef VERSION_Q7

    int * tabn = new int[5]{1,2,3,4,5};
    Film * f1= new Film();
    f->aff(cout);
    *f1 = *f;
    int * tabj = new int[5]{2,4,6,8,10};
    f->setTabDuree(tabj,5);
    f->aff(cout);
    f1->aff(cout);
    delete f;
    delete f1;
    delete [] tabn;
    delete [] tabj;

    #endif // VERSION_Q7

    #ifdef VERSION_Q8_Q9

    int * tabn = new int[5]{1,2,3,4,5};
    Groupe *grp = new Groupe("Vacances");
    Groupe *grp1 = new Groupe("Weekend");
    Groupe *grp2 = new Groupe("Weekday");
    printf("%s\n",grp->getName().c_str());
    shared_ptr<Media> p1(new Video("Mohamad","Abdallah"));
    shared_ptr<Media> p2(new Film("Friend","/home/Mohamad/inf224",tabn,5));
    shared_ptr<Media> p3(new Photo("Santaigo","Morino",15,20));
    grp->push_back(p1);
    grp->push_back(p2);
    grp->push_back(p3);
    grp1->push_back(p1);
    grp1->push_back(p2);
    grp2->push_back(p3);
    grp->affGrp(cout);
    printf("%s\n",grp1->getName().c_str());
    grp1->affGrp(cout);
    grp2->affGrp(cout);
    delete [] tabn;
    list<Ptr> ::iterator it = grp->begin();
    list<Ptr> ::iterator it1 = grp1->begin();
    list<Ptr> ::iterator it2 = grp2->begin();
    advance(it,2);
    grp->erase(it);
    advance(it2,0);
    grp2->erase(it2);
    advance(it1,1);
    grp1->erase(it1);

    delete grp2;
    delete grp;
    delete grp1;

    #endif // VERSION_Q8_Q9

    #ifdef VERSION_Q10_Q11

    ges->play("download.png");
    ges->affich_ges("Samir");
    ges->supp_grp("Hello");
    ges->supp_grp("Brag");
    ges->supp_obj("download");
    delete ges;
    // En plus de la partie du serveur qu'on est entrain d'utiliser couramment.

    #endif // VERSION_Q10_Q11

    #ifdef VERSION_Q12

    //Pour l'ecriture dans le fichier:

    Gestion *ges = new Gestion();
    int * tabn = new int[5]{1,2,3,4,5};
    ofstream fileout;
    fileout.open("log.txt");
    ges->create_photo("download.png", "/home/Mohamad/Pictures", 20.25, 40.5);
    ges->create_video("Mohamad","Abdallah",25);
    ges->create_video("Salim","Abdallah",25);
    ges->create_film("Friend","/home/Mohamad/inf224",tabn,5);
    ges->create_video("Walid","Abdallah",25);
    ges->write(fileout);
    delete ges;
    delete [] tabn;

    // Pour la lecture du fichier

    Gestion *ges = new Gestion();
    ifstream filein;
    filein.open("log.txt",ios_base::app); //app -> append (pour ajouter de nouveaux objets a un fichier qui existe deja)
    ges->read(filein);
    ges->affich_ges("Salim", cout);
    ges->affich_ges("Mohamad", cout);
    ges->affich_ges("Walid", cout);
    ges->affich_ges("Brug", cout);
    ges->affich_ges("Friend", cout);

    #endif // VERSION_Q12

    return 0;
}
