#ifndef __BIBLI_H_INCLUDED__
#define __BIBLI_H_INCLUDED__
struct produit//structure d'un produit
{
    std::string nom;
    float prix;
    int qte;
};
//liste des produit
extern produit stock[100];
//fonction d'affichage du menu
void choisir_option(int j,std::string menu[]);
void enregistrerDonnees(std::string donnee,int s,int p);
bool verif_exist(std::string nom,produit stock[100]);
int verif_index(std::string nom,produit stock[100]);
void save_all_data(produit stock[100]);
void init_data(produit stock[100]);
//fonction pour les identifiants des facture
int indentifiant();
//fonction pour enregistrer la facture virtuel
void facture_save(produit facturier[100]);
#endif