#include<iostream>
#include<conio.h>

int main(){
    char touche;
    while(true){
        if(_kbhit()){
            touche = _getch();
            if(touche == 'p' || touche == 'P'){
                std::cout<<"porc"<<std::endl;
            }else if(touche == 'o' || touche == 'O'){
                std::cout<<"orc"<<std::endl;
            }
        }
    }
}