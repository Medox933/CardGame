// Berserker.cpp
#include "Berserker.h"

Berserker::Berserker(const string& Nom, int pointsDeVie): Personnage(Nom, pointsDeVie){
    nom = Nom;
    pointsDeVie = pointsDeVie;
    attaque = 0;
    defense = 0;
    vitesse = 40;
    srand(time(NULL));
    energie = 0;
    jaugeAttaque = 0;
}

void Berserker::FrappePunitive(Personnage& cible) {
    int degats = 0.3 * pointsDeVie;
    int coutVie = 0.1 * pointsDeVie;
    cible.setPv(degats);
    pointsDeVie -= coutVie;
    GenererEnergie(20);
}

void Berserker::CoupDechaine(Personnage& cible) {
    int degats = 0.5 * pointsDeVie;
    int coutVie = 0.15 * pointsDeVie;
    cible.setPv(degats);
    pointsDeVie -= coutVie;
    GenererEnergie(30);
}

void Berserker::ActionSpeciale(Personnage& cible) {
    if (energie >= 100) {
        int degats = 0.75 * pointsDeVie;
        int regen = 0.5 * pointsDeVie;
        cible.setPv(degats);
        pointsDeVie += regen;
        energie -= 100;
    }
}
