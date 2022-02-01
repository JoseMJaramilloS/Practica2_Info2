#include <iostream>
#include "functions.h"

using namespace std;

//variables globales
int **matriz, n; //cuadrado magico
char cadena[30];

int main()
{
    int select, num=0, a=0, b=0; //tam=0;
    char char_array[16]={'\0'}, charA[201];
    int money[10]={50000,20000,10000,5000,2000,1000,500,200,100,50};

    cout<<"MENU PRINCIPAL"<<endl;
    cout<<"(1) Combinacion de billetes"<<endl;
    cout<<"(2) Arreglo de letras repetidas"<<endl;
    cout<<"(4) Cadena de numeros a enteros"<<endl;
    cout<<"(5) Numero entero a cadena"<<endl;
    cout<<"(7) Borrar letras repetidas"<<endl;
    cout<<"(10) Numeros romanos"<<endl;
    cout<<"(12) Cuadrado magico"<<endl;
    cout<<"(13)"<<endl;
    cout<<"(15) Interseccion de rectangulos"<<endl;
    cout<<"(18) Permutaciones lexicograficas"<<endl;
    while(true){

        cout<<"\nIngrese numero del problema: ";
        cin>>select;

        switch(select){

            case 1:{
                cout<<"\nPROBLEMA 1"<<endl;
                cout<<"Ingrese cantidad de dinero: "; cin>>num;
                for(int i=0; i<=9; i++){
                    cout<<money[i]<<": "<<num/money[i]<<endl;
                    num= num - num/money[i]*(money[i]);
                }
                cout<<"Faltante: "<<num<<endl;
                break;
            }

            case 2:{
                cout<<"\nPROBLEMA 2"<<endl;
                for(int i=0;i<200;i++){
                    charA[i]=rand()%26+65; //rand()%26: genera numeros entre 0 y 25
                    cout<<charA[i];
                }
                isRepeat(charA); //Funcion de comparacion
                break;
            }

            case 4:{
                cout<<"\nPROBLEMA 4"<<endl;
    //            //para memoria dinamica: gets(cadena);
    //            cout<<"Ingrese longitud de la cadena: "; cin>>tam;
    //            char *cadena= new char[5]; //Reservo memoria en el heap, para un arreglo de tamaño tam;
    //            cout<<"Ingrese cadena: "; cin>>cadena;
    //            num = char2int_2(cadena, tam);
    //            cout<<"Numero: "<<num<<endl;
    //            delete[] cadena;

                cout<<"Ingrese cadena: "; cin>>char_array;
                num = char2int(char_array);
                cout<<"Numero: "<<num<<endl;

                break;
            }

            case 5:{
                cout<<"\nPROBLEMA 5"<<endl;

                cout<<"Ingrese numero: "; cin>>num;

                a= digitsCalc(num);//a= digitos; se usa funcion para calcular digitos

                char *cad=new char[a+1]; //creo variable puntero del tamaño de los digitos del numero
                cad[a]='\0';//agrego fin de linea a la cadena

                int2char(cad,a,num); //funcion de conversion
                mostrarCadena(cad); //funcion que muestra la cadena

                delete[] cad;
                cout<<endl;
                break;
            }

            case 7:{
                cout<<"\nPROBLEMA 7"<<endl;
                cout<<"Ingrese una cadena de caracteres: ";
                fflush(stdin); //limpio basura de la terminal
                cin.getline(cadena,30,'\n'); //se obtiene una cadena de la entrada estandar

                //cadena ya es un arreglo y apunta a una direccion
                cout<<"Original: "; mostrarCadena(cadena);
                cout<<". Sin repetidos: "; borrarRepetidos(cadena);
                cout<<endl;

                break;
            }

            case 10:{
                cout<<"\nPROBLEMA 10"<<endl;

                num=0; //reiniciar variable para no tener problemas
                cout<<"Ingrese numero romano: "; cin>>char_array;    //MMMDCCCLXXXVIII
                for(int i=0; char_array[i] !='\0'; i++){ //El ciclo está restringido por el caracter de fin de cadena

                    a=Roman2int(char_array[i]);
                    b=Roman2int(char_array[i+1]);

                    if(a>=b){
                        num +=a;
                    }
                    else{
                        num -=a;
                    }
                }

                cout<<"El numero ingresado fue: "<<char_array<<endl;
                cout<<"Que corresponde a: "<<num<<endl;
                break;
            }

            case 12:{
                cout<<"\nPROBLEMA 12"<<endl;
                pedirMatriz();
                mostrarMatriz(matriz,n);
                isMagic(matriz,n);

                //LIBERO MEMORIA
                for(int i=0;i<n;i++){
                   delete[] matriz[i];
                }
                delete[] matriz;

                break;
            }

            case 13:{
                break;
            }

            case 15:{
                cout<<"\nPROBLEMA 15"<<endl;

                int rec1[4], rec2[4], sec[4];    //rectangulos 1 y 2, sec corresponde a su interseccion

                cout<<endl<<"Ingrese el rectangulo 1 (x, y, ancho, alto). Un dato a la vez: "<<endl;
                for(int i = 0; i<4; i++){
                    cin>> *(rec1+i);
                }


                cout<<endl<<"Ingrese el rectangulo 2 (x, y, ancho, alto). Un dato a la vez: "<<endl;
                for(int i = 0; i<4; i++){
                    cin>> *(rec2+i);
                }


                cout<<endl<<"El rectangulo interseccion corresponde a: ";

                if(intersectRectangle(rec1,rec2,sec) == true)    // if true, se ha encontrado la interseccion
                    cout<<"{"<<*(sec)<<","<<*(sec+1)<<","<<*(sec+2)<<","<<*(sec+3)<<"}"<<endl<<endl;

                else if (intersectRectangle(rec2,rec1,sec)== true) //vectores en orden contrario
                    cout<<"{"<<*(sec)<<","<<*(sec+1)<<","<<*(sec+2)<<","<<*(sec+3)<<"}"<<endl<<endl;

                else cout<<endl<<"Interseccion vacia. "<<endl;  //Se han revisdo todos los casos, no hay interseccion
                break;
            }

            case 18:{
                cout<<"\nPROBLEMA 18"<<endl;
                cout<<"Digite el numero de permutacion deseada: "; cin>>num;
                int *digitos= new int(10); //creo puntero porque necesito usarla en funcion y que cambie globalmente
                int numeros[10]={0,1,2,3,4,5,6,7,8,9};


                for (int i=*digitos-1;i>=0;i--) { //i es el factoial
                    for (int j=*digitos-1;j>=0;j--) { //j es q: da la posicion del proximo valor en el arreglo
                        if(j*factorial(i)<num){ //si es el mayor multiplo de i, menor que num (valor ingresado actualizable)
                            num -= j*factorial(i);
                            //cout<<"q: "<<j<<endl;//testeo
                            //cout<<numeros[j]<<endl;//testeo
                            cout<<numeros[j];

                            quitaElementos(numeros, j, digitos);//funcion que quita elementos (arreglo, indice, digitos)
                            break;
                        }
                    }
                }
                delete digitos;
                cout<<endl;
                break;
            }

        }
    }
    return 0;
}
