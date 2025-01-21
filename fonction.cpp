#include<iostream>
#include <fstream>
#include <string>
#include<stdlib.h>
#include<ctime>
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
    return 0;
}
//fonction pour verifier si sa existe
bool verif_exist(std::string nom,produit stock[100]){
    for(int i=0;i<=99;i++){
        if(nom == stock[i].nom){
            return false;
        }
    }
    return true;
}
//fonction pour tou sauvegarder
void save_all_data(produit stock[100]){
    remove("donnees.txt");
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
//fonction pour les identifiants des facture
int indentifiant(){
    int a;
    std::ifstream fichier("id.txt");
    if (fichier.is_open()){
        fichier>>a;
    }
    remove("id.txt");
    std::ofstream mise("id.txt");
    if(fichier.is_open()){
        mise<<a+1;
    }
    mise.close();
    return a;
}
//fonction pour enregistrer la facture virtuel
void facture_save(produit facturier[100]){
    int total=0;
    time_t now = time(0);
    tm* ltm = localtime(&now);
    //creation du fichier avec un nom unique
    std::string nom_fichier=std::to_string(indentifiant())+".txt";
    std::ofstream fichier("facture/" + nom_fichier);
    //initialisation de la facture
    fichier<<"------------F A C T U R E---------"<<std::endl;
    fichier<<"id : "<<std::to_string(indentifiant())<<std::endl<<"temp :"<<ltm->tm_year + 1900<<"-"<<ltm->tm_mon + 1<<"-"<<ltm->tm_mday<<"_"<<ltm->tm_hour<<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<"\n \n \n"<<std::endl;
    fichier<<"nom produit / qte / prix unitaire / prix total"<<std::endl;
    for(int i=0;i<=99;i++){
        if(facturier[i].qte != 0){
            fichier<<"--"<<facturier[i].nom<<" / "<<facturier[i].qte<<" / "<<facturier[i].prix<<" / "<<(facturier[i].qte * facturier[i].prix)<<std::endl;
            total += facturier[i].qte * facturier[i].prix;
        }
    }
    fichier<<"total : "<<total;
    fichier.close();
    }