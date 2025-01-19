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

void enregistrerDonnees(std::string donnee,int s,int p) {
    std::ofstream fichier(FICHIER, std::ios::app);
    if (fichier.is_open()) {
        fichier << donnee << s << p <<std::endl;
        fichier.close();
    } else {
        std::cerr << "Erreur d'ouverture du fichier." << std::endl;
    }
}
