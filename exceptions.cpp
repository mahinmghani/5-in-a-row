#include "exceptions.h"
#include <iostream>
#include <exception>
#include <vector>
#include <cstdlib>



void clear_buffer() {                                                                               //For clearing the buffer
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
} 

void exceptionHandling(int &variable){
    char buffer;
    while (true){
        try
        {
            while (!(std::cin >> variable)){
                clear_buffer();
                throw Invalid_Input();
            }
            if (variable == 1 || variable == 0){
                buffer = std::cin.peek();
                //std::cout << "buffer is " << buffer << " this"; 
                if(buffer != '\n'){
                    clear_buffer();
                    throw Invalid_Input();                
                }
                return;
            }
            else{
                clear_buffer();
                throw Invalid_Input();                
            }
        }   
        catch(Invalid_Input e)
        {
            std::cout << e.what() << '\n';
        }
        std::cout << "Please re-enter your choice either '1' or '0': ";
    }
}

void exceptionHandling (int &variable, std::string t){                                                        //For entering the row and column of a game
    char buffer;
    while (true){
        try
        {
            while (!(std::cin >> variable)){
                clear_buffer();
                throw Invalid_Input();
            }
            if ((variable >= 1) && (variable <= 5)){
                buffer = std::cin.peek();
                if (buffer !='\n'){
                    clear_buffer();
                    throw Invalid_Input();
                }
                return;
            }
            else{
                clear_buffer();
                throw Invalid_Input();                
            }
        }   
        catch(Invalid_Input e)
        {
            std::cout << e.what() << '\n';
        }
        std::cout << "Please re-enter your " << t << " you want to move (1 - 5): ";
    }
}

