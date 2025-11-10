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
    };

    bool checkWinner() {
                //check for row winner
                    for (int i = 0; i < 3; ++i) {
                if (board[i][0] == currentPlayer &&
                    board[i][1] == currentPlayer &&
                    board[i][2] == currentPlayer) {
                        std::cout << currentPlayer << " wins!" << std::endl;
                        return true;
                    }
            }
            //checks for column winner
            for (int j = 0; j < 3; ++j) {
                if (board[0][j] == currentPlayer &&
                    board[1][j] == currentPlayer &&
                    board[2][j] == currentPlayer) {
                        std::cout << currentPlayer << " wins!" << std::endl;
                        return true;
                    }
            }
        //check for diagonol 
        // this can be checked with XOR or AND but if i have time
                if (board[1][1] == currentPlayer) {
                    if ( (board[0][0] == currentPlayer) && (board[2][2] == currentPlayer) ) {
                        std::cout << currentPlayer << " is the winner! " << " top right to bottom left diagonal win " << std::endl;
                        return true;
                    }
                    if ( (board[0][2] == currentPlayer) && (board[2][0] == currentPlayer) ) {
                        std::cout << currentPlayer << " is the winner! " << " bottom right to upper left diagonal win " << std::endl;
                        return true;
                    }
                    
                }
                return false;
            };




    //if moves matches the amount of marks on the board then this will execute
    bool isDraw() {
        if (moveCount == 9) {
            std::cout << "no one won this round" << std::endl;
            return true;
        }
        return false;
    }

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

    //play game also acts as a reset no matter the outcome of the game
    void playGame() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = '.';
            }
        }

            moveCount = 0;
            currentPlayer = 'X';
            rules();
            displayBoard();

    };


    //added this to display the rules of a new game
    void rules() {
        std::cout << "tictactoe rules:" << std::endl;
        std::cout << "1. player X will always go first" << std::endl;
        std::cout << "2. row & column's valid input is 1, 2, or 3" << std::endl;
        std::cout << "for example, (R, C) to place in center, it would be (2, 2)" << std::endl;
        std::cout << "3. first to get three of their type in a row in any direction will WIN" << std::endl;
    }

};

int main() {
    //variables
    char userInput;
    bool ready = false;
    TicTacToe game;
    int row, col;
    bool Winner = false;


    //Waiting for the user to be ready to play 
    while (ready == false) {
        std::cout << "are you ready to play Tic Tac Toe? (y/n): ";
        std::cin >> userInput;
    if (userInput == 'y' || userInput == 'Y') {
        game.rules();
        game.displayBoard();
        ready = true;
        userInput = ' ';
    } else if (userInput == 'n' || userInput == 'N') {
        std::cout << "okay see you later" << std::endl;
        return 0;
    } else {
        std::cout << "invalid input. please enter 'y' or 'n'." << std::endl;
    };
    };

    //while there is no winner this will continue to loop, the games logic
    while (!Winner) {

        std::cout << "where would you want to place your piece?" << std::endl;

        do {
        //asks for input and retrieves it
        std::cout << "enter row number: ";
        std::cin >> row;
        std::cout << "enter column number: ";
        std::cin >> col;
        
        //adjusted input to match the col and rows in the board arrays
        row -=1;
        col -=1;

        //move validator
        if (game.isValidMove(row, col) == false) {
            std::cout << "invalid move. try again." << std::endl;
            game.displayBoard();
        } 

    } while (game.isValidMove(row, col) == false);

    game.makeMove(row, col);
    game.displayBoard();

    //checks if there is winner
    if (game.checkWinner()) {
        std::cout << "we have a winner! ";
        Winner = true;
    } else if (game.isDraw()) {
        Winner = true;
    } 

    //if there is a winner ask for a another game
    if (Winner) {
        char anotherGame;
        std::cout << "would you like to play again? y/n?" << std::endl;
        std::cin >> anotherGame;

        if (anotherGame == 'y' || anotherGame == 'Y') {
            Winner = false;
            game.playGame();
        } else {
            std::cout << "see ya!" << std::endl;
            break;
        }
    
    //if no winner, rotate player turn
    } else {
        game.switchPlayer();
    }

    }

    return 0;

}