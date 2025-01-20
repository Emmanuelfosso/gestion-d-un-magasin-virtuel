#include<iostream>
#include <fstream>
#include <string>
#include<stdlib.h>
#include"bibli.h"
//bibliotheque ou sont les fonction
const std::string FICHIER = "donnees.txt";
//fonction d'affichage du menu
void choisir_option(int j,std::string menu[]){
    int cmt=0;
    std::cout<<"------------menu------------"<<std::endl;
    for(cmt=0;cmt<=4;cmt++){
        if(cmt == j){
            std::cout<<"|["<<menu[cmt]<<"]|"<<std::endl;
        }else{
            std::cout<<"|"<<menu[cmt]<<"|"<<std::endl;
        }
    }
    std::cout<<"----------------------------"<<std::endl;
}
//focntion pour enregistrer des donnee
void enregistrerDonnees(std::string donnee,int s,int p) {
    std::ofstream fichier(FICHIER, std::ios::app);
    if (fichier.is_open()) {
        fichier << donnee <<" "<< s <<" "<< p <<std::endl;
        fichier.close();
    } else {
        std::cerr << "Erreur d'ouverture du fichier." << std::endl;
    }
}
//fonction pour verifier l'index
int verif_index(std::string nom,produit stock[100]){
    for (int i=0;i<=99;i++){
        if(nom == stock[i].nom){
            return i;
        }
    }
}
//fonction pour verifier si sa existe
bool verif_exist(std::string nom,produit stock[100]){
    for(int i=0;i<=99;i++){
        if(nom = stock[i].nom){
            return false;
        }
    }
    return true;
}
//fonction pour tou sauvegarder
void save_all_data(produit stock[100]){
    std::ofstream fichier("donnees.txt");
    if(fichier.is_open()){
        for(int i=0;i<=99;i++)
        {
        fichier<<stock[i].nom<<" "<<stock[i].prix<<" "<<stock[i].qte<<std::endl;
    }
    fichier.close();
}
}
//pour initialser les donnees du fichier 
void init_data(produit stock[100]){
    std::ifstream fichier("donnees.txt");
    if (fichier.is_open()){
        for(int i=0 ; i<= 99;i++){
            fichier>>stock[i].nom>>stock[i].prix>>stock[i].qte;
        }
        fichier.close();
    }
}