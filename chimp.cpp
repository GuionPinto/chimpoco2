#include<iostream>
#include"rlutil.h"
#include <stdlib.h>
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()
using namespace std;
const int tamanio= 7;
const int vida=0, danioMax=1,danioMin=2,pas=3,critico=4, pot=5, danioAct=6;

int chimp(int vecChimpoco[])
{
    int vidaActualOponente;
    int vectorOponente[5];

    int  y=0;
    bool salida=true;
    while (salida!=false)
    {
        rlutil::hidecursor();
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
            case 0: //Rockito
                vecChimpoco[vida]=1200;
                vecChimpoco[danioMax]=50;
                vecChimpoco[danioMin]=40;
                salida=false;
                break;
            case 1: //Picante
                vecChimpoco[vida]=500;
                vecChimpoco[danioMax]=65;
                vecChimpoco[danioMin]=55;
                salida=false;
                break;
            case 2: //Freddy
                vecChimpoco[vida]=700;
                vecChimpoco[danioMax]=55;
                vecChimpoco[danioMin]=35;
                salida=false;
                break;
            case 3: //Rayin
                vecChimpoco[vida]=600;
                vecChimpoco[danioMax]=85;
                vecChimpoco[danioMin]=15;
                salida=false;
                break;
            case 4:
                salida=false;
                break;

            }



        }




    }
    if (y!=4)
    {
        srand(time(0));
        int i;
        int vidaAct;
        for (i=1; i<=5 ; i++ ){
        if(i==1){
        vidaAct=vecChimpoco[vida];
        }
        else{
            vecChimpoco[vida]=vidaAct;
        }

            bool salir=false;
            string nombre;
            switch (i)
            {
            case 1:
                nombre = "Stitchard";
                vectorOponente[vida]=150;
                vectorOponente[danioMin]=5;
                vectorOponente[danioMax]=10;
                break;

            case 2:
                nombre = "FurbyZhor";
                vectorOponente[vida]=300;
                vectorOponente[danioMin]=25;
                vectorOponente[danioMax]=45;
                break;

            case 3:
                nombre = "HelloCathy";
                vectorOponente[vida]=450;
                vectorOponente[danioMin]=40;
                vectorOponente[danioMax]=55;
                break;

            case 4:
                nombre = "BabyYorda";
                vectorOponente[vida]=700;
                vectorOponente[danioMin]=55;
                vectorOponente[danioMax]=75;
                break;

            case 5:
                nombre = "TioMickey";
                vectorOponente[vida]=1500;
                vectorOponente[danioMin]=25;
                vectorOponente[danioMax]=150;
                break;
            }
            while(salir!=true)
            {
                int atkChimp= rand() % ((vecChimpoco[danioMax]-vecChimpoco[danioMin]) + 1) + vecChimpoco[danioMin];
                int atkOp = rand() % ((vectorOponente[danioMax]-vectorOponente[danioMin])+ 1) + vectorOponente[danioMin];
                int key = rlutil::getkey();
                system("cls");
                rlutil::locate (52, 10);
                cout<<"Atacar";
                rlutil::locate (52, 11);
                cout<<"Usar item";
                rlutil::locate (65,10 + y);
                cout<<(char)60;
                rlutil::locate (51,10 + y);
                cout<<(char)62;
                rlutil::locate(10, 19);
                cout<<"SITUACION DE BATALLA"<<endl;
                rlutil::locate (52, 8);
                cout<<vectorOponente[vida];
                rlutil::locate (52, 7);
                cout<<nombre;

                switch (key)
                {
                case 14: //flecha ariba
                    rlutil::locate (52,10 + y);
                    y--; //para ir subiendo
                    if(y<0)
                    {
                        y=0;                     //para que el cursor no se mueva mas alla de la opcion 5
                    }
                    break;
                case 15: //flecha abajo
                    y++; //para ir bajando
                    if(y>1)
                    {
                        y=1;                    //para que el cursor no se mueva mas alla de la opcion 5
                    }
                    break;
                case 1:

                    switch(y)
                    {
                    case 0:
                        rlutil::locate (10, 15);
                        cout<<"La vida actual de tu chimpoco es "<<vecChimpoco[vida]<<endl;
                        if(vidaAct==vectorOponente[vida]){
                            rlutil::locate(10,20 );
                        cout<<"EN ESTE ATAQUE PERDIsTE 0 HP"<<endl;
                        }
                        else{

                        rlutil::locate(10,20 );
                        cout<<"EN ESTE ATAQUE PERDIsTE "<<atkOp<<" HP"<<endl;
                        }

                        rlutil::locate (52, 8);
                        cout<<vectorOponente[vida];
                        rlutil::locate (52, 7);
                        cout<<nombre;
                        vectorOponente[vida]-=atkChimp;
                        vecChimpoco[vida]-=atkOp;
                        if(vecChimpoco[vida]<=0 || vectorOponente[vida]<=0)
                        {
                            salir=true;
                        }


                    break;

                    case 1:
                        rlutil::locate (52,11);
                        cout<<"                 ";
                        rlutil::locate (52, 11);
                        cout<<"Boost de Ataque";
                        rlutil::locate(52, 12);
                        cout<<"Boost de Defensa";
                        rlutil::locate (52, 13);
                        cout<<"Pocion";
                        switch (y){
                        case 1:
                            break;
                        case 2:
                            break;
                        case 3:
                            break;



                        }



                    }


                }

            }

        }


    }

}








