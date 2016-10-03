#include <iostream>
using namespace std;


bool scanVertical(char (&TTTarray)[3][3], char target, int num);
bool scanHorizontal(char (&TTTarray)[3][3], char target, int num);
bool scanDiagonal(char (&TTTarray)[3][3], char target, int num);

//void checkForWin(/*PASS BY REFERENCE*/); // IGNORE THIS FOR 
bool checkForTwoX(char (&TTTarray)[3][3]);
bool checkForTwoO(char (&TTTarray)[3][3]);
bool checkForOneX(char (&TTTarray)[3][3]);

void insertX(char (&TTTarray)[3][3]);
//void insertO(/*PASS BY REFERENCE*/);

void printTTT(char (&TTTarray)[3][3]);

int main( ){

    char TTTarray[3][3] = { {'X','-','-'},
                            {'-','-','-'},
                            {'O','-','O'}};

    // char TTTarray[3][3] = { {'-','-','-'},
    //                         {'-','-','O'},
    //                         {'-','X','O'}};

    //char TTTarray[3][3] = { {'-','-','-'},
    //                        {'-','X','-'},
    //                        {'-','O','-'}};

    //char TTTarray[3][3] = { {'X','-','X'},
    //                        {'-','-','-'},
    //                        {'O','-','-'}};


    // char TTTarray[3][3] = { {'O','O','-'},
    //                        {'-','-','-'},
    //                        {'X','X','-'}};

    // char TTTarray[3][3] = { {'X','-','X'},
    //                        {'O','X','-'},
    //                        {'O','-','O'}};


    printTTT(TTTarray);

    insertX(TTTarray);

    printTTT(TTTarray);

    /*****************
    I have included the declaratoin of the array, initialized to - for each spot.
    The '-' represents an empty position.  You should fill it with either a 
    capital 'O' or a capital 'X'. I have also included a number of initialized arrays 
    to test; just comment out the ones you don't want for that moment
    *****************/
    return 0;   
}

void insertX(char (&TTTarray)[3][3]) {
    if (checkForTwoX(TTTarray)) return;
    else if (checkForTwoO(TTTarray)) return;
    else if (checkForOneX(TTTarray)) return;
    else TTTarray[0][0] = 'X';
}

bool scanVertical(char (&TTTarray)[3][3], char target, int num) {
    int count = 0;
    
    for (int column = 0; column < 3; column++) {

        for (int row = 0; row < 3; row++) {
            if (TTTarray[row][column] == target) {
                count++;
            } 
        }

        if (count == num) {
            if (num == 2) {
                for (int row = 0; row < 3; row++) {
                    if (TTTarray[row][column] == '-'){
                        TTTarray[row][column] = 'X';
                        return true;
                    }
                }
            } else
            if (num == 1) {
                for (int row = 0; row < 3; row++) {
                    if (TTTarray[row][column] == 'X') {
                        TTTarray[(row+2)%3][column] = 'X';
                        return true;
                    } 
                        
                }
            }
        }

        count = 0;
    } 

    return false; 
}

bool scanHorizontal(char (&TTTarray)[3][3], char target, int num) {
    int count = 0;
    
    for (int row = 0; row < 3; row++) {

        for (int column = 0; column < 3; column++) {

            if (TTTarray[row][column] == target) {
                count++;
            } 
        }

        if (count == num) {
            if (num == 2) {
                for (int column = 0; column < 3; column++) {
                    if (TTTarray[row][column] == '-') {
                        TTTarray[row][column] = 'X';
                        return true;
                    }
                }
            } else
            if (num == 1) {
                for (int column = 0; column < 3; column++) {
                    if (TTTarray[row][column] == 'X') {
                        TTTarray[row][(column+2)%3] = 'X';
                        return true;
                    }
                }
            }
        }
        count = 0;
    }
    return false;
}

bool scanDiagonal(char (&TTTarray)[3][3], char target, int num) {
    // Right diagonal
    int startRow = 0;
    int count = 0;

    // Scan '\' diagonal to see if it has two X's
    for (int column = 0; column < 3; column++) {
        if (TTTarray[(startRow+column)][column] == target) {
            count++;
        } 

        if (count == num) {
            // Scan again, find the open space
            if (count == 2) {
                for (int column = 0; column < 3; column++) {
                    if (TTTarray[(startRow+column)][column] == '-') {
                        TTTarray[(startRow+column)][column] = 'X';
                        return true;
                    }
                }
            } else 
            if (count == 1) {
                for (int column = 0; column < 3; column++) {
                    if (TTTarray[(startRow+column)][column] == 'X') {
                        TTTarray[((startRow+column)+2)%3][(column+2)%3] = 'X';
                        return true;
                    }
                }
            }
        } 
    }

    count = 0;
    startRow = 2;

    // Scan '/' diagonal to see if it has two X's
    for (int column = 0; column < 3; column++) {
        if (TTTarray[(startRow-column)][column] == target) {
            count++;
        } 

        if (count == num) {
            // Scan again, find the open space
            if (count == 2) {
                for (int column = 0; column < 3; column++) {
                    if (TTTarray[(startRow-column)][column] == '-') {
                        TTTarray[(startRow-column)][column] = 'X';
                        return true;
                    }
                }
            } else 
            if (count == 1) {
                for (int column = 0; column < 3; column++) {
                    if (TTTarray[(startRow-column)][column] == '-') {
                        TTTarray[((startRow-column)+2)%3][(column-2)%3] = 'X';
                        return true;
                    }
                }
            }
        } 
    }
    return false;
}


bool checkForTwoO(char (&TTTarray)[3][3]) {
    if (scanVertical(TTTarray, 'O', 2)) return true;
    if (scanHorizontal(TTTarray, 'O', 2)) return true;
    if (scanDiagonal(TTTarray, 'O', 2)) return true;
    return false;
}

bool checkForTwoX(char (&TTTarray)[3][3]) {
    if (scanVertical(TTTarray, 'X', 2)) return true;
    if (scanHorizontal(TTTarray, 'X', 2)) return true;
    if (scanDiagonal(TTTarray, 'X', 2)) return true;
    return false;
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



