#include "groupe.h"

Groupe::Groupe(string _name)
{
    name = _name;
}

string Groupe::getName() const
{
    return name;
}

void Groupe::affGrp(ostream & s) const
{
    for(Ptr it : *this)
    {
        it->aff(s);
    }
}
Groupe::~Groupe()
{
    for(Ptr n : *this)
    {
        n.reset();
    }
}


