#include <iostream>
#include <exception>
#include <vector>
#include <cstdlib>

#include "board.h"
#include "exceptions.h"


/* =================

MAIN FUNCTION

================= */


int main(){
    int startPoint;
    bool temp;

    do{
        game GRIMES;                                                                                    //Random object named GRIMES has been created
        GRIMES.welcomeMessage();

        GRIMES.getMarks();                                                                              //Getting the user mark and then putting the mark for computer
        //Deciding who gets to start the game and thus continuing the game ; 1 means USER starts
        startPoint = GRIMES.whoStarts();
        
        if (startPoint == 1){
            do{
                GRIMES.getRowColUser();
                GRIMES.showBoardUser();
                GRIMES.computerMove(); 
                GRIMES.showBoardPC();
            } while (!GRIMES.gameStatus() && !GRIMES.Winner());
            if (GRIMES.gameStatus())
                std::cout << "Game is drawn!" <<std::endl;
        }
        else{
            do{
                GRIMES.computerMove();
                GRIMES.showBoardPC();
                GRIMES.getRowColUser();
                GRIMES.showBoardUser();
            } while (!GRIMES.gameStatus() && !GRIMES.Winner());
            if (GRIMES.gameStatus())
                std::cout << "Game is drawn!" <<std::endl;
        }
        temp = GRIMES.continuePlaying();
    } while (temp);
    

    return 0;
}


