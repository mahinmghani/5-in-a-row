#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
#include <exception>
#include <vector>
#include <cstdlib>

/* =================

GAME CLASS

================= */

class game{
private:
    char playerMark, computerMark;
    int rowNum, colNum;
    int rowNumPC, colNumPC;
    int startingPoint;
    int newGameStarter;
    std::vector <std::vector <char> > board;                                                                //Creation of vector of vectors for the 5x5 board

public:

    game();                                                                                                 //Default constructor, constructs with empty vector
    void getMarks();
    bool continuePlaying();
    void computerMove();
    void showBoardUser();                                                                                   //Function to display the board after the user's move
    void showBoardPC();                                                                                     //Function to display the board after the computer's move
    bool Winner();                                                                                          //Checks if there is a winner or not
    void welcomeMessage();                                                                                  //Function to display the welcome message; 30 black spaces used
    int whoStarts();                                                                                        //Note for Programmer: Integer return value is needed
    void getRowColUser();                                                                                   //To get the row and column move from user, accepts only when a spot is free
    bool gameStatus();                                                                                      //Returns true if the whole board is occupied
};  


#endif