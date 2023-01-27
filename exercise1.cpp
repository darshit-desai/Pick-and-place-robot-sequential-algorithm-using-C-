#include <iostream>

/**
 * @file main.cpp
 * @author Darshit Desai (darshit@umd.edu)
 * @brief Exercise#1 Assignment#1
 * @version 0.1
 * @date 2022-09-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief Contains the whole program and variables
 * 
 * @return int 
 */
int main(){
    char grpr{}, part{}, table{}, u_inp{};
    /**
     * @brief The portion consists of do while loop running throughout
     * the program. It consists of switch cases, loops and comparisons as
     * per the rubric and guidelines given
     */
    do
    {
        std::cout << "\n-----------------------------------";
        std::cout << "\nEXERCISE 1";
        std::cout << "\n-----------------------------------";
        
        //Part pick up portion
        std::cout << "\nWhich part to pick up (c, b, p)? ";
        std::cin>>part;
        //Checking validity of user input
        if (part!='c' && part!='b' && part!='p')
        {
            std::cout<<"\n";
            u_inp='y';
            continue;
        }
        //checking validity of user input  for gripper choice
        while (1){
            std::cout << "-----------------------------------";
            std::cout << "\nWhich gripper to use (s, f)? ";
            std::cin>>grpr;
            if (grpr!='s'&&grpr!='f'){
                continue;                      
            }
            else{
                break;
            }
        }
        //test variable use for decision making statements
        int test{0};

        //switch case of gripper selection        
        switch (grpr)
        {
        case 's':
            if (part=='b'){
                test=1;
                break;
            }
            else if(part=='c'){
                std::cout <<"\n-----------------------------------";
                std::cout <<"\nFailure: Cannot pick up the cube with the suction gripper.";
                break;
            }
            else{
                std::cout <<"\n-----------------------------------";
                std::cout <<"\nFailure: Cannot pick up the peg with the suction gripper.";
                break; 
            }
        case 'f':
            if (part=='c'||part=='p'){
                test=1;
                break;
            }
            else{
                std::cout <<"-----------------------------------";
                std::cout <<"\nFailure: Cannot pick up the ball with the finger gripper.";
                break;
            } 
        }

        //decision statement indicating user has selected correct shape gripper combinations
        if(test==1){
            //loop for checking valid choice by user of table colour
            while (1){
                std::cout << "-----------------------------------";
                std::cout << "\nWhich table to use (r, g, b)? ";
                std::cin>>table;
                if (table!='r'&&table!='g'&&table!='b'){
                    continue;                      
                }
                else{
                    break;
                }
            }
            std::cout <<"-----------------------------------";
            switch (part)
            {
            case 'b':
                if(table=='g'){
                    std::cout<<"\nSuccess: The ball was placed on the green table.";
                    break;
                }
                else if (table=='r')
                {
                    std::cout<<"\nFailure: Cannot place the ball on the red table.";
                    break;
                }
                else if (table=='b')
                {
                    std::cout <<"\nFailure:Cannot place the ball on the blue table";
                    break;
                }
            case 'c':
                if(table=='r'){
                    std::cout<<"\nSuccess: The cube was placed on the red table.";
                    break;
                }
                else if (table=='g')
                {
                    std::cout<<"\nFailure: Cannot place the cube on the green table.";
                    break;
                }
                else if (table=='b')
                {
                    std::cout <<"\nFailure:Cannot place the cube on the blue table";
                    break;
                }
            case 'p':
                if(table=='b'){
                    std::cout<<"\nSuccess: The peg was placed on the blue table.";
                    break;
                }
                else if (table=='r')
                {
                    std::cout<<"\nFailure: Cannot place the peg on the red table.";
                    break;
                }
                else if (table=='g')
                {
                    std::cout <<"\nFailure:Cannot place the peg on the green table";
                    break;
                }
            }
        }

        //loop for checking valid user input of try again
        while (1)
        {
            std::cout <<"\n-----------------------------------";
            std::cout << "\nTry again (y, n)? ";
            std::cin>>u_inp;
            if(u_inp!='y'&&u_inp!='n'){
                continue;
            }
            else{
                break;
            }  
        }        
    } while (u_inp=='y'||u_inp=='Y');
}