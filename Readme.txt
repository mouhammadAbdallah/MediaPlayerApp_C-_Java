
Prenom: Mohamad
Nom: ABDALLAH

*** Dans la partie C++:

Q4)

// On ne peut pas avoir des instances de la classe de base
// car il est devenu une classe abstraite a cause de la methode abstraite.

Q5)

// La propriete est le polymorphisme d'heritage

// il faut marquer la fonction a utiliser
// comme virtuelle, puisqu'en C++:
// - Avec virtual, on applique la methode du pointe
// - Sans virtual, on applique la methode du pointeur

// Ce tableau contient les pointeurs vers ces objets puisque chaque element
// est un Media *, alors chaque case pointe vers une instance: Photo ou Video.

// En java, tous les methodes herites "non finalisees" sont virtuelles par defaut.
// Donc, c'est la derniere version qui s'applique par heritage.

Q6)

// Pour que l'objet Film ait plein controle sur ses donnees, il
// doit copier le contenu du tableau passe en parametre.

// En ajoutant const au valeur de retour de l'accesseur du tableau,
// on ne permet plus la modification externe du tableau.

Q7)

// Dans la classe Film, on a utilise "new" pour creer le tableau des durees
// afin de copier le tableau passe en parametres.
// Et, dans cette classe, il faut initialiser le destructeur pour supprimer
// le tableau des durees initialise (avec new) avant la suppression de l'objet pour empecher les fuites memoires.

// Concernant la copie des objets, lorsqu'on copie le pointeur, l'objet est
// partage par plusieurs fonctions. Pour cela, il faut initialiser un nouveau objet
// avant de copier le contenu.

Q8)

// La liste d'objets doit etre une liste de pointeurs car les objets appartiennent aux classes
// derives de cette classe (en plus, la classe de base est une classe abstraite - on va obtenir une erreur)
// Or, en java les pointeurs sont implicites.

// Remarque: Il ne faut pas oublier de mettre le destructeur comme "virtual"
// lorsqu'on applique la polymorphisme d'heritage.

Q10 et plus)

// Pour empecher new, on utilise des constructeurs "friend".

// La solution la plus simple est de mettre cette fonction dans la classe responsable de la coherence des donnees.

// Les exceptions sont generees au fur et a mesure du travail et sont mentionnees dans la documentation.



*** Dans la partie Java:


// On constate que lorsque le JTextArea est tout plein de donnees, il ya des donnees qui disparaissent. D'ou, l'utilisation de JscrollPane.

// Les classes imbriquees sont publiques pour pouvoir les documenter.


*** Documentation:

# doxygen -g
# doxygen
puis dans le folder html on ouvre index.html


*** usage:
le dernier version de ce projet fonctionne bien sur les machines de TP de l'ecole:
on commence par la commande: "make run" dans le Folder cpp puis "make run" dans le folder swing




