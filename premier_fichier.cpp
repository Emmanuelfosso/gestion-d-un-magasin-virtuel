#include<iostream>
#include<conio.h>
#include <fstream>
#include <string>
#include<stdlib.h>
int index_menu=0,i=0,j=0,choix=10;
char touche;
struct produit
{
    std::string nom;
    float prix;
    int qte;
};
produit stock[100];
std::string menu[]={"1-afficher inventaire","2-acheter des produits","3-ajouter un produit","4-modifier un produit","5-quitter"};
void choisir_option(int j){
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
void affich_menu(){

}
int main(int argc,char** argv){
//
    while(choix != 5){
        choisir_option(index_menu);
        //verification touche;
         if(_kbhit()){
            touche = _getch();
            if(touche == 'w' || touche == 'W'){
                if(index_menu>0){
                    index_menu--;
                }
            }else if(touche == 's' || touche == 'S'){
                if(index_menu<5){
                    index_menu++;
                }
            }else if(touche == 'e' || touche == 'E'){
                    choix = index_menu;
                }
                ///programme meme
            switch (choix)
            {
            case 0:{

                break;
            }
            case 1:{
                //25 caratere pour le nom,9 caratere pour le prix 6 pour la quantite;
                for(i=0;i<=99;i++){
                    std::cout<<stock[i].nom<<" : "<<stock[i].prix<<"|"<<stock[i].qte<<"|"<<std::endl;
                }
                std::cout<<"entrez une valeur pour quitter"<<std::endl;
                break;
            }
            case 2:{

                break;
            }
            case 3:{

                break;
            }
            case 4:{

                break;
            }
                
            }
            //fin programme meme
        }
        system("cls");
        //fin verif touche
}

//
    return 0;
}