
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

static bool getHumanMove(int maxValue, TicTacToe::Entry human, TicTacToe& t)//this entire section will have to be reworked
{
    // check if player is able to move
    if (t.isVictory(t.PLAYER_ONE) || t.isVictory(t.PLAYER_TWO) || t.isFull())
        return true;

    int rowChoice = 0;
    int colChoice = 0;

    do {

        do {

            cout << "Enter column number (x) : 0 ... 2 : ";
            cin >> colChoice;
            cout << endl;

        } while (colChoice > maxValue || colChoice < 0);

        do {

            cout << "Enter row number (y) : 0 ... 2 : ";
            cin >> rowChoice;
            cout << endl;

        } while (rowChoice > maxValue || rowChoice < 0);


        if (t.board[rowChoice][colChoice] == t.EMPTY)
        {
            t.board[rowChoice][colChoice] = (char)human;

            return false;
        }

        else
        {
            cout << "Not a valid option! Please try again..." << endl;
        }


    } while (t.board[rowChoice][colChoice] != t.EMPTY);

    // move complete
    return false;
}

/*https://www.digitalocean.com/community/tutorials/random-number-generator-c-plus-plus
* https://learn.microsoft.com/en-us/cpp/cpp/enumerations-cpp?view=msvc-160
* test for instant win in one move
* test for player win in next move(block)
* if no win is immediately possible, and no block is necessary: pick at random
*/

static bool getComputerMove(TicTacToe::Entry computer, TicTacToe& t, TicTacToe::Entry human)
{
    // check if computer is able to move
    if (t.isVictory(t.PLAYER_ONE) || t.isVictory(t.PLAYER_TWO) || t.isFull())
        return true;

    // handle computer's move

    int rowChoice = 0;
    int colChoice = 0;

    //canWin notes:
    //p1 is human
    //returns bool, and sets winLoc to predicted location.
    //t.canWin(t.PLAYER_TWO);//checks if player two can win in next round
    //colChoice = t.winLoc[0]; winloc = {c,r}

    //previous issue: had rows and columns flipped
    //if player one is not failing to win, then they are about to win
    if (t.canWin(computer))
    {//if computer is about to win, then win. ignore human

        colChoice = t.winLoc[1];//set based on predictions

        rowChoice = t.winLoc[0];
        //cout << " win location Win: c" << colChoice << " r" << rowChoice << "\n";

        t.board[rowChoice][colChoice] = (char)computer;//send choice as computer

        return false;//exit
    }

    else if (t.canWin(human))
    {//if player is about to win, block

        colChoice = t.winLoc[1];//set based on predictions

        rowChoice = t.winLoc[0];

        //cout << " win location Block: c" << colChoice << " r" << rowChoice << "\n";
        t.board[rowChoice][colChoice] = (char)computer;//send choice as computer

        return false;//exit
    }
    /*
    * actually, i'm not a fan of this mindset, where center is most inportant.
    * as a player, i consider knowing exactly what my opponents first move is going to be sad, and sometimes boring.
    * most of the ai from older tictactoe games followed this religously.
    * as discussed in class, taking center has an almost equal chance of winning as it does tieing. aka good chance of not loosing, but thats it.
    * my prefernce is chaos, after consideration. try to win, otherwise chaos. at least for tic tac toe.
    */

    //not broken
    else//pick a spot at random, and try to play there.
    {
        do {

            // choose at random until we find a space that's empty
            do {

                rowChoice = rand() % ((t.getSize() - 0) + 1) + 0;

            } while (rowChoice > t.getSize() || rowChoice < 0);

            do {

                colChoice = rand() % ((t.getSize() - 0) + 1) + 0;

            } while (colChoice > t.getSize() || colChoice < 0);


            if (t.board[rowChoice][colChoice] == t.EMPTY)
            {
                t.board[rowChoice][colChoice] = (char)computer;

                //cout << " win location Rand: c" << colChoice << " r" << rowChoice << "\n";
                return false;//exit func
            }

            else
            {
                //cout << "Not a valid option! Please try again..." << endl;
            }


        } while (t.board[rowChoice][colChoice] != t.EMPTY);//while selected choice is not empty

    }

    // move complete
    return false;
}

// ----------------------------
// main
// ----------------------------

int main()
{
    TicTacToe t;
    TicTacToe::Entry human = TicTacToe::PLAYER_ONE;
    TicTacToe::Entry computer = TicTacToe::PLAYER_TWO;

    int maxValue = t.getSize();

    cout << "----------------------------------------" << endl;

    cout << "You are '" << (char)human << "', " <<
        "the computer is: '" << (char)computer << "'" << endl;

    cout << "----------------------------------------" << endl << endl;

    // run the game until one player isn't able to go again
    do
    {
        // show board
        t.dump();
    } while (!getHumanMove(maxValue, human, t) && !getComputerMove(computer, t, human));


    t.dump();

    cout << endl;
    
    //win testing
    if (t.isVictory(human))
        cout << "Human Victory" << endl;

    else if (t.isVictory(computer))
        cout << "Computer Victory" << endl;

    else if (t.isFull())
        cout << "Tie" << endl;

    return(0);
}