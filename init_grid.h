/*
* init_grid.h
*
* Created on: June 1, 2020
*
Author: Tom & Binnert
*/

// List of includes required for the functions you are declaring

#ifndef init_init_H
#define init_init_H

#include <iostream>
#include <vector>

using namespace std;

class Grid
{
    public:
        int win;        //initialize win

        std::vector <int> initialisation(){
            //Define temperary values
            int robotamount;
            string direction;

            //Determine amount of robots
            cout<< "How many robots do you want to play against?"<<endl;
            cin>>robotamount;

            //Define vectors for direction and position
            vector <string> directionr(robotamount*3+3);
            vector <int> position(robotamount*3+3);

            //Determine and store own x-position, y-position and orientation into an array
            cout<< "----------------------------------- \nFrom which x-position do you want to start?"<<endl;
            cin>>position[0]; 
            cout<< "From which y-position do you want to start?"<<endl;
            cin>>position[1]; 
            cout<< "From which orientation do you want to start? \n\n North = 1 \n East  = 2 \n South = 3 \n West  = 4"<<endl;
            cin>>position[2];  

            //Make two new arrays. One with the x-position and y-position, the other with just the orientation of each robot    
            for (int i = 3; i < robotamount*3+3 ; i += 3){
                cout<< "----------------------------------- \nWhat is the x-position of robot "<< i/3 << "?"<<endl;
                cin>>position[i];

                cout<< "What is the y-position of robot "<< i/3 << "?"<<endl;
                cin>>position[i+1];

                cout<< "What is the orientation of robot "<< i/3 << "? \n\n North = 1 \n East  = 2 \n South = 3 \n West  = 4" <<endl;
                cin>>position[i+2];
            
            //Fill vector with purpose of printing orientation
                if(position[i+2]==1){
                    directionr[i+2] = "North";
                }
                else if(position[i+2]==2){
                    directionr[i+2] = "East";
                }
                else if(position[i+2]==3){
                    directionr[i+2] = "South";
                }
                else if(position[i+2]==4){
                    directionr[i+2] = "West";
                }
            }
            //Fill vector with purpose of printing orientation
            if(position[2]==1){
                direction = "North";
            }
            else if(position[2]==2){
                direction = "East";
            }
            else if(position[2]==3){
                direction = "South";
            }
            else if(position[2]==4){
                direction = "West";
            }

            //Print out the position and orientation of the human controlled robot on a single line
            cout<< "--------------------------------------\n All positions and orientations: \n--------------------------------------"<<endl;
            cout<< "You:       ("<<position[0]<<","<<position[1]<<") "<< direction<<endl;
            for (int j = 3; j < robotamount*3+3; j = j+3){
                cout<< "Robot "<<j/3<<":   ("<<position[j]<<","<<position[j+1]<<") "<< directionr[j+2]<<endl;
            }
            return position;
}

        int printGrid(std::vector<int> position){ 
            //check size of the vector
            auto size = position.size();
            //initialize length and width
            int length = 23;
            int width = 15;

            // fill grid with |_|
            string grid[width+1][length+1];
            for(int x = 1; x<width; x++){
                for(int y = 1; y<length; y++){
                    grid[x][y]= {"|_|"};
                }
            }

            // fill grid with human     
            if(position[2] == 1){
                grid[position[1]][position[0]]={"|↑|"};}
            else if(position[2] == 2){
                grid[position[1]][position[0]]={"|→|"};}
            else if(position[2] == 3){
                grid[position[1]][position[0]]={"|↓|"};}
            else if(position[2] == 4){
                grid[position[1]][position[0]]={"|←|"};}

            // fill grid with robot
            for (int i = 3 ; i < size ; i+=3 ){
                if(position[i+2] == 1){
                    grid[position[i+1]][position[i]]={"|▲|"};}
                else if(position[i+2] == 2){
                    grid[position[i+1]][position[i]]={"|►|"};}
                else if(position[i+2] == 3){
                    grid[position[i+1]][position[i]]={"|▼|"};}
                else if(position[i+2] == 4){
                    grid[position[i+1]][position[i]]={"|◄|"};}
            }

            // print grid
            cout<<" _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _ "<<endl;
            for(int x = 1; x<width; x++){
                for(int y = 1; y<length; y++){
                    cout<<grid[x][y];
                }
                cout<<endl;
            }
        }

};

#endif