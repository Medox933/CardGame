// Berserker.h
#ifndef BERSERKER_H
#define BERSERKER_H

#include "PersoJeu.h"

class Berserker : public Personnage {
protected:
    std::string nom;
    int pointsDeVie;    
public:
    Berserker(const string& Nom, int pv);

    // Méthodes d'action spécifiques à Berserker
    void FrappePunitive(Personnage& cible);
    void CoupDechaine(Personnage& cible);

    // Redéfinition de l'action spéciale
    void ActionSpeciale(Personnage& cible);
};

#endif
