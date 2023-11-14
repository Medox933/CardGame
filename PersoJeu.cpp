// Personnage.cpp
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "PersoJeu.h"


Personnage::Personnage(const string& Nom, int pv) {
    nom = Nom;
    pointsDeVie = pv;
    attaque = 10;
    defense = 0;
    vitesse = 10;
    srand(time(NULL));
    energie = 0;
    jaugeAttaque = 0;
}

void Personnage::AttaqueDeBase(Personnage& cible) {
    int degats = attaque;
    cible.pointsDeVie -= degats;
    GenererEnergie(10);
}

void Personnage::AttaqueAmelioree(Personnage& cible) {
    int degats = 1.5 * attaque;
    cible.pointsDeVie -= degats;
    GenererEnergie(15);
}

void Personnage::ActionSpeciale(Personnage& cible) {
    if (energie >= 100) {
        int degats = 3.5 * attaque;
        cible.pointsDeVie -= degats;
        energie -= 100;
    }
}



string Personnage::getNom(){
    return nom;
}

int Personnage::getVitesse(){
    return vitesse;
}

void Personnage::setPv(int pv)
{
    pointsDeVie -= pv;
}

void Personnage::GenererEnergie(int quantite) {
    energie += quantite;
}

int Personnage::getPV()
{
    return pointsDeVie;
}

bool Personnage::estEnVie(){
    return pointsDeVie > 0;
}

void Personnage::incrementerJaugeAttaque(){
    jaugeAttaque++;
}

int Personnage::getJaugeAttaque(){
    return jaugeAttaque;
}

void Personnage::equiper(const string& nom_Equip){
    try {
  // Les variables nécessaires à notre programme
  sql::Driver* driver;
  sql::Connection* con;
  sql::Statement* stmt;
  sql::ResultSet* res;
 
  // Etape 1 : créer une connexion à la BDD
  driver = get_driver_instance();
  // on note les paramètres classiques: adresse ip du serveur et port, login, mot de passe
  con = driver->connect("localhost", "student", "crif2024sn");
 
  // Etape 2 : connexion à la base choisie, ici olivier_db
  con->setSchema("equipementdb");
 
  // Etape 3 : création d'un objet qui permet d'effectuer des requêtes sur la base
  stmt = con->createStatement();
 
  // Etape 4 : exécution d'une requete : ici on sélectionne tous les enregistrements
  // de la table equipement
  res = stmt->executeQuery("SELECT * FROM equipement WHERE nom='" + nom_Equip +"'");
  
  // Etape 5 : exploitation du résultat de la requête
  if (res->next()) {
    cout << "\nEquipement : "<< res->getString("nom") << endl;
    cout << "bonus_defense : "<< res->getString("bonus_defense") << endl;
    cout << "bonus_att : "<< res->getString("bonus_att") << endl;
    cout << "bonus_vit : "<< res->getString("bonus_vit") << endl;
    cout << "bonus_pv : "<< res->getString("bonus_pv") << endl;

    int att_sonic = res->getInt("bonus_att");
    int def_sonic = res->getInt("bonus_defense");
    int vit_sonic = res->getInt("bonus_vit");
    int pv_sonic = res->getInt("bonus_pv");

    attaque+= att_sonic;
    defense+= def_sonic;
    vitesse += vit_sonic;
    pointsDeVie += pv_sonic;
  }
  else{
    cout << " ERREUR de connection a la BD " << endl;
  }
    // On nettoie tout avant de sortir : effacement des pointeurs
  // le pointeur sur le Driver sera effacé tout seul
  delete res;
  delete stmt;
  delete con;
    }catch (sql::SQLException &e) {
  // Gestion des execeptions pour déboggage
  cout << "# ERR: " << e.what();
  cout << " (code erreur MySQL: " << e.getErrorCode();
  cout << ", EtatSQL: " << e.getSQLState() << " )" << endl;
}
 
cout << endl;
} 
 



void Personnage::AfficherInfo() const
{
    std::cout << "Nom : " << nom << std::endl;
    std::cout << "Points de vie : " << pointsDeVie << std::endl;
    std::cout << "Attaque : " << attaque << std::endl;
    std::cout << "Defense : " << defense << std::endl;
    std::cout << "Vitesse : " << vitesse << std::endl;
    std::cout << "Energie : " << energie << std::endl;
}
