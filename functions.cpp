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

int digitsCalc(int num){//5 Calcula el numero de digitos de un numero entero
    int digitos=0;
    while (num !=0) {
        num /= 10;
        digitos++;
    }

    return digitos;
}

int potencia(int num,int exp){//5 efectua la operacion num^exp
    int rslt=1;
    for (int i=1;i<=exp;i++) {
        rslt *=num;
    }
    return rslt;
}

void int2char(char *cad, int digitos, int num){//5 convierte un numero entero a cadena de caracteres
    int resto;

    for (int i=0;i<digitos;i++) {
        resto=num/(potencia(10,((digitos-1)-i)));//num/10^(digitos-1-i)

        *(cad+i)= 48 + resto;
        num = num-resto*(potencia(10,((digitos-1)-i)));
    }
}

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

void mostrarCadena(char *cadena){//7 Muestra una cadena de caracteres
    for(int i=0;*(cadena+i) != '\0';i++){
        cout<<*(cadena+i);
    }
    //cout<<endl;
}

void borrarRepetidos(char *cadena){//7 Borra los repetidos de una cadena

    int j=0;
    char cadena_final[30];
    cadena_final[0] = '\0';

    //comparando las cadenas
    for(int i=0;*(cadena+i) != '\0';i++){               //letra que se evalua: *(cadena+i)
        for (j=0;*(cadena_final+j) != *(cadena+i) && *(cadena_final+j) !='\0';j++);

        if(*(cadena_final+j)=='\0'){ //si llegó hasta el final sin encontrar repetidos
            *(cadena_final+j)=*(cadena+i);
            cout<<*(cadena+i);
        }


    }
}

int factorial(int N){//18 retorna el factorial de un numero
    int result=1;
    if(N<0) cout<<"Operacion factorial no definido para el numero "<<N<<endl;
    else{
        for(;N>0;N--) result*=N;
        //cout <<aux<<"!="<< result<<endl;

        }
    return result;
}

void quitaElementos(int *numeros, int indice, int *digitos){//18 quita elementos de un arreglo

    for (int i=indice;i<*digitos-1;i++) {//recorro los numeros desde el indice hasta el final del actual arreglo
        *(numeros+i)=*(numeros+i+1); //si el valor coincide con el valor en el indice, se omite (se corre a la izquierda)
    }

    (*digitos)--; //se disminuyen los digitos
    numeros[*digitos]='\0';
}

bool intersectRectangle(int *r1, int *r2, int *IN){
    if(*(r1)<= *(r2)){                               //si  x <= x'
        if(*(r1+1)>= *(r2+1)){                       //si  y >= y'
            if((*(r2)<=*(r1)+*(r1+2)) && (*(r2+1)>=*(r1+1)-*(r1+3))){      //si (x' <= x+w) & (y' >= y-h) hay interseccion
                *(IN)= *(r2);         // x', y' pertenecen a la interseccion
                *(IN+1)= *(r2+1);
                if(*(r2) + *(r2+2) <= *(r1)+*(r1+2)) //si x'+w' <= x + w
                    *(IN+2)= *(r2+2)  ;              //w' pertenece a la interseccion
                else *(IN+2)= *(r1)+*(r1+2)-*(r2);   // x+w-x' pertenece a la interseccion
                if(*(r2+1)-*(r2+3) >= *(r1+1)-*(r1+3)) // si y'-h' >= y-h
                    *(IN+3)= *(r1+3)-*(r2+2)+*(r2+3); //h' pertenece a la interseccion (teoria de conjuntos)
                    //*(IN+3)= *(r2+3); //h' pertenece a la interseccion
                else *(IN+3)= -*(r1+1)+*(r1+3)+*(r2+1); // -y+h+y' pertenece a la interseccion
                return true;
            }
        }
        else{
            if((*(r2)<= *(r1)+*(r1+2)) && (*(r1+1)>= *(r2+1)-*(r2+3))){   //si (x' <= x+w) & (y >= y'-h') hay interseccion
                *(IN)=*(r2);         //x' pertenece a la interseccion
                *(IN+1)=*(r1+1);     //y  pertenece a la interseccion
                if(*(r1)+*(r1+2) <= *(r2)+*(r2+2)) //si x+w <= x'+w'
                    *(IN+2) = *(r1)+*(r1+2)-*(r2); // x+w-x' pertenece a la interseccion
                else *(IN+2) = *(r2+2);            //w' pertenece a la interseccion
                if(*(r1+1)-*(r1+3) <= *(r2+1)-*(r2+3)) // si y-h <= y'-h'
                    *(IN+3) = -*(r2+1)+*(r2+3)+*(r1+1);  //-y'+h'+y pertenece a la interseccion
                else *(IN+3) = *(r1+3); //h pertenece a la interseccion
                return true;
            }
        }

    }
    return false;
}
