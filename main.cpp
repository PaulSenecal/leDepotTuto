/*#################################
# Title : pointer                  #
# Author : Paulz                   #
# Date : 19/10/24                  #
# Version: 1.0.0                   #
##################################*/
/*
Les fonctions virtuelles et virtuelles pures sont utilisées
dans la programmation orientée objet en C++
pour implémenter le polymorphisme.
Elles permettent de définir des interfaces et
d'assurer que les classes dérivées implémentent certaines méthodes.
 */

#include <iostream>

// Classe de base abstraite (interface)
class Animal {
public:
    // Fonction virtuelle pure (doit être implémentée par les classes dérivées)
    virtual void sound() const = 0;

    // Fonction virtuelle normale (peut être redéfinie dans les classes dérivées)
    virtual void sleep() const {
        std::cout << "L'animal dort." << std::endl;
    }

    // Un destructeur virtuel pour un bon nettoyage de mémoire lorsqu'on supprime via un pointeur de base
    virtual ~Animal() = default;
};

// Classe dérivée Dog (Chien)
class Dog : public Animal {
public:
    // Implémentation de la fonction virtuelle pure
    void sound() const override {
        std::cout << "Le chien aboie: Woof! Woof!" << std::endl;
    }

    // Redéfinition de la fonction virtuelle
    void sleep() const override {
        std::cout << "Le chien dort paisiblement." << std::endl;
    }
};

// Classe dérivée Cat (Chat)
class Cat : public Animal {
public:
    // Implémentation de la fonction virtuelle pure
    void sound() const override {
        std::cout << "Le chat miaule: Meow! Meow!" << std::endl;
    }

    // Redéfinition de la fonction virtuelle
    void sleep() const override {
        std::cout << "Le chat dort en se lovant." << std::endl;
    }
};

int main() {
    // Utilisation de polymorphisme via des pointeurs de base
    Animal* myDog = new Dog();
    Animal* myCat = new Cat();

    // Appel des méthodes polymorphes
    myDog->sound(); // Le chien aboie
    myDog->sleep(); // Le chien dort

    myCat->sound(); // Le chat miaule
    myCat->sleep(); // Le chat dort

    // Libérer la mémoire allouée
    delete myDog;
    delete myCat;

    return 0;
}
