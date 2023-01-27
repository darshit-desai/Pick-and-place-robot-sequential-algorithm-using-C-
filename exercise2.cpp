/**
 * @file main.cpp
 * @author Darshit Desai (darshit@umd.edu)
 * @brief Exercise#2 Assignment#1
 * @version 0.1
 * @date 2022-09-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <array>
#include <vector>
#include <string>
//#include <ctype.h>

/**
 * @brief Contains the whole program and variables
 * 
 * @return int 
 */
int main(){
    start:  //Start label used for swinging back to this line from th end
    
    //initialization of the 2d array
    std::array<std::array<std::string, 3>, 3> numbers {{
        {"1", "2", "3"},
        {"4", "5", "6"},
        {"7", "8", "9"}
    }};

    //code display starts
    std::cout << "-----------------------------------";
    std::cout << "\nEXERCISE 2";
    std::cout << "\n-----------------------------------\n";

    //matrix display starts
    for (auto i = 0; i < 3 ; i++)
    {
        for (auto k = 0; k < 3; k++)
        {
            std::cout << numbers.at(i).at(k)<<" ";
        }
        std::cout << "\n";
    }
    std::cout << "\n-----------------------------------";

    //loop for checking user input of red pegs
    char decision_red{};
    while (1){
        std::cout << "\nDo you want to place red pegs? ";
        std::cin>>decision_red;
        if(decision_red!='y' && decision_red!='n')
        {
            continue;
        }
        else{
            break;
        }
    }

    //std::vector<std::string> v1{"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    
    //insertion program of red pegs
      //tag for retaking data from user
    if (decision_red!='n')
    {    
        red1: 
        std::vector<std::string> v4{}; //vector defined for dynamic allocation and comparison
        std::cout<<"\nWhere to place red pegs (1-9)? ";
        std::string c{0}; //string assigned for pushing vector inputs in v4
        while(true)
        {
            std::cin >> c;
            v4.push_back(c);
            if(std::cin.peek() == '\n') {
                // Leave the for loop acting as terminator
                break;
            }            
        }

        //user input validity checking loop
        int flag1{0};
        for (size_t i = 0; i < 3; i++)
        {
            for(size_t n=0;n<3;n++)
            {
                size_t array_size = v4.size();
                for (size_t m{0}; m < array_size; ++m) 
                {
                    if(numbers[i][n].compare(v4.at(m))==0){
                        flag1+=1;
                    }
                }
            }
        }
        if (flag1==0)
        {
            v4.clear();
            goto red1;
        }       
        /**
         * @briev4.clear();
                goto red1;f comparison of vector inputs with 2d indices to 
         * enter pegs in position
         * 
         */
        for (auto i = 0; i < 3 ; i++)
        {
            size_t array_size = v4.size();
            for (auto k = 0; k < 3; k++)
            {
                for (size_t m{0}; m < array_size; ++m) 
                {
                    if(numbers[i][k].compare(v4[m])==0)
                    {
                        numbers[i][k]='r';
                    }
                }  
            }
        }
    }

    //display of newly generated peg arrangement
    for (auto i = 0; i < 3 ; i++)
    {
        for (auto k = 0; k < 3; k++)
        {
            std::cout << numbers.at(i).at(k)<<" ";
        }
        std::cout << "\n";
    }
    
    //Loop for checking 2d array status if full will ask user to exit or restart
    int flag3{0}; 
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if(!(numbers[i][j]>="1" && numbers[i][j]<="9")){
               flag3+=1; 
            }
        }
    }
    //if the flag above counts to 9 that means all elements are filled
    if(flag3 >= 9){
        char red_call{};
        while(true){
            std::cout << "\nTry again (y, n)? ";
            std::cin>>red_call;
            if (red_call!='y'&& red_call!='n')
            {
                continue;
            }
            else{
                break;
            }
        } 
        if (red_call=='y'||red_call=='Y')
        {
            goto start;
        }
        else{
            exit(0);
        }
    }
    /* red insertion program ends here*/

    /**
     * @brief GREEN PEG INSERTION PROGRAM STARTS HERE
     * 
     */
    
    char decision_green{}; //variable for user input of green peg decision
    
    //loop for checking user input of decision_green variable
    while (1){
        std::cout << "\nDo you want to place green pegs? ";
        std::cin>>decision_green;
        if(decision_green!='y' && decision_green!='n')
        {
            continue;
        }
        else{
            break;
        }
    }

    //vector and string initialization for user input
    std::vector<std::string> v5{};
    std::string d{0};

    //decision loop for insertion of green pegs
    if (decision_green!='n')
    {     
        label1: //label for swinging back in case user inputs undesired variable
        std::cout<<"\nWhere to place green pegs (1-9)? ";
        std::cout << "( ";
        size_t j{0};

        //loop for displaying pending spaces where pegs can be inserted
        for (size_t i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if(numbers[i][j]>"1" && numbers[i][j]<"9"){
                    std::cout << numbers[i][j]<< ", ";
                }
            }
        }
        std::cout << ") ? ";

        //insertion loop waits for \n to end
        while(true)
        {
            std::cin >> d;
            v5.push_back(d);
            if(std::cin.peek() == '\n') {
                // Leave the for loop
                break;
            }
        }

        //vector checking incase user inputs invalid responses swing back to label1 
        int inc_ip_flag2{0};
        size_t array_size1 = v5.size();
        for (size_t m{0}; m < array_size1; ++m) 
        {
            if(v5.at(m)>"9" || v5.at(m)<"1"){
                inc_ip_flag2+=1;
            }  
        }
        if (inc_ip_flag2>0)  
        {
            v5.clear();
            goto label1;
        }

        //loop for checking invalid index inputs which are already filled with red pegs   
        int flag1{0};
        for (size_t i = 0; i < 3; i++)
        {
            for(size_t n=0;n<3;n++)
            {
                size_t array_size = v5.size();
                for (size_t m{0}; m < array_size; ++m) 
                {
                    if(numbers[i][n].compare(v5.at(m))==0){
                        flag1+=1;
                    }
                }
            }
        }
        if (flag1==0)
        {
            v5.clear();
            goto label1;
        }
        std::cout<<"\n";
    }

    //after all conditions satisfy program inserts green pegs in master matrix
    for (auto i = 0; i < 3 ; i++)
    {
        size_t array_size = v5.size();
        for (auto k = 0; k < 3; k++)
        {
            for (size_t m{0}; m < array_size; ++m) 
            {
                if(numbers[i][k].compare(v5[m])==0)
                {
                    numbers[i][k]='g';
                }
            }  
        }
    }
    std::cout << "\n-----------------------------------\n";
    //display of modified matrix with pegs placed
    for (int z = 0; z < 3 ; z++)
    {
        for (auto k = 0; k < 3; k++)
        {
            std::cout << numbers.at(z).at(k)<<" ";
        }
        std::cout << "\n";
    }

    //loop for checking whether green+red pegs have filled the 2d array
    int flag4{0};
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            if(!(numbers[i][j]>="1" && numbers[i][j]<="9")){
               flag4+=1; 
            }
        }
    }

    //2d array full or not condition check if true than user given a chance to restart the whole program 
    if(flag4 >= 9){
        char green_call{};
        while(true){
            std::cout << "\nTry again (y, n)? ";
            std::cin>>green_call;
            if (green_call!='y'&& green_call!='n')
            {
                continue;
            }
            else{
                break;
            }
        } 
        if (green_call=='y'||green_call=='Y')
        {
            goto start;
        }
        else{
            exit(0);
        }
    }
  /*GREEN PEG INPUT PROGRAM ENDS HERE*/

  /**
   * @brief BLUE PEG INPUT PROGRAM STARTS HERE  
   * 
   */
    char decision_blue{};
    //decision variable invalid user input check loop
    while (1){
        std::cout << "\nDo you want to place blue pegs (y, n)? ";
        std::cin>>decision_blue;
        if(decision_blue!='y' && decision_blue!='n')
        {
            continue;
        }
        else{
            break;
        }
    }

    //Vector initialization for dynamic strings
    std::vector<std::string> v6{};
    std::string w{0};

    //Decision loop for blue peg input
    if (decision_blue!='n')
    {
        label:  
        std::cout<<"\nWhere to place blue pegs ";
        std::cout << "( ";
        size_t j{0};

        //displaying remaining indices of 2d array after the red and green insertion peg programs
        for (size_t i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if(numbers[i][j]>="1" && numbers[i][j]<="9"){
                    std::cout << numbers[i][j]<< ", ";
                }
            }
        }
        std::cout << ") ? "; 
        /**
         * @brief Loop for delimited push back of v6 strings, 
         * terminates when the user presses enter
         */
        while(true){
            std::cin >> w;
            v6.push_back(w);
            if(std::cin.peek() == '\n') {
                    // Leave the for loop
                    break;
            }
        }

        /**
         * @brief   User input validity check from vector, 
         * if incorrect jumps back to user input of blue pegs again 
         */
        int inc_ip_flag3{0};
        size_t array_size1 = v6.size();
        for (size_t m{0}; m < array_size1; ++m) 
        {
            if(v6.at(m)>="9" && v6.at(m)<="1"){
                inc_ip_flag3+=1;
            }  
        }
        if (inc_ip_flag3>0)  
        {
            goto label;
        }
        /**
         * @brief   Array conflict check loop
         * ensures user doesn't enter same responses again 
         * 
         */
        int flag{0};
        for (size_t i = 0; i < 3; i++)
        {
            for(size_t n=0;n<3;n++)
            {
                size_t array_size = v6.size();
                for (size_t m{0}; m < array_size; ++m) 
                {
                    if(numbers[i][n].compare(v6.at(m))==0){
                        flag+=1;
                    }
                }
            }
        }
        if (flag==0)
        {
            v6.clear();
            goto label;
        }
    }
    std::cout << "\n-----------------------------------";
    std::cout<<"\n";
    //Blue peg insertion loop starts here
    for (auto i = 0; i < 3 ; i++)
    {
        size_t array_size = v6.size();
        for (auto k = 0; k < 3; k++)
        {
            for (size_t m{0}; m < array_size; ++m) 
            {
                if(numbers[i][k].compare(v6[m])==0)
                {
                    numbers[i][k]='b';
                }
            }  
        }
    }
    //Final 2d array display
    for (auto i = 0; i < 3 ; i++)
    {
        for (auto k = 0; k < 3; k++)
        {
            std::cout << numbers.at(i).at(k)<<" ";
        }
        std::cout << "\n";
    }
    
    //Final call loop to get user choice validate and rerun the program if required
    char final_call{};
    while(true){
        std::cout << "\nTry again (y, n)? ";
        std::cin>>final_call;
        if (final_call!='y'&&final_call!='n')
        {
            continue;
        }
        else{
            break;
        }
    } 
    if (final_call=='y'||final_call=='Y')
    {
        goto start;
    }
}
