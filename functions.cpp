#include "functions.h"

//IMPLEMENTACION DE FUNCIONES
int Roman2int(char letra){//10 Transforma numeros romanos a enteros
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

int char2int(char cadena[]){//4 Convierte cadenas de caracteres a enteros
    int entero=0;

    for(int i=0 ; cadena[i]!='\0' ; i++){
        entero = entero*10 + cadena[i]-'0';       //por codigo ASCII: ('9'-'0')=(57-48)=9
        //cout<<i<<"->"<<entero<<endl;
    }

    return entero;
}

int char2int_2(char cadena[], int tam){//4 Convierte cadenas de caracteres a enteros (MEMORIA DINAMICA)
    int entero=0;

    for(int i=0 ; i<tam ; i++){
        entero = entero*10 + cadena[i]-'0';       //por codigo ASCII: ('9'-'0')=(57-48)=9
        //cout<<i<<"->"<<entero<<endl;
    }

    return entero;
}

//void int2char(int *num, ){//5 Convierte enteros a cadena de caracteres
//    char *cadena;

//}

void isRepeat(char arreglo[]){//2 Encuentra el numero de letras repetidas en un arreglo
    char letra=65;
    int count;
    for(int i=0; i<26; i++,letra++){//Recorre el alfabeto ASCII
        count=0;

        for(int j=0;j<200;j++){//Recorre el arreglo
            if(letra==arreglo[j]) {
                count++; //Compara las letras y cuenta las repetidas
            }
        }
        cout<<"\n"<<letra<<": "<<count;//Se imprimen resultados
    }
    cout<<endl;
}
