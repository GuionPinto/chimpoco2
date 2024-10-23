#include<iostream>
#include"rlutil.h"
#include"chimp.h"
using namespace std;
int y=0;


void menu ()
{
    bool n=true;
    while(n!=false)
    {
        system("cls");

        rlutil::hidecursor();
        rlutil::locate (52,10);
        cout<<"CHIMPOCO FIGHT"<<endl;
        rlutil::locate (54,12);
        cout<<"Aventura"<<endl;
        rlutil::locate (54,13);
        cout<<"Versus"<<endl;
        rlutil::locate (54,14);
        cout<<"GOD MODE"<<endl;
        rlutil::locate (54,15);
        cout<<"Estadisticas"<<endl;
        rlutil::locate (54,16);
        cout<<"Manual"<<endl;
        rlutil::locate (54,17);
        cout<<"Salir"<<endl;
        rlutil::locate (52,12 + y);
        cout<<(char)62;
        rlutil::locate (67,12 + y);
        cout<<(char)60;
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
            if(y>5)
            {
                y=5;                    //para que el cursor no se mueva mas alla de la opcion 5
            }
            break;

        case 1: //enter
            switch (y)
            {
            case 0: //Aventura
                chimp();
                break;

            case 1: //Versus

                break;

            case 2: //GOD MODE

                break;

            case 3: //Estadisticas

                break;

            case 4: //Manual

                break;

            case 5: //salir del programa
                n=false;
                break;


            }

        }

    }

}
