/*#################################
# Title : pointer                  #
# Author : Paulz                   #
# Date : 19/10/24                  #
# Version: 1.0.0                   #
##################################*/
/*
Les pointeurs en C++ sont des variables qui stockent
l'adresse d'une autre variable. Cependant,
la gestion manuelle des pointeurs peut être
source d'erreurs comme des fuites de mémoire.
Pour pallier ces problèmes, C++ introduit les pointeurs intelligents(c++11)
à travers la bibliothèque standard (<memory>),
qui gèrent automatiquement la mémoire et
libèrent les ressources lorsqu'elles ne sont plus utilisées.
 */

//  CLASSIC POINTER , can be deprecied
/*
#include <iostream>

int main(int arc ,char **arv) {
    // Création d'une variable entière
    int a = 10;

    // Création d'un pointeur qui stocke l'adresse de a
    int* ptr = &a;

    // Affichage de la valeur de a à travers le pointeur
    std::cout << "Valeur de a: " << *ptr << std::endl;

    // Allouer dynamiquement un entier
    int* dynamicInt = new int(20);

    // Afficher la valeur de l'entier alloué dynamiquement
    std::cout << "Valeur du pointeur alloué dynamiquement: " << *dynamicInt << std::endl;

    // Libérer la mémoire allouée dynamiquement
    delete dynamicInt;

    return 0;
}
*/

//  SMART POINTER  sont des classes qui gèrent automatiquement la durée de vie des objets pointé
/*
#include <iostream>
#include <memory> // Pour les pointeurs intelligents

int main(int arc , char **arv) {
    // Création d'un pointeur intelligent unique
    std::unique_ptr<int> uniquePtr = std::make_unique<int>(10);

    // Accès à la valeur via le pointeur intelligent
    std::cout << "Valeur de uniquePtr: " << *uniquePtr << std::endl;

    // Allouer dynamiquement un tableau avec un pointeur intelligent
    std::unique_ptr<int[]> arrayPtr = std::make_unique<int[]>(5);
    arrayPtr[0] = 1;
    arrayPtr[1] = 2;
    arrayPtr[2] = 3;
    arrayPtr[3] = 4;
    arrayPtr[4] = 5;

    // Affichage des éléments du tableau
    std::cout << "Valeurs du tableau: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << arrayPtr[i] << " ";
    }
    std::cout << std::endl;

    // Aucune libération manuelle de mémoire n'est nécessaire !
    // La mémoire sera automatiquement libérée lorsque uniquePtr sortira de la portée.

    return 0;
}
*/

// SHARE SMART POINTER
#include <iostream>
#include <memory> // Pour les pointeurs intelligents

int main(int arc , char **arv) {
    // Création de deux pointeurs intelligents partagés
    std::shared_ptr<int> sharedPtr1 = std::make_shared<int>(100);
    std::shared_ptr<int> sharedPtr2 = sharedPtr1; // sharedPtr2 partage la même ressource

    // Affichage de la valeur
    std::cout << "Valeur de sharedPtr1: " << *sharedPtr1 << std::endl;
    std::cout << "Valeur de sharedPtr2: " << *sharedPtr2 << std::endl;

    // Affichage du nombre de références à l'objet
    std::cout << "Nombre de références : " << sharedPtr1.use_count() << std::endl;

    return 0;
}
