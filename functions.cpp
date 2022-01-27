#include "functions.h"

//Implementacion de las funciones
int Roman2int(char letra){//10
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

int char2int(char cadena[]){//4
    int entero=0;

    for(int i=0 ; cadena[i]!='\0' ; i++){
        entero = entero*10 + cadena[i]-'0';       //por codigo ASCII: ('9'-'0')=(57-48)=9
        //cout<<i<<"->"<<entero<<endl;
    }

    return entero;
}

int char2int_2(char cadena[], int tam){
    int entero=0;

    for(int i=0 ; i<tam ; i++){
        entero = entero*10 + cadena[i]-'0';       //por codigo ASCII: ('9'-'0')=(57-48)=9
        //cout<<i<<"->"<<entero<<endl;
    }

    return entero;
}
