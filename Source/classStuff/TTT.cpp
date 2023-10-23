// Fill out your copyright notice in the Description page of Project Settings.


#include "TTT.h"

TTT::TTT()
{
#include <iostream>
#include <string>

    using namespace std;

    class TicTacToe
    {
    public:
        // TTT board, empty by default
        char board[3][3] =
        {
            {' ', ' ', ' '},
            {' ', ' ', ' '},
            {' ', ' ', ' '}
        };

        // used for keeping track what's in each space, and what value each player has
        enum Entry
        {
            EMPTY = ' ',
            PLAYER_ONE = 'x',
            PLAYER_TWO = 'o'
        };

        // predicted location of winning move
        int winLoc[2] =
        {
            {0},//column
            {0}//row
        };

        // has the board been completely filled?
        bool isFull()
        {
            bool result = true;

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (board[i][j] == Entry::EMPTY)
                        result = false;
                }
            }

            return result;
        }

        // has someone won?
        bool isVictory(Entry e)
        {

            // first col
            if (board[0][0] == (char)e && board[0][1] == (char)e && board[0][2] == (char)e)
            {
                return true;
            }

            // second col
            else if (board[1][0] == (char)e && board[1][1] == (char)e && board[1][2] == (char)e)
            {
                return true;
            }

            // third col
            else if (board[2][0] == (char)e && board[2][1] == (char)e && board[2][2] == (char)e)
            {
                return true;
            }

            // first row
            else if (board[0][0] == (char)e && board[1][0] == (char)e && board[2][0] == (char)e)
            {
                return true;
            }

            // second row
            else if (board[0][1] == (char)e && board[1][1] == (char)e && board[2][1] == (char)e)
            {
                return true;
            }

            // third row
            else if (board[0][2] == (char)e && board[1][2] == (char)e && board[2][2] == (char)e)
            {
                return true;
            }

            // diagonal 1
            else if (board[0][0] == (char)e && board[1][1] == (char)e && board[2][2] == (char)e)
            {
                return true;
            }

            // diagonal 2
            else if (board[0][2] == (char)e && board[1][1] == (char)e && board[2][0] == (char)e)
            {
                return true;
            }

            return false;
        }

        // can specified competitor win in the next move?
        //if so return true and store locaion in winLoc
        //i realized it's easiest for readability to inport the code from isVictory,
        // and replace the check for taken,
        // with a check for empty on one of the combination elements.
        bool canWin(Entry e)
        {//realized that i notated the reverse, it's winloc0 = row, winLoc1 = column
            // first col win possible
            if (board[0][0] == EMPTY && board[0][1] == (char)e && board[0][2] == (char)e)
            {
                winLoc[0] = 0;//column
                winLoc[1] = 0;//row
                return true;//competitor specified can win.
            }
            if (board[0][0] == (char)e && board[0][1] == EMPTY && board[0][2] == (char)e)
            {
                winLoc[0] = 0;//column
                winLoc[1] = 1;//row
                return true;//competitor specified can win.
            }
            if (board[0][0] == (char)e && board[0][1] == (char)e && board[0][2] == EMPTY)
            {
                winLoc[0] = 0;//column
                winLoc[1] = 2;//row
                return true;//competitor specified can win.
            }

            // second col
            else if (board[1][0] == EMPTY && board[1][1] == (char)e && board[1][2] == (char)e)
            {
                winLoc[0] = 1;//column
                winLoc[1] = 0;//row
                return true;//competitor specified can win.
            }
            else if (board[1][0] == (char)e && board[1][1] == EMPTY && board[1][2] == (char)e)
            {
                winLoc[0] = 1;//column
                winLoc[1] = 1;//row
                return true;//competitor specified can win.
            }
            else if (board[1][0] == (char)e && board[1][1] == (char)e && board[1][2] == EMPTY)
            {
                winLoc[0] = 1;//column
                winLoc[1] = 2;//row
                return true;//competitor specified can win.
            }

            // third col
            else if (board[2][0] == EMPTY && board[2][1] == (char)e && board[2][2] == (char)e)
            {
                winLoc[0] = 2;//column
                winLoc[1] = 0;//row
                return true;//competitor specified can win.
            }
            else if (board[2][0] == (char)e && board[2][1] == EMPTY && board[2][2] == (char)e)
            {
                winLoc[0] = 2;//column
                winLoc[1] = 1;//row
                return true;//competitor specified can win.
            }
            else if (board[2][0] == (char)e && board[2][1] == (char)e && board[2][2] == EMPTY)
            {
                winLoc[0] = 2;//column
                winLoc[1] = 2;//row
                return true;//competitor specified can win.
            }

            // first row 
            else if (board[0][0] == EMPTY && board[1][0] == (char)e && board[2][0] == (char)e)
            {
                winLoc[0] = 0;//column
                winLoc[1] = 0;//row
                return true;//competitor specified can win.
            }
            else if (board[0][0] == (char)e && board[1][0] == EMPTY && board[2][0] == (char)e)
            {
                winLoc[0] = 1;//column
                winLoc[1] = 0;//row
                return true;//competitor specified can win.
            }
            else if (board[0][0] == (char)e && board[1][0] == (char)e && board[2][0] == EMPTY)
            {
                winLoc[0] = 2;//column
                winLoc[1] = 0;//row
                return true;//competitor specified can win.
            }

            // second row
            else if (board[0][1] == EMPTY && board[1][1] == (char)e && board[2][1] == (char)e)
            {
                winLoc[0] = 0;//column
                winLoc[1] = 1;//row
                return true;//competitor specified can win.
            }
            else if (board[0][1] == (char)e && board[1][1] == EMPTY && board[2][1] == (char)e)
            {
                winLoc[0] = 1;//column
                winLoc[1] = 1;//row
                return true;//competitor specified can win.
            }
            else if (board[0][1] == (char)e && board[1][1] == (char)e && board[2][1] == EMPTY)
            {
                winLoc[0] = 2;//column
                winLoc[1] = 1;//row
                return true;//competitor specified can win.
            }

            // third row
            else if (board[0][2] == EMPTY && board[1][2] == (char)e && board[2][2] == (char)e)
            {
                winLoc[0] = 0;//column
                winLoc[1] = 2;//row
                return true;//competitor specified can win.
            }
            else if (board[0][2] == (char)e && board[1][2] == EMPTY && board[2][2] == (char)e)
            {
                winLoc[0] = 1;//column
                winLoc[1] = 2;//row
                return true;//competitor specified can win.
            }
            else if (board[0][2] == (char)e && board[1][2] == (char)e && board[2][2] == EMPTY)
            {
                winLoc[0] = 2;//column
                winLoc[1] = 2;//row
                return true;//competitor specified can win.
            }

            // diagonal 1
            else if (board[0][0] == EMPTY && board[1][1] == (char)e && board[2][2] == (char)e)
            {
                winLoc[0] = 0;//column
                winLoc[1] = 0;//row
                return true;//competitor specified can win.
            }
            else if (board[0][0] == (char)e && board[1][1] == EMPTY && board[2][2] == (char)e)
            {
                winLoc[0] = 1;//column
                winLoc[1] = 1;//row
                return true;//competitor specified can win.
            }
            else if (board[0][0] == (char)e && board[1][1] == (char)e && board[2][2] == EMPTY)
            {
                winLoc[0] = 2;//column
                winLoc[1] = 2;//row
                return true;//competitor specified can win.
            }

            // diagonal 2
            else if (board[0][2] == EMPTY && board[1][1] == (char)e && board[2][0] == (char)e)
            {
                winLoc[0] = 0;//column
                winLoc[1] = 2;//row
                return true;//competitor specified can win.
            }
            else if (board[0][2] == (char)e && board[1][1] == EMPTY && board[2][0] == (char)e)
            {
                winLoc[0] = 1;//column
                winLoc[1] = 1;//row
                return true;//competitor specified can win.
            }
            else if (board[0][2] == (char)e && board[1][1] == (char)e && board[2][0] == EMPTY)
            {
                winLoc[0] = 2;//column
                winLoc[1] = 0;//row
                return true;//competitor specified can win.
            }

            return false;//no winning moves detected
            //cout << "no win found \n";
        }

        // return size of the board; mostly just in case I wanted to make the board expandable
        int getSize()
        {
            return 3;
        }

        void dump()
        {
            cout << "----------------------------------------" << endl << endl;
            for (int i = 0; i < getSize(); i++)
            {
                for (int j = 0; j < getSize(); j++)
                {
                    cout << " | " << board[i][j] << " | ";
                }

                cout << endl;
            }
            cout << "----------------------------------------" << endl << endl;
        }//dump will be removed for gui

    };
}

TTT::~TTT()
{
}
