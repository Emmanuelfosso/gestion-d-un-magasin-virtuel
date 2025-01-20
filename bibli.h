#ifndef __BIBLI_H_INCLUDED__
#define __BIBLI_H_INCLUDED__
//fonction d'affichage du menu
void choisir_option(int j,std::string menu[]);
void enregistrerDonnees(std::string donnee,int s,int p);
bool verif_exist(std::string nom,produit stock[100]);
int verif_index(std::string nom,produit stock[100]);
void save_all_data(produit stock[100]);
void init_data(produit stock[100]);
#endif