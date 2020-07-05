#include <iostream>
#include <vector>    

#include "init_robots.h"
#include "init_human.h"
#include "init_grid.h"

using namespace std;

int main(){
    Robot r;
    Human h;
    Grid g;

    vector <int> position;

    position = g.initialisation();         //Run initialization

    g.printGrid(position);                 //Print grid with position as input

    auto size = position.size();           //size of position vector
    g.win     = 0;                         //value to win-factor

    //game loop
    while(position[0]!=0 && position[1]!=0 && position[0]!=23 && position[1]!=15 && g.win==0){
        position = h.moveHuman(position);
        position = r.moveRobot(position);
        g.printGrid(position);
        
        //check for lose-factor
        for(int i = 3; i < size; i=+3){  
            if(position[0]==position[i] && position[1]==position[i+1]){
                g.win =1;
            }
        break;
        }
    
    }
//Lose if:
    if(g.win==1){
        cout<<endl;                                                                  
        cout<<"OO    OO    OOOOOO     OO   OO      OO       OOOOOO    OOOOO   OOOOO "<<endl;
        cout<<" OO  OO    OO    OO    OO   OO      OO      OO    OO   OO      OO    "<<endl;
        cout<<"  OOOO     OO    OO    OO   OO      OO      OO    OO    OOO    OOOOO "<<endl;
        cout<<"   OO      OO    OO    OO   OO      OO      OO    OO      OO   OO    "<<endl;
        cout<<"   OO       OOOOOO     OOOOOOO      OOOOO    OOOOOO    OOOOO   OOOOO "<<endl;


    }
    //Win else:
    else{
        cout<<endl;                                                                        
        cout<<"OO    OO    OOOOOO     OO   OO    OO     OOO   OO   OO   OOO     OO	"<<endl;
        cout<<" OO  OO    OO    OO    OO   OO     OO   OO O   OO   OO   OOOO    OO  "<<endl;
        cout<<"  OOOO     OO    OO    OO   OO     OO   O  OO  OO   OO   OO  OO  OO  "<<endl;
        cout<<"   OO      OO    OO    OO   OO      OO O    OO O    OO   OO    OOOO  "<<endl;
        cout<<"   OO       OOOOOO     OOOOOOO       OOO     OOO    OO   OO     OOO  "<<endl; 
    }
    return 0;
}