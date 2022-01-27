#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
    int select, num=0, a=0, b=0; //tam=0;
    char char_array[16]={'\0'};
    int money[10]={50000,20000,10000,5000,2000,1000,500,200,100,50};

    cout<<"MENU PRINCIPAL"<<endl;
    cout<<"(1) Combinacion de billetes"<<endl;
    cout<<"(2)"<<endl;
    cout<<"(4) Cadena de numeros a enteros"<<endl;
    cout<<"(5)"<<endl;
    cout<<"(7)"<<endl;
    cout<<"(10) Numeros romanos"<<endl;
    cout<<"(12)"<<endl;
    cout<<"(13)"<<endl;
    cout<<"(15)"<<endl;
    cout<<"(18)"<<endl;
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
        case 2:
            break;
        case 4:{
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
        case 5:
            break;
        case 7:
            break;

        case 10:{
            num=0; //reiniciar variable para no tener problemas
            cout<<"\nPROBLEMA 2"<<endl;
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

        case 12:
            break;
        case 13:
            break;
        case 15:
            break;
        case 18:
            break;

        }
    }
    return 0;
}