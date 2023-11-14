// SnowQueen.cpp
#include "SnowQueen.h"

SnowQueen::SnowQueen(const string& Nom, int pointsDeVie) : Personnage(Nom, pointsDeVie) {
    nom = Nom;
    pointsDeVie = pointsDeVie;
    attaque = 0;
    defense = 0;
    vitesse = rand()%100 + 1;
    srand(time(NULL));
    energie = 0;
    jaugeAttaque = 0;
}

void SnowQueen::JavelotDeGlace(Personnage& cible) {
    int degats = 1.25 * this->attaque;
    cible.setPv(degats);
    GenererEnergie(20);
}

void SnowQueen::VentGlacial(Personnage& cible) {
    int degats = 1.5 * this->attaque;
    cible.setPv(degats);
    GenererEnergie(30);
}

void SnowQueen::ActionSpeciale(Personnage& cible) {
    if (this->energie >= 100) {
        int degats = 1.75 * this->attaque;
        cible.setPv(degats);
        this->energie -= 100;
    }
}
