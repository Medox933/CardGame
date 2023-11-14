// SnowQueen.h
#ifndef SNOWQUEEN_H
#define SNOWQUEEN_H

#include "PersoJeu.h"

class SnowQueen : public Personnage {
public:
    SnowQueen(const string& nom, int pointsDeVie);

    // Méthodes d'action spécifiques à SnowQueen
    void JavelotDeGlace(Personnage& cible);
    void VentGlacial(Personnage& cible);

    // Redéfinition de l'action spéciale
    void ActionSpeciale(Personnage& cible);
};

#endif
