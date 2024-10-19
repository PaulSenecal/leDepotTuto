/*#################################
# Title : Cast                     #
# Author : Paulz                   #
# Date : 18/10/24                  #
# Version: 1.0.0                   #
##################################*/
#include <iostream>
#include <typeinfo>

// Classe de base
class Base {
public:
    virtual void display() {
        std::cout << "Base class display" << std::endl;
    }
};

// Classe dérivée
class Derived : public Base {
public:
    void display() override {
        std::cout << "Derived class display" << std::endl;
    }
};

int main(int argc, char **argv) {

    // 1. static_cast
    int a = 10;
    double b = static_cast<double>(a); // Convertit int en double
    std::cout << "static_cast result: " << b << std::endl;

    // 2. const_cast
    const int x = 42;
    int* y = const_cast<int*>(&x); // Retire la constance de x
    *y = 100; // Ne pas faire ça dans un code réel, c'est dangereux !
    std::cout << "const_cast result: " << *y << std::endl; // Affiche 100

    // 3. dynamic_cast
    Base* basePtr = new Derived(); // Pointeur de base pointant vers un objet dérivé
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr); // Cast dynamique
    if (derivedPtr) {
        derivedPtr->display(); // Appelle display() de Derived
    } else {
        std::cout << "dynamic_cast failed" << std::endl;
    }

    // 4. reinterpret_cast
    int num = 65;
    char* charPtr = reinterpret_cast<char*>(&num); // Interprète l'adresse d'un int comme un char*
    std::cout << "reinterpret_cast result: " << *charPtr << std::endl; // Affiche le premier caractère correspondant à la valeur de num

    // Nettoyage
    delete basePtr;

    return 0;
}


