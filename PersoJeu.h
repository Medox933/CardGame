// Personnage.h
#ifndef PERSOJEU_H
#define PERSOJEU_H
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Personnage {
protected:
    std::string nom;
    int pointsDeVie;
    int attaque;
    int defense;
    int vitesse;
    int energie;
    int jaugeAttaque;
    
public:
    Personnage(const string& Nom, int pointsDeVie);

    // Méthodes d'action
    void AttaqueDeBase(Personnage& cible);
    void AttaqueAmelioree(Personnage& cible);
    void ActionSpeciale(Personnage& cible);

    int getPV() ;
    void AfficherInfo() const;
    void GenererEnergie(int quantite);
    string getNom();
    int getVitesse();
    void setPv(int pv);
    bool estEnVie();
    int getJaugeAttaque();
    void incrementerJaugeAttaque();
    void equiper(const string& nom_Equip);

    
};

#endif

/*

USE EquipementDB;

CREATE TABLE equipement (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nom VARCHAR(255),
    bonus_defense INT
    bonus_Attaque INT
    bonus_Vitesse INT
    bonus_Pv INT
);

insert into equipement (id,nom,bonus_defense, bonus_Attaque, bonus_Vitesse, bonus_Pv ) values (1, 'Gant' ,0, 20, 0, 10);






*/