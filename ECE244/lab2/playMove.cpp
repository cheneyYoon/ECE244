//
//  playMove.cpp
//  TicTacToe
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//
//  ECE244 Student: write your code for playMove in this file

#include "globals.h"
#include "GameState.h"

void winCodeState(GameState& game_state) {


 game_state.set_winCode(0);
    
 if ( (game_state.get_gameBoard(0,2) == O && game_state.get_gameBoard(1,1) == O && game_state.get_gameBoard(2,0) == O) || 
    (game_state.get_gameBoard(0,2) == X && game_state.get_gameBoard(1,1) == X && game_state.get_gameBoard(2,0) == X) ) {
        game_state.set_gameOver(true);
     
        if (game_state.get_winCode() <= 8) 
            game_state.set_winCode(8);
        
    }

 if ( (game_state.get_gameBoard(2,2) == O && game_state.get_gameBoard(1,1) == O && game_state.get_gameBoard(0,0) == O) || 
    (game_state.get_gameBoard(2,2) == X && game_state.get_gameBoard(1,1) == X && game_state.get_gameBoard(0,0) == X) ) {
        game_state.set_gameOver(true);
     
        if (game_state.get_winCode() <= 7) 
            game_state.set_winCode(7);
        
    } 
   
 if ( (game_state.get_gameBoard(2,2) == O && game_state.get_gameBoard(1,2) == O && game_state.get_gameBoard(0,2) == O) || 
    (game_state.get_gameBoard(2,2) == X && game_state.get_gameBoard(1,2) == X && game_state.get_gameBoard(0,2) == X) ) {
        game_state.set_gameOver(true);
     
        if (game_state.get_winCode() <= 6) 
            game_state.set_winCode(6);
        
    } 

 if ( (game_state.get_gameBoard(2,1) == O && game_state.get_gameBoard(1,1) == O && game_state.get_gameBoard(0,1) == O) || 
    (game_state.get_gameBoard(2,1) == X && game_state.get_gameBoard(1,1) == X && game_state.get_gameBoard(0,1) == X) ) {
        game_state.set_gameOver(true);
     
        if (game_state.get_winCode() <= 5) 
            game_state.set_winCode(5);
        
    } 
        
 if ( (game_state.get_gameBoard(2,0) == O && game_state.get_gameBoard(1,0) == O && game_state.get_gameBoard(0,0) == O) || 
    (game_state.get_gameBoard(2,0) == X && game_state.get_gameBoard(1,0) == X && game_state.get_gameBoard(0,0) == X) ) {
        game_state.set_gameOver(true);
     
        if (game_state.get_winCode() <= 4) 
            game_state.set_winCode(4);
        
    } 

 if ( (game_state.get_gameBoard(2,2) == O && game_state.get_gameBoard(2,1) == O && game_state.get_gameBoard(2,0) == O) || 
    (game_state.get_gameBoard(2,2) == X && game_state.get_gameBoard(2,1) == X && game_state.get_gameBoard(2,0) == X) ) {
        game_state.set_gameOver(true);
     
        if (game_state.get_winCode() <= 3) 
            game_state.set_winCode(3);
        
    } 

 if ( (game_state.get_gameBoard(1,0) == O && game_state.get_gameBoard(1,1) == O && game_state.get_gameBoard(1,2) == O) || 
    (game_state.get_gameBoard(1,0) == X && game_state.get_gameBoard(1,1) == X && game_state.get_gameBoard(1,2) == X) ) {
        game_state.set_gameOver(true);
     
        if (game_state.get_winCode() <= 2) 
            game_state.set_winCode(2);
        
    } 

 if ( (game_state.get_gameBoard(0,0) == O && game_state.get_gameBoard(0,1) == O && game_state.get_gameBoard(0,2) == O) || 
    (game_state.get_gameBoard(0,0) == X && game_state.get_gameBoard(0,1) == X && game_state.get_gameBoard(0,2) == X) ) {
        game_state.set_gameOver(true);
     
        if (game_state.get_winCode() <= 1) 
            game_state.set_winCode(1);
        
    } 

int emptyBlock = 0;

 if (game_state.get_winCode() == 0) {

        for ( int i = 0 ; i < boardSize; i++) {
            for ( int j = 0 ; j < boardSize; j++) {
                if (game_state.get_gameBoard(i, j) == Empty) {
                    
                    emptyBlock++;
                }
            }
        }
        if (game_state.get_winCode() == 0 && emptyBlock == 0) {
            game_state.set_gameOver(true);
            game_state.set_winCode(0);
            
        }
    }

}


void playMove(GameState& game_state) {

game_state.set_moveValid(true);

     if ( (game_state.get_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn()) == Empty) 
            && game_state.get_gameOver() == false) {
                 if (game_state.get_turn() == false) {
                        game_state.set_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn(), O);
                        game_state.set_turn(true);
                    }
                else if (game_state.get_turn() == true) {
                            game_state.set_gameBoard(game_state.get_selectedRow(), game_state.get_selectedColumn(), X);
                            game_state.set_turn(false);
                    }     
    }
    
    else if (game_state.get_gameOver() == false) {        
            
            game_state.set_moveValid(false);
            
            if (game_state.get_turn() == false) {
                    game_state.set_turn(false);
                }
            else if (game_state.get_turn() == true) {
                        game_state.set_turn(true);
            }
    }
 
 winCodeState(game_state); 

}






  

