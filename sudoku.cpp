#include <iostream>
#include <cstdlib>
#include <ctime>

class Sudoku {
private:
    int board[81] = {};
    bool isValidBoard();
    bool generateBoard(int currentIndex);
    bool isValidNumber(int newNumberIndex);

public:
    Sudoku();
    void printBoard();
};

Sudoku::Sudoku() {
    std::srand(std::time(nullptr));
    generateBoard(0);
}

bool Sudoku::isValidBoard() {
    for (int i = 0; i < 9; i++) {
        int counterVertical[10] = {};
        int counterHorizontal[10] = {};
        for (int j = 0; j < 9; j++) {
            int rowValue = board[i * 9 + j];
            int colValue = board[j * 9 + i];
            if (rowValue) {
                if (counterHorizontal[rowValue]) return false;
                counterHorizontal[rowValue]++;
            }
            if (colValue) {
                if (counterVertical[colValue]) return false;
                counterVertical[colValue]++;
            }
        }
    }
    for (int row = 0; row < 9; row += 3) {
        for (int col = 0; col < 9; col += 3) {
            int counterSquare[10] = {};
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int value = board[(row + i) * 9 + (col + j)];
                    if (value) {
                        if (counterSquare[value]) return false;
                        counterSquare[value]++;
                    }
                }
            }
        }
    }
    return true;
}

bool Sudoku::isValidNumber(int newNumberIndex){
    int row = newNumberIndex/9;
    int col = newNumberIndex%9;
    int counterRow [10] = {};
    int counterCol [10] = {};
    for(int i = 0; i<9; i++){
        int valueRow = board[row*9+i];
        int valueCol = board[i*9 + col];
        if(valueRow){
            if(counterRow[valueRow]) return false;
            counterRow[valueRow]++;
        }
        if(valueCol){
            if(counterCol[valueCol]) return false;
            counterCol[valueCol]++;
        }
    }
    int squarePointer = (row/3)*27+(col/3)*3;
    int counterSquare [10] = {};
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int squareValue = board[squarePointer + i*9 + j];
            if(squareValue){
                if(counterSquare[squareValue]) return false;
                counterSquare[squareValue]++;
            }
        }
    }
    return true;
}

bool Sudoku::generateBoard(int currentIndex) {
    if (currentIndex == 81) return true;
    int choice[9] = {};
    int chosen[10] = {};
    int randomNumber;
    for (int i = 0; i < 9; i++) {
        do {
            randomNumber = std::rand() % 9 + 1;
        } while (chosen[randomNumber]);
        chosen[randomNumber]++;
        choice[i] = randomNumber;
    }

    for (int i = 0; i < 9; i++) {
        board[currentIndex] = choice[i];
        if (isValidNumber(currentIndex)){
            if (generateBoard(currentIndex + 1)) return true;
        }
        board[currentIndex] = 0;
    }
    return false;
}

void Sudoku::printBoard() {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0) std::cout << '\n';
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0) std::cout << '\t';
            std::cout << '[' << board[i * 9 + j] << ']';
        }
        std::cout << '\n';
    }
}
