/*
* init_human.h
*
* Created on: May 30, 2020
*
Author: Tom & Binnert
*/

// List of includes required for the functions you are declaring

#ifndef init_human_H
#define init_human_H

#include <iostream>
#include <vector>

using namespace std;

class Human
{
    public:

        std::vector<int> moveHuman(std::vector<int> position){
            int move;

            cout<<"\n Choose your move: \n\n Forward       = 1 \n Backward      = 2 \n Rotate right  = 3 \n Rotate left   = 4"<<endl;
            cin>>move;

            // turning
            if(position[2]==1 && move==3){
                position[2]=2;
            }
            else if(position[2]==1 && move==4){
                position[2]=4;
            }
            else if(position[2]==2 && move==3){
                position[2]=3;
            }
            else if(position[2]==2 && move==4){
                position[2]=1;
            }
            else if(position[2]==3 && move==3){
                position[2]=4;
            }
            else if(position[2]==3 && move==4){
                position[2]=2;
            }
            else if(position[2]==4 && move==3){
                position[2]=1;
            }
            else if(position[2]==4 && move==4){
                position[2]=3;
            }

            // forwards and backwards
            if(position[2]==1 && move==1){
                position[1]--;
            }
            else if(position[2]==1 && move==2){
                position[1]++;
            }
            else if(position[2]==2 && move==1){
                position[0]++;
            }
            else if(position[2]==2 && move==2){
                position[0]--;
            }
            else if(position[2]==3 && move==1){
                position[1]++;
            }
            else if(position[2]==3 && move==2){
                position[1]--;
            }
            else if(position[2]==4 && move==1){
                position[0]--;
            }
            else if(position[2]==4 && move==2){
                position[0]++;
            }
            return (position);
        };
};

#endif