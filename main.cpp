#include<iostream>
#include<fstream>
#include<conio.h>
#include <string>
#include<stdlib.h>
#include"bibli.h"
//liste des options de lappli
std::string menu[]={"1-afficher inventaire","2-acheter des produits","3-ajouter un produit","4-modifier un produit","5-quitter"};

//bibliotheque ou sont les fonction
int index_menu=0,i=0,j=0,choix=10,ajout=1,in=0,s=0,p=0,index=0;
char touche,nom[100];
struct produit//structure d'un produit
{
    std::string nom;
    float prix;
    int qte;
};
//liste des produit
produit stock[100];

int main(){
    init_data(stock);
    while(choix != 4){
        choisir_option(index_menu,menu);
        //verification touche;
         if(_kbhit()){
            touche = _getch();
            if(touche == 'w' || touche == 'W'){
                if(index_menu>0){
                    index_menu--;
                }
            }else if(touche == 's' || touche == 'S'){
                if(index_menu<4){
                    index_menu++;
                }
            }else if(touche == 'e' || touche == 'E'){
                    choix = index_menu;
                }}
                ///programme meme
            switch (choix)
            {
            case 0:{

                break;
            }
            case 1:{
 
            }
            case 2:{//ajouter un produit//
                std::cout<<"-------ajouter des produits----------"<<std::endl;
                while(ajout!=1){
                    std::cout<<"[w] ajouter un produit"<<std::endl;
                    std::cout<<"[s] revenir au menu principal"<<std::endl;
                    system("cls");
                                                            //verification touche et prise des donnees dans les varriables nom , s , p
                                                                if(_kbhit()){
                                                                touche = _getch();
                                                                if(touche == 'w' || touche == 'W'){
                                                                if(index_menu>0){
                                                                std::cout<<"saisir le nom"<<std::endl;
                                                                //mise du bon index
                                                                while(stock[in].nom!=""){
                                                                    in++;
                                                                }
                                                                std::cin>>nom;
                                                                //verification de lexistance du produit
                                                                while( verif_exist(nom,stock) == false){
                                                                    std::cout<<"ce nom existe deja ,en saisir un autre"<<std::endl;
                                                                    std::cin>>nom;
                                                                }
                                                                std::cout<<"saisir la quantite"<<std::endl;
                                                                std::cin>>s;
                                                                std::cout<<"saisir le prix"<<std::endl;
                                                                std::cin>>p;
                                                                enregistrerDonnees(nom,s,p);
                                                                }
                                                                }else if(touche == 's' || touche == 'S'){
                                                                ajout = 1;
                                                                }}
                }
                //on remet les variable des menus a 0;
                ajout=0;
                choix = 10;
                break;
            }
            case 3:{//modifier un produit//
            //dabord selectioner le produit a modifier
            std::cout<<"saisir le nom du produit a modifier"<<std::endl;
            std::cin>>nom;
            index = verif_index(nom,stock);
            std::cout<<"que voulez vous modifier?"<<std::endl;
                while(ajout!=1){
                    std::cout<<"[w] pour modifier le nom "<<std::endl;
                    std::cout<<"[s] pour modifier le prix"<<std::endl;
                    std::cout<<"[e] pour modifer la quantite"<<std::endl;
                    std::cout<<"[d] pour quitter"<<std::endl;
                    system("cls");
                                                            //verification touche et prise des donnees dans les varriables nom , s , p
                                                                if(_kbhit()){
                                                                touche = _getch();
                                                                if(touche == 'w' || touche == 'W'){
                                                                std::cout<<"saisir le nouveau nom"<<std::endl;
                                                                std::cin>>nom;
                                    	                        stock[index].nom = nom;
                                                                }
                                                                else if(touche == 's' || touche == 'S'){
                                                                std::cout<<"saisir le nouveau prix"<<std::endl;
                                                                std::cin>>s;
                                    	                        stock[index].prix = s;  
                                                                }
                                                                else if(touche == 'e' || touche == 'E'){
                                                                std::cout<<"saisir la nouvelle quatite"<<std::endl;
                                                                std::cin>>p;
                                    	                        stock[index].qte = p;
                                                                }
                                                                else if(touche == 'd' || touche == 'D'){
                                                                    ajout = 1;
                                                                }
                                                                }}
                //on remet les variable des menus a 0;
                ajout=0;
                choix = 10;
                save_all_finish(stock);

                break;
            }
                
            }

        system("cls");
        }
        //fin verif touche

std::cout<<"merci d'avoir utiliser le programme";
    
//
    return 0;
}
