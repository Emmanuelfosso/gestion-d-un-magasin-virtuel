#include<iostream>
#include<fstream>
#include<conio.h>
#include <string>
#include<stdlib.h>
#include"bibli.h"
//liste des options de lappli
std::string menu[]={"1-afficher inventaire","2-acheter des produits","3-ajouter un produit","4-modifier un produit","5-quitter"};
//bibliotheque ou sont les fonction
int index_menu=0,i=0,j=0,choix=10,ajout=1,in=0,s=0,p=0;
char touche,nom[100];
produit stock[100];
produit facturier[100]={};
int main(){
    int index;
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
                system("cls");
                std::cout<<"\033[33mI N V E N T A I R E\033[0m"<<std::endl;
                std::cout<<"\033[33m---nom / prix / quatite\033[0m"<<std::endl;
                for(i=0;i<=99;i++){
                    if(stock[i].qte != 0){
                    std::cout<<"---"<<stock[i].nom<<" , "<<stock[i].prix<<" , "<<stock[i].qte<<"\033[0m"<<std::endl;
                }}
                std::cout<<"saisir n'importe quel valeur"<<std::endl;
                std::cin>>p;
                //on remet les variable des menus a 0;
                ajout=0;
                choix = 10;
                break;
            }
            case 1:{//--------interface des factures----------
                std::cout<<"\033[34m-------acheter des produits----------\033[0m"<<std::endl;
                while(ajout!=1){
                std::cout<<"\033[32m[w]\033[33m acheter de nouveau produit\033[0m"<<std::endl;
                std::cout<<"\033[32m[s]\033[33m revenir au menu principal et generer la facture\033[0m"<<std::endl;
                system("cls");
                                                            //verification touche et prise des donnees dans les varriables nom , s , p
                                                                if(_kbhit()){
                                                                touche = _getch();
                                                                if(touche == 'w' || touche == 'W'){
                                                                    std::cout<<"\033[33mI N V E N T A I R E\033[0m"<<std::endl;
                                                                    std::cout<<"\033[33m---nom / prix / quatite\033[0m"<<std::endl;
                                                                    for(i=0;i<=99;i++){
                                                                    if(stock[i].qte != 0){
                                                                    std::cout<<"---"<<stock[i].nom<<" , "<<stock[i].prix<<" , "<<stock[i].qte<<std::endl;
                                                                    }}
                                                                    std::cout<<"\033[33m----------saisir le nom du produit----------\033[32m"<<std::endl;
                                                                std::cin>>nom;
                                                                //verification de lexistance du produit dans la facture
                                                                while( verif_exist(nom,facturier) == false){
                                                                    std::cout<<"ce nom existe deja dans la facture,en saisir un autre"<<std::endl;
                                                                    std::cin>>nom;
                                                                }
                                                                
																//verification de lexistance du produit dans le stock
                                                                while( verif_exist(nom,stock) == true){
                                                                    std::cout<<"ce nom n'existe pas dans le stock,en saisir un autre"<<std::endl;
                                                                    std::cin>>nom;
                                                                }
                                                                in = verif_index(nom,stock);
                                                                std::cout<<"\033[33msaisir la quantite\033[31m"<<std::endl;
                                                                std::cin>>s;
                                                                while(s > stock[verif_index(nom,stock)].qte){
                                                                    std::cout<<"pas assez de "<<nom<<"saisir une autre quatite"<<std::endl;
                                                                }
                                                                p = stock[verif_index(nom,stock)].prix;
                                                                for(i=0;i<=99;i++){
                                                                    if(facturier[i].qte == 0){
                                                                        facturier[i].nom = nom;
                                                                        facturier[i].qte = s;
                                                                        stock[verif_index(nom,stock)].qte -= s;
                                                                        facturier[i].prix = p;
                                                                        save_all_data(stock);
                                                                        break;
                                                                    }
                                                                }

                                                                }
                                                                else if(touche == 's' || touche == 'S'){
                                                                    facture_save(facturier);
                                                                    ajout = 1;
                                                                }}
                }
                //on remet les variable des menus a 0;
                ajout=0;
                choix = 10;
                facturier[100]={};
            }
            case 2:{//ajouter un produit//
                std::cout<<"\033[34m-------ajouter des produits----------\033[0m"<<std::endl;
                while(ajout!=1){
                    std::cout<<"\033[32m[w]\033[0m\033[42m ajouter un produit\033[0m"<<std::endl;
                    std::cout<<"\033[32m[s]\033[0m\033[42m revenir au menu principal\033[0m"<<std::endl;
                    system("cls");
                                                            //verification touche et prise des donnees dans les varriables nom , s , p
                                                                if(_kbhit()){
                                                                touche = _getch();
                                                                if(touche == 'w' || touche == 'W'){
                                                                if(index_menu>0){
                                                                std::cout<<"\033[32msaisir le nom\033[31m"<<std::endl;
                                                                //mise du bon index
                                                                while(stock[in].nom!=""){
                                                                    in++;
                                                                }
                                                                std::cin>>nom;
                                                                //verification de lexistance du produit
                                                                while( verif_exist(nom,stock) == false){
                                                                    std::cout<<"\033[32m ce nom existe deja ,en saisir un autre\033[31m"<<std::endl;
                                                                    std::cin>>nom;
                                                                }
                                                                std::cout<<"\033[32msaisir la quantite\033[31m"<<std::endl;
                                                                std::cin>>s;
                                                                std::cout<<"\033[32msaisir le prix\033[31m"<<std::endl;
                                                                std::cin>>p;
                                                                for(i=0;i<=99;i++){
                                                                    if(stock[i].qte == 0){
                                                                        stock[i].nom = nom;
                                                                        stock[i].qte = s;
                                                                        stock[i].prix = p;
                                                                        break;
                                                                    }
                                                                }
                                                                save_all_data(stock);
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
            while(!stock[index].qte){
                std::cout <<"ce produit nexiste pas en saisir un nouveau"<<std::endl;
                std::cin>>nom;
            index = verif_index(nom,stock);
            }
            std::cout<<"que voulez vous modifier?"<<std::endl;
                while(ajout!=1){
                    std::cout<<"\033[32m[w]\033[0m\033[42m pour modifier le nom \033[0m"<<std::endl;
                    std::cout<<"\033[32m[s]\033[0m\033[42m pour modifier le prix\033[0m"<<std::endl;
                    std::cout<<"\033[32m[e]\033[0m\033[42m pour modifer la quantite\033[0m"<<std::endl;
                    std::cout<<"\033[32m[d]\033[0m\033[42m pour quitter\033[0m"<<std::endl;
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
                save_all_data(stock);
                break;
            }
                
            }

        system("cls");
        }
        //fin verif touche

std::cout<<"\033[41 mmerci d'avoir utiliser le programme";
save_all_data(stock);
    
//
    return 0;
}
