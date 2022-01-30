#include "functions.h"
extern int **matriz, n;//llamando variables globales

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

void pedirMatriz(){//12 Pide al usuario que digite una matriz cuadrada de dimension n
    cout<<"Ingrese dimension de la matriz: "; cin>>n;

    matriz = new int*[n]; //reservando filas
    for(int i=0;i<n;i++){
        matriz[i]= new int[n];
    }

    //Se piden datos al usuario
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"Digite dato para la posicion ["<<i<<","<<j<<"]: ";
            cin>>*(*(matriz + i)+j);
        }
    }
}

void mostrarMatriz(int **matriz, int n){//12 Imprime una matriz cuadrada
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<*(*(matriz + i)+j)<<" ";
        }
        cout<<endl;
    }
}

void isMagic(int **matriz, int n){//12 Comprueba si es cuadrado magico
    int sumFil=0, sumCol=0, sumDiag1=0, sumDiag2=0, aux=0;
    bool magic=false;

    for(int i=0;i<n;i++){
        sumFil=0;
        sumCol=0;
        for(int j=0;j<n;j++){
            sumFil += *(*(matriz + i)+j); //sumando filas de la matriz
            sumCol += *(*(matriz + j)+i); //sumando columnas de la matriz

//            if(i==j) sumDiag1 += *(*(matriz + i)+j); //sumando diagonal1
//            if(n-i==i) sumDiag2 += *(*(matriz + i)+j); //sumando diagonal2

            if(aux==sumFil && aux==sumCol && i>0) magic=true; //se prueban filas y columnas
            else magic=false;
        }
        aux=sumFil;//almacenando el valor de una fila
        sumDiag1 += *(*(matriz + i)+i);//sumando diagonal | i=j
        sumDiag2 += *(*(matriz + i)+((n-1)-i));//sumando diagonal | (i,(n-1)-i), considerando que el indice es n-1

    }
    if(sumDiag1==aux && sumDiag1==aux) magic=true; //se prueban diagonales
    else magic=false;

    if(magic==true) cout<<"Es cuadrado magico"<<endl;
    else cout<<"NO es cuadrado magico"<<endl;

}
