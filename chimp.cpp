#include<iostream>
#include"rlutil.h"
#include <stdlib.h>



///declaracion de los valores que luego daran referencia a las carac del chimpoco
const int tamanio=7;
const int vida=0, danioMax=1,danioMin=2,pas=3,critico=4, pot=5, danioAct=6;

///vector que almacena las caracteristicas
int vecChimpoco[tamanio];


using namespace std;
void chimp()
{
    int    y=0;
    bool a=true;
    while (a!=false)
    {
        system("cls");
        rlutil::locate (52,10);
        cout<<"¿Cual sera tu chimpoco?"<<endl;
        rlutil::locate (52,12);
        cout<<"Rockito"<<endl;
        rlutil::locate (52,13);
        cout<<"Picante"<<endl;
        rlutil::locate (52,14);
        cout<<"Freddy"<<endl;
        rlutil::locate (52,15);
        cout<<"Rayin"<<endl;
        rlutil::locate (52, 16);
        cout<<"Volver al menu principal"<<endl;
        rlutil::locate (76,12 + y);
        cout<<(char)60;
        rlutil::locate (51,12 + y);
        cout<<(char)62;


        int key = rlutil::getkey();

        switch (key)
        {
        case 14: //flecha ariba
            rlutil::locate (52,12 + y);
            cout<<" ";                           //Esto es para borrar la anterior flecha
            rlutil::locate (67,12 + y);
            cout<<" ";
            y--; //para ir subiendo
            if(y<0)
            {
                y=0;                     //para que el cursor no se mueva mas alla de la opcion 5
            }





            break;
        case 15: //flecha abajo
            rlutil::locate (52,12 + y);
            cout<<" ";                          //Esto es para borrar la anterior flecha
            rlutil::locate (67,12 + y);
            cout<<" ";

            y++; //para ir bajando
            if(y>4)
            {
                y=4;                    //para que el cursor no se mueva mas alla de la opcion 5
            }
            break;
        case 1:
            switch(y)
            {

            case 0:
                ///rockito
                vecChimpoco[vida]=1200;
                vecChimpoco[danioMax]=50;
                vecChimpoco[danioMin]=40;

                cout<<"ENTRO A ROCKITO Y EL VALOR DE VIDA ES"<<vecChimpoco[vida]<<endl;
                break;
            case 1:
                ///Picante
                vecChimpoco[vida]=500;
                vecChimpoco[danioMax]=65;
                vecChimpoco[danioMin]=55;


                break;
            case 2:
                ///Freddy
                vecChimpoco[vida]=700;
                vecChimpoco[danioMax]=55;
                vecChimpoco[danioMin]=35;

                break;
            case 3:

                break;
            case 4:
                a=false;
                break;

            }



        }




    }
}




