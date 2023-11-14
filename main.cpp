
#include <iostream>
#include "PersoJeu.h"
#include "Berserker.h"
#include "SnowQueen.h"

int main() {
    // Création des instances de personnages
    Personnage p1 ("Héros", 3000);
    Berserker b1("Berserker", 3000);
    SnowQueen s1("SnowQueen", 3000);

    int choix, tour;

    p1.AfficherInfo();
    b1.AfficherInfo();
    s1.AfficherInfo();

    if(p1.getVitesse() > b1.getVitesse() && p1.getVitesse() < s1.getVitesse()){
        cout<<"SnowQueen joue."<<endl;    
    }
    else if(b1.getVitesse() > p1.getVitesse() && b1.getVitesse() > s1.getVitesse()){
        cout<<"Berserker joue."<<endl; 
    } 
    else if(p1.getVitesse() > b1.getVitesse() && p1.getVitesse() > s1.getVitesse()){
        cout<<"Héros joue."<<endl;
    }

    while(1){       
            while(choix < 1 || choix >1){
                cout<<"Choisissez une action : 1 Attaque de base"<<endl;
                cin>> choix;
                if(choix == 2){
                cout<<"La jauge n'est pas remplie !"<<endl;
                }
            }

        exit(1);
    }
      
      
       
       
    return 0;
}
    
    
