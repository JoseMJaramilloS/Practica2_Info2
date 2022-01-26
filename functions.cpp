#include "functions.h"

//Implementacion de las funciones
int Roman2int(char letra){

    int num;
    switch(letra){
    case 'M':
        num= 1000;
        break;
    case 'D':
        num= 500;
        break;
    case 'C':
        num= 100;
        break;
    case 'L':
        num= 50;
        break;
    case 'X':
        num= 10;
        break;
    case 'V':
        num= 5;
        break;
    case 'I':
        num= 1;
        break;
    default:
        num=0;
        break;
    }
    return num;
}
