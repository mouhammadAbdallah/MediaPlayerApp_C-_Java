#include "gestion.h"

Gestion::Gestion()
{

}

void Gestion::create_photo(string objName, string path,
                           float lon, float lat)
{
    auto it = obj.find(objName);
    if (it != obj.end()) std::cout << "Photo Existant!\n";
    else
    {
        obj[objName] = shared_ptr<Media> (new Photo(objName, path, lon, lat));
    }

}

void Gestion::create_video(string objName, string path, int duree)
{
    auto it = obj.find(objName);
    if (it != obj.end()) std::cout << "Video Existant!\n";
    else
    {
        obj[objName] = shared_ptr<Media> (new Video(objName, path, duree));
    }
}

void Gestion::create_film(string objName, string path, int * duree, int taille)
{
    auto it = obj.find(objName);
    if (it != obj.end()) std::cout << "Film Existant!\n";
    else
    {
        obj[objName] = shared_ptr<Media> (new Film(objName, path, duree, taille));
    }
}

void Gestion::create_groupe(string name)
{
    auto it = grp.find(name);
    if (it != grp.end()) std::cout << "Groupe Existant!\n";
    else
    {
        grp[name] = shared_ptr<Groupe> (new Groupe(name));
    }
}




void Gestion::affich_ges(string name, ostream& s) const
{
    //Chercher dans le tableau des multimedias
    auto it = obj.find(name);
    if (it != obj.end())
    {
        stringstream ss;
        string req;
        obj.at(name)->aff(ss);
        req = ss.str();
        replace(req.begin(), req.end(), ';', '\n');
        s << req;
    }
    else
    {
     //Chercher dans le tableau des groupes
        auto it_g = grp.find(name);
        if (it_g != grp.end())
        {
            stringstream ss;
            string req;
            grp.at(name)->affGrp(ss);
            req = ss.str();
            replace(req.begin(), req.end(), ';', '\n');
            s << req;
        }
        else
        {
            s << "Pas Trouve!" << "\n";
        }
    }
}

void Gestion::affich_ges_serv(string name, ostream& s) const
{
    //Chercher dans le tableau des multimedias
    auto it = obj.find(name);
    if (it != obj.end())
    {
        obj.at(name)->aff(s);
    }
    else
    {
     //Chercher dans le tableau des groupes
        auto it_g = grp.find(name);
        if (it_g != grp.end())
        {
            grp.at(name)->affGrp(s);
        }
        else
        {
            s << "Pas Trouve!;";
        }
    }
}

void Gestion::play(string objname) const
{
    auto it = obj.find(objname);
    if (it != obj.end())
    {
        obj.at(objname)->joue();
    }
    else
    {
        cout << "Pas Trouve!\n";
    }
}

void Gestion::supp_obj(string objname)
{
    auto it = obj.find(objname);
    if (it != obj.end())
    {
        obj.erase(it);
        cout << "Media supprime!";
    }
    else
    {
        cout << "Pas Trouve!\n";
    }
    for (auto i = grp.begin(); i != grp.end(); ++i)
    {
      // cout << grp[i->first]->getName();
      //auto findIter = find(grp[i->first]->begin(), grp[i->first]->end(), 1);
    }
}

void Gestion::supp_grp(string name)
{
    auto it_g = grp.find(name);
    if (it_g != grp.end())
    {
        grp.erase(it_g);
        cout << "Groupe supprime!"<< endl;
    }
    else
    {
        cout << "Pas Trouve!\n";
    }
}

void Gestion::add_to_grp(string name, string grpname)
{
    //Chercher dans tableau des multimedias
    auto it = obj.find(name);
    if (it == obj.end())
    {
        cout << "Impossible";
    }
    else
    {
     //Chercher dans tableau des groupes
        auto it_g = grp.find(grpname);
        if (it_g == grp.end())
        {
            cout << "Impossible";
        }
        else
        {
            grp[grpname]->push_back(obj[name]);
        }
    }
}

bool Gestion::processRequest(TCPConnection& cnx, const string& request, string& response)
{
    string token;
    stringstream ss(request);
    stringstream resp;
    list<string> lis_str;
    while(getline(ss, token, ',')) {
        lis_str.push_back(token);
    }

    if(lis_str.front().compare("Show") == 0)
    {
        (this->affich_ges_serv(lis_str.back(), resp));
    }

    if(lis_str.front().compare("Play") == 0)
    {
        this->play(lis_str.back());
        resp << "Media Played!;";
    }

    cerr << "\nRequest: '" << request << "'" << endl;
    response = "OK: " + resp.str();
    cerr << "response: " << response << endl;

    return true;
}

void Gestion::object(string lis1)
{
    string token = "", exp = "";
    list<string> obj_lis = list<string>();
    vector<string> vec, vect;
    stringstream ss(lis1), sg, sm;
    int * t;
    uint i;
    while(getline(ss, token , '|'))
    {
        obj_lis.push_back(token);
    }
    exp = obj_lis.front();
    if(exp.compare("Photo") == 0)
    {
        exp = obj_lis.back();
        replace(exp.begin(), exp.end(), ',', ':');
        sg << exp;
        while(getline(sg, token, ':'))
        {
            vec.push_back(token);
        }
        create_photo(vec[1], vec[3], stoi(vec[5]), stoi(vec[7]));
    }

    if(exp.compare("Video") == 0)
    {

        exp = obj_lis.back();
        replace(exp.begin(), exp.end(), ',', ':');
        sg << exp;
        while(getline(sg, token, ':'))
        {
            vec.push_back(token);
        }
        create_video(vec[1], vec[3], stoi(vec[5]));
    }


    if(exp.compare("Film") == 0)
    {
        exp = obj_lis.back();
        replace(exp.begin(), exp.end(), ',', ':');
        sg << exp;
        while(getline(sg, token, ':'))
        {
            vec.push_back(token);
        }
        sm << vec[6];
        while(getline(sm, exp, '-'))
        {
            vect.push_back(exp);
        }
        t = new int[vect.size()];

        for(i = 0; i < vect.size(); ++i)
        {
            t[i] = stoi(vect[i]);
        }

        create_film(vec[1], vec[3], t, vect.size());
        delete t;
    }
}

void Gestion::write(ostream& f)
{
    string resp;
    shared_ptr<Media> m;
    for(auto it = obj.begin(); it != obj.end(); ++it)
    {
        stringstream ss;
        m = it->second;
        m->aff(ss);
        resp = ss.str();
        replace(resp.begin(), resp.end(), ';', '\n');
        f << m->type() << resp;
    }

}

void Gestion::read(istream& f)
{
    string lis;
    while(getline(f, lis))
    {
        object(lis);
    }
}

Gestion::~Gestion()
{
}
