#include <iostream>
#include <string>


class TicTacToe {

    //everything below can not be changed during the game
    
    private:
    //Start with empty board will be soon be filled with inputs
    char board[3][3] = { {'.', '.', '.'}, {'.', '.', '.'}, {'.', '.', '.'} };

    //Will be later be X for player 1 and O for player 2, this is also used as the input for the board
    char currentPlayer = 'X';

    //iterating for every move switch
    int moveCount = 0;



    // public functions to be used later in the main
    public:

    //display board with every new move
    void displayBoard() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << board[i][j];
                std::cout << " ";
    }
            std::cout << std::endl;
    }
    };

    //row # and col# will be passed through for validation
    bool isValidMove(int row, int col) {
        //this only lets valid moves to be made
        if (row < 0 || row >= 3 || col < 0 || col >= 3) {
            return false;
        }
        //this checks if they are emoty
        if (board[row][col] != '.') {
            return false;
    } else {
        return true;
    }
    };

    //moves will be made here
    void makeMove(int row, int col) {
        //after validmove return true, this will make the move
        if (isValidMove(row, col) == true) {
            board[row][col] = currentPlayer;
            moveCount++;
        } else {
            std::cout << "not valid move set. try again." << std::endl;
        }
    }
    bool checkWinner();
    bool isDraw();

    //switching players after every valid and correct move 
    void switchPlayer() {
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        } else {
            currentPlayer = 'X';
        }
        std::cout << "player: " << currentPlayer << " turn." << std::endl;
        std::cout << "total moves made: " << moveCount << std::endl;
    }



    void rules() {
        std::cout << "tictactoe rules:" << std::endl;
        std::cout << "1. player X will always go first" << std::endl;
        std::cout << "2. row & column's valid input is 0, 1, or 2" << std::endl;
        std::cout << "for example, (R, C) to place in center, it would be (1, 1)" << std::endl;
        std::cout << "3. first to get three of their type in a row in any direction will WIN" << std::endl;
    }

};

int main() {
    char userInput;
    bool ready = false;
    TicTacToe game;
    int row, col;
    bool Winner = false;

    //Waiting for the user to be ready to play 
    while (!ready) {
        std::cout << "Are you ready to play Tic Tac Toe? (y/n): ";
        std::cin >> userInput;
    if (userInput == 'y' || userInput == 'Y') {
        ready = true;
        userInput = ' ';
    } else if (userInput == 'n' || userInput == 'N') {
        std::cout << "okay see you later" << std::endl;
        return 0;
    } else {
        std::cout << "Invalid input. Please enter 'y' or 'n'." << std::endl;
    };
    };

    game.rules();
    game.displayBoard();



    while (!Winner) {

    while (game.isValidMove(row, col) == false) {
        std::cout << "where would you want to place your piece?" << std::endl;


        //asks for input and retrieves it
        std::cout << "Enter your move (R, C): ";
        std::cout << "row: ";
        std::cin >> row;
        std::cout << "column: ";
        std::cin >> col;
        if (game.isValidMove(row, col) == false) {
            std::cout << "Invalid move. Try again." << std::endl;
            game.displayBoard();
        } 

    }

    game.makeMove(row, col);

    game.displayBoard();

    //needs to validate winner before switcing because what is the point

    

    game.switchPlayer();

    }

    return 0;

}