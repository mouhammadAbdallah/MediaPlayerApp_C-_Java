#include "media.h"
/**
 * le constructeur: le valeur par defaut "Untitled".
 */
Media::Media(){
path = "Untitled";
objName = "Untitled";

}

Media::Media(string _objName, string _path){
    path = _path;
    objName = _objName;
    
}

string Media::getObjName() const{
    return objName;
}

string Media::getPath() const{
    return path;
}

void Media::setObjName(string _objName){
    objName = _objName;
}

void Media::setPath(string _path){
    path = _path;
}

void Media::aff(ostream & s) const {
    s << "Object Name: " << objName
    << endl << "Pathname: "
    << path << endl;
}

Media::~Media()
{
    cout << "Media killed\n";
}
