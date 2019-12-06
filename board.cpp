#include "board.h"
#include "exceptions.h"

#include <iostream>
#include <exception>
#include <vector>
#include <cstdlib>


void game::getMarks(){  
    char buffer;                                   
    std::cout << "Please choose your mark either 'X' or 'O': ";
    while (true){
        try
        { 
            std::cin >> playerMark;
            if (playerMark == 'X' || playerMark == 'O'){
                buffer = std::cin.peek();
                if(buffer != '\n'){
                    clear_buffer();
                    throw Invalid_Input();
                }
                if (playerMark == 'X')                                                              //Getting the mark of the USER and then assigning mark to the computer
                    computerMark = 'O';
                else
                    computerMark = 'X';
                break;
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
        std::cout << "Please re-enter your choice either 'X' or 'O': ";
    }           
}

bool game::continuePlaying(){                                                                       //If the user continue playing
    std::cout << "Do you want to start a new game? (1 for yes, 0 for no): ";                       
    exceptionHandling(newGameStarter);
    if (newGameStarter == 1)                                                                        //True if user wants to keep playing
        return true;
    return false;
}

game::game(){                                                                                         //Construct the vector with ' ' 
    for (int i=0; i<5; i++){
        std::vector <char> temp;
        for (int j=0; j<5; j++){
            temp.push_back(' ');
        }
        board.push_back(temp);
    }
}




void game::computerMove(){
    int tempROW_PC, tempCOL_PC;
    tempROW_PC = ((rand() % 5) + 1);
    tempCOL_PC = ((rand() % 5) + 1);

    while ((board[tempROW_PC-1][tempCOL_PC-1]=='X') || (board[tempROW_PC-1][tempCOL_PC-1]=='O')){
        tempROW_PC = ((rand() % 5) + 1);
        tempCOL_PC = ((rand() % 5) + 1);        
    }
    rowNumPC = tempROW_PC;
    colNumPC = tempCOL_PC;
}

void game::showBoardUser(){                                                                               //Function to display the board
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (i==(rowNum-1) && j==(colNum-1)){
                board[i][j]=playerMark;
            }  
            std::cout << "  " << board[i][j] << "  ";
            if (j==4){break;}
            std::cout << "|";
        }
        if (i==4){break;}
        std::cout << std::endl;
        std::cout << "-----------------------------";
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
}

void game::showBoardPC(){                                                                                 //Function to display the board
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (i==(rowNumPC-1) && j==(colNumPC-1)){
                board[i][j]=computerMark;
            }
            std::cout << "  " << board[i][j] << "  ";
            if (j==4){break;}
            std::cout << "|";
        }
        if (i==4){break;}
        std::cout << std::endl;
        std::cout << "-----------------------------";
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
}


bool game::Winner(){
    for (int i=0; i<5; i++){
        if(board[i][0]==board[i][1] && board[i][0]==board[i][2] && board[i][0]==board[i][3] && board[i][0]==board[i][4]){
            if (board[i][0] == ' '){
                continue;
            }
            else if (board[i][0]==playerMark){
                std::cout << "Congrats! You win! Row " << i+1 << " is the same." << std::endl;
                return true;
            }
            else if (board[i][0]==computerMark){
                std::cout << "Computer wins! Row " << i+1 << " is the same." <<std::endl;
                return true;
            }
        }
        else 
            continue;
    }
    for (int i=0; i<5; i++){ 
        if(board[0][i]==board[1][i] && board[0][i]==board[2][i] && board[0][i]==board[3][i] && board[0][i]==board[4][i]){
            if (board[0][i]==' '){
                continue;
            }
            else if (board[0][i]==playerMark){
                std::cout << "Congrats! You win! Column " << i+1 << " is the same" << std::endl;
                return true;
            }
            else if (board[0][i]==computerMark){
                std::cout << "Computer win! Column " << i+1 << " is the same" << std::endl;
                return true;
            }
        }
        else 
            continue;
    }
    
    if (board[0][0]==board[1][1] && board[0][0]==board[2][2] && board[0][0]==board[3][3] && board[0][0]==board[4][4])
    {
        if (board[0][0]==' '){
            goto jmp;
        }
        else if (board[0][0]==playerMark){
            std::cout << "Congrats! You win! Left diagonal is the same" << std::endl;
            return true;
        }
        else if (board[0][0]==computerMark){
            std::cout << "Computer win! Left diagonal is the same" << std::endl;
            return true;
        }
    }
    
    jmp:if (board[0][4]==board[1][3] && board[0][4]==board[2][2] && board[0][4]==board[3][1] && board[0][4]==board[4][0])
    {
        if (board[0][4]==' '){
            goto jmp1;
        }
        else if (board[0][4]==playerMark){
            std::cout << "Congrats! You win! Right diagonal is the same" << std::endl;
            return true;
        }
        else if (board[0][4]==computerMark){
            std::cout << "Computer win! Right diagonal is the same" << std::endl;
            return true;
        }
    }
    jmp1:return false;
    
}

void game::welcomeMessage(){                                                                                  //Function to display the welcome message
    std::cout << "                              " << std::endl;                                         //30 blank spaces used 
    std::cout << "------------------------------" << std::endl;
    std::cout << "|  Welcome to Five in a ROW  |" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "                              " << std::endl;
}

int game::whoStarts(){                                                                                        //Note for Programmer: Integer return value is needed
    std::cout << "If you want to move first please enter 1, otherwise enter 0: ";                       //EXCEPTION HANDLING NEEDED!! 
    exceptionHandling(startingPoint);
    return startingPoint;
}


void game::getRowColUser(){                                                                                   //To get the row and column move from user, accepts only when a spot is free
    int tempROW, tempCOL;
    std::string r = "row", c="column";
    
    std::cout << "Please enter the row you want to move (1 - 5): ";
    exceptionHandling (tempROW, r);
    std::cout << "Please enter the column you want to move (1 - 5): ";
    exceptionHandling (tempCOL, c);
    while ((board[tempROW-1][tempCOL-1]=='X') || (board[tempROW-1][tempCOL-1]=='O')){
        std::cout << "This block is already taken, try another one!" << std::endl;
        std::cout << "Please enter the row you want to move (1 - 5): ";
        std::cin >> tempROW;
        std::cout << "Please enter the column you want to move (1 - 5): ";
        std::cin >> tempCOL;
    }
    rowNum = tempROW;
    colNum = tempCOL;   
}  

bool game::gameStatus(){                                                                                      //Returns true if the whole board is occupied
    int counter = 0;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (board[i][j] != ' '){
                counter++;
                
            }     
        }  
    }
    return counter == 25;
    /*
    if (counter==25)
        return true;
    return false;                                                                                       //Returns false if the board is still empty
    */
    
}



