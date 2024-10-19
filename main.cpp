/*#################################
# Title : template                 #
# Author : Paulz                   #
# Date : 19/10/24                  #
# Version: 1.0.0                   #
##################################*/
#include <iostream>
#include <string>

// Fonction template
template <typename T>
T add(T a, T b) {
    return a + b;
}

// Classe template
template <typename T>
class Box {
private:
    T value;

public:
    // Constructeur
    Box(T val) : value(val) {}

    // Méthode pour obtenir la valeur
    T getValue() const {
        return value;
    }

    // Méthode pour changer la valeur
    void setValue(T val) {
        value = val;
    }
};

int main(int arc , char *arcv[]) {

    // Utilisation de la fonction template avec int
    int intResult = add<int>(5, 3);
    std::cout << "Addition de deux int: " << intResult << std::endl;

    // Utilisation de la fonction template avec double
    double doubleResult = add<double>(2.5, 3.1);
    std::cout << "Addition de deux double: " << doubleResult << std::endl;

    // Utilisation de la fonction template avec std::string
    std::string strResult = add<std::string>("Hello, ", "World!");
    std::cout << "Concaténation de deux strings: " << strResult << std::endl;

    // Utilisation de la classe template avec int
    Box<int> intBox(10);
    std::cout << "Valeur initiale du Box<int>: " << intBox.getValue() << std::endl;
    intBox.setValue(20);
    std::cout << "Nouvelle valeur du Box<int>: " << intBox.getValue() << std::endl;

    // Utilisation de la classe template avec double
    Box<double> doubleBox(3.14);
    std::cout << "Valeur initiale du Box<double>: " << doubleBox.getValue() << std::endl;

    // Utilisation de la classe template avec std::string
    Box<std::string> stringBox("C++ Templates");
    std::cout << "Valeur initiale du Box<std::string>: " << stringBox.getValue() << std::endl;

    return 0;
}
