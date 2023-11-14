-- Active: 1678373709862@@127.0.0.1@3306

USE EquipementDB;

CREATE TABLE equipement (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nom VARCHAR(255),
    bonus_defense INT
    bonus_Attaque INT
    bonus_Vitesse INT
    bonus_Pv INT
);

insert into equipement (id,nom,bonus_defense, bonus_Attaque, bonus_Vitesse, bonus_Pv ) values (1, 'Chevalresse' ,20, 20, 20, 20);