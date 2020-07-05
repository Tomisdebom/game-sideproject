/*
* init_robots.h
*
* Created on: May 30, 2020
*
Author: Tom & Binnert
*/

// List of includes required for the functions you are declaring

#ifndef init_robot_H
#define init_robot_H

#include <iostream>
#include <vector>

using namespace std;

class Robot
{
    public:
        std::vector<int> moveRobot(std::vector<int> position){   
            //intitialize size of position vector         
            auto size = position.size();

            //calculate difference in x and y direction
            for (int i = 3 ; i <size ; i +=3 ){
                int xverschil = position[0]-position[i];
                int yverschil = position[1]-position[i+1];
            //Move robot in the direction where the difference in coordinates is largest
                if(yverschil>=0 && abs(yverschil)>=abs(xverschil)){
                    if(position[i+2] == 2 || position[i+2] == 4){
                        position[i+2]= 3;   
                    }
                    else{
                        position[i+1]++;
                    }
                }
                else if(yverschil<0 && abs(yverschil)>=abs(xverschil)){
                    if(position[i+2] == 2 || position[i+2] == 4){
                        position[i+2]= 1;   
                    }
                    else{
                        position[i+1]--;
                    }
                }
                else if(xverschil>=0 && abs(xverschil)>abs(yverschil)){
                    if(position[i+2] == 1 || position[i+2] == 3){
                        position[i+2]= 2;   
                    }
                    else{
                        position[i]++;
                    }
                }
                else if(xverschil<0 && abs(xverschil)>abs(yverschil)){
                    if(position[i+2] == 1 || position[i+2] == 3){
                        position[i+2]= 4;   
                    }
                    else{
                        position[i]--;
                    }
                }
            }
            return(position);
        };
};

#endif

