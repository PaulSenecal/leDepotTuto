/*#################################
# Title : friend                   #
# Author : Paulz                   #
# Date : 19/10/24                  #
# Version: 1.0.0                   #
##################################*/
/*
 * Ce mot-clé friend permet à une fonction ou à une classe d'accéder
 *  aux membres privés ou protégés d'une autre classe.
 *  Cela peut être utile pour permettre à certaines fonctions ou classes de
 *  travailler en étroite collaboration sans exposer
 *  les détails d'implémentation à tout le monde.
 */


#include <iostream>

// Classe Rectangle
class Rectangle {
private:
    double width;  // Largeur privée
    double height; // Hauteur privée

public:
    // Constructeur
    Rectangle(double w, double h) : width(w), height(h) {}

    // Déclaration d'une fonction friend qui peut accéder aux membres privés
    friend double calculateArea(const Rectangle& rect);

    // Déclaration d'une classe friend qui peut accéder aux membres privés
    friend class RectangleInfo;
};

// Fonction friend qui peut accéder aux membres privés de Rectangle
double calculateArea(const Rectangle& rect) {
    return rect.width * rect.height; // Accès aux membres privés
}

// Classe friend qui peut accéder aux membres privés de Rectangle
class RectangleInfo {
public:
    void printInfo(const Rectangle& rect) {
        std::cout << "Largeur: " << rect.width << ", Hauteur: " << rect.height << std::endl;
    }
};

int main(int arc, char **arv) {
    // Création d'un objet Rectangle
    Rectangle rect(5.0, 3.0);

    // Utilisation de la fonction friend pour calculer l'aire
    std::cout << "Aire du rectangle: " << calculateArea(rect) << std::endl;

    // Utilisation de la classe friend pour afficher les informations
    RectangleInfo info;
    info.printInfo(rect); // Accès aux membres privés via la classe friend

    return 0;
}
