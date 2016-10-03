/******************************************
*   Template by Aaron Carpenter
*   ELEC 3150 - OOPs
*   EET Dept., WIT
*   Tic-Tac-Toe Lab (#6)
******************************************/

#include <iostream>
using namespace std;



void printTTT(char (&TTTarray)[3][3]);
void insertX(char (&TTTarray)[3][3]);
void insertO(/*PASS BY REFERENCE*/);
void checkForWin(/*PASS BY REFERENCE*/); // IGNORE THIS FOR 
void checkForTwo(char (&TTTarray)[3][3]);
bool twoVertical(char (&TTTarray)[3][3]);
bool twoHorizontal(char (&TTTarray)[3][3]);
bool twoDiagonal(char (&TTTarray)[3][3]);

int main( ){

    // char TTTarray[3][3] = { {'-','-','-'},
    //                         {'-','-','-'},
    //                         {'-','-','-'}};

    // char TTTarray[3][3] = { {'-','X','-'},
    //                         {'-','X','-'},
    //                         {'-','-','O'}};

    //char TTTarray[3][3] = { {'-','-','-'},
    //                        {'-','X','-'},
    //                        {'-','O','-'}};

    //char TTTarray[3][3] = { {'X','-','X'},
    //                        {'-','-','-'},
    //                        {'O','-','-'}};


    char TTTarray[3][3] = { {'O','O','-'},
                           {'-','-','-'},
                           {'X','X','-'}};

    // char TTTarray[3][3] = { {'X','-','X'},
    //                        {'O','X','-'},
    //                        {'O','-','O'}};


    printTTT(TTTarray);

    insertX(TTTarray);
    //OR
    insertO(/*CALL*/);

    printTTT(TTTarray);

    /*****************
    I have included the declaratoin of the array, initialized to - for each spot.
    The '-' represents an empty position.  You should fill it with either a 
    capital 'O' or a capital 'X'. I have also included a number of initialized arrays 
    to test; just comment out the ones you don't want for that moment
    *****************/
    return 0;   
}

void printTTT(char (&TTTarray)[3][3]) {
    cout << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << TTTarray[i][j];
        }
        cout << endl;
    }
}

void insertX(char (&TTTarray)[3][3]) {
    checkForTwo(TTTarray);
}

void checkForTwo(char (&TTTarray)[3][3]) {

    if (twoVertical(TTTarray)) return;

    else if (twoHorizontal(TTTarray)) return;

    else if (twoDiagonal(TTTarray)) return;
}

/*
 * See if there's any columns with two X's
 * Place an X in the empty spot
 * Simultaneously see if there's any columns with two X's
 * Defend appropriately
 */
bool twoVertical(char (&TTTarray)[3][3]) {

    int countX = 0,
        countO = 0;
    
    for (int column = 0; column < 3; column++) {

        for (int row = 0; row < 3; row++) {
            if (TTTarray[row][column] == 'X') {
                countX++;
            } else
            if (TTTarray[row][column] == 'O') {
                countO++;
            }
        }

        if (countX == 2) {
            for (int row = 0; row < 3; row++) {
                if (TTTarray[row][column] == '-'){
                    TTTarray[row][column] = 'X';
                    return true;
                }
            }
        } else 
        if (countO == 2) {
            for (int row = 0; row < 3; row++) {
                if (TTTarray[row][column] == '-'){
                    TTTarray[row][column] = 'X';
                    return true;
                }
            }
        }

        countX = 0;
        countO = 0;
    } 

    return false; 
}

/*
 * See if there's any rows with two X's
 * Place an X in the empty spot
 * Simultaneously see if there's any rows with two X's
 * Defend appropriately
 */
bool twoHorizontal(char (&TTTarray)[3][3]) {
    int countX = 0,
        countO = 0;
    
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            if (TTTarray[row][column] == 'X') {
                countX++;
            } else
            if (TTTarray[row][column] == 'O') {
                countO++;
            }
        }
        if (countX == 2) {
            for (int column = 0; column < 3; column++) {
                if (TTTarray[row][column] == '-'){
                    TTTarray[row][column] = 'X';
                    return true;
                }
            }
        } else 
        if (countO == 2) {
            for (int column = 0; column < 3; column++) {
                if (TTTarray[row][column] == '-'){
                    TTTarray[row][column] = 'X';
                    return true;
                }
            }
        }

        countX = 0;
        countO = 0;
    }
    return false;
}

bool twoDiagonal(char (&TTTarray)[3][3]) {
    // Right diagonal
    int seed = 0;
    int countX = 0,
        countO = 0;

    // Scan '\' diagonal to see if it has two X's
    for (int column = 0; column < 3; column++) {
        if (TTTarray[(seed+column)][column] == 'X') {
            countX++;
        } else
        if (TTTarray[(seed+column)][column] == 'O') {
            countO++;
        }

        // Scan again, find the open space
        if (countX == 2) {
            for (int column = 0; column < 3; column++) {
                if (TTTarray[(seed+column)][column] == '-') {
                    TTTarray[(seed+column)][column] = 'X';
                    return true;
                }
            }
        } else 
        if (countO == 2) {
            for (int column = 0; column < 3; column++) {
                if (TTTarray[(seed+column)][column] == '-') {
                    TTTarray[(seed+column)][column] = 'X';
                    return true;
                }
            }
        }
    }

    countX = 0;
    countO = 0;
    seed = 2;

    // Scan '/' diagonal to see if it has two X's
    for (int column = 0; column < 3; column++) {
        if (TTTarray[(seed-column)][column] == 'X') {
            countX++;
        } else
        if (TTTarray[(seed-column)][column] == 'O') {
            countO++;
        }

        // Scan again, find the open space
        if (countX == 2) {
            for (int column = 0; column < 3; column++) {
                if (TTTarray[(seed-column)][column] == '-') {
                    TTTarray[(seed-column)][column] = 'X';
                    return true;
                }
            }
        } else 
        if (countO == 2) {
            for (int column = 0; column < 3; column++) {
                if (TTTarray[(seed-column)][column] == '-') {
                    TTTarray[(seed-column)][column] = 'X';
                    return true;
                }
            }
        }
    }
    return false;
}



void insertO(/*PASS BY REFERENCE*/){

}
