#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>


int main(int argc, char** argv)
{
    unsigned seed = time(0);
    srand(seed);
    int coef;
    std::cout<<"digite um numero"<<std::endl;
    std::cin>> coef;
    int size = 0; 
    size = rand()%coef;
    std::cout<< size<< std::endl;
    int vet[size];
    

    for(int i = 0;i<size;i++){
        int aux=rand()%coef;
        if(aux == 0){
            std::cout <<"-------deuzero--------"<<std::endl;
            aux=(1+rand()%coef);
        }
        vet[i]=aux;
        coef--;
    }

    for(int i = 0;i<size;i++){
        std::cout<< vet[i]<<std::endl;
    }
   
    return 0;
}