#include <iostream>

using namespace std;

class TicTacToe {
    public:
        TicTacToe() {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    board[i][j] = ' ';
                }
            }
        }

        void run() {
            bool isGameOver = false;
            bool isWinner = false;
            int currentPlayer = 1;
            cout << "-- Tic Tac Toe -- CSIE@CGU\n"  << "Player 1 (X) - Player 2 (O)\n" ;
            
            int n = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    board[i][j] = '1'+ n;
                    cout << board[i][j];
                    n++;
                        if (j < 2){
                            cout << " | " ;
                        }
                }
                cout << endl;
                if (i < 2){
                    cout << "----------" << endl;
                }
            }
            
            bool usedInputs[9] = {false}; 
            
            while (!isGameOver) {
                char input;
                cout << "Player " << currentPlayer << " 請輸入 1~9 的數字:";
                cin >> input;
                
                int index = input - '1';
                if(usedInputs[index]) {
                    cout << "Player " << currentPlayer << "請重新輸入未使用過的數字" << endl;
                    continue;
                }
                usedInputs[index] = true;

                int row = (input - '1') / 3;
                int col = (input - '1') % 3;
            
                if(currentPlayer == 1) {
                    board[row][col] = 'X';
                    
                } else {
                    board[row][col] = 'O';
                    
                }
                displayBoard();
                isGameOver = checkForWin() || check_tie();

                if(currentPlayer == 1) {
                    currentPlayer = 2;
                } else {
                    currentPlayer = 1;
                }
                
                if (checkForWin()) {
                    isWinner = true;
                    currentPlayer = (currentPlayer == 1) ? 2 : 1;
                    break;
                }
            }
            displayBoard();
            
            if (isWinner) {
                cout << "==> Player " << currentPlayer << " win" << endl;
            } else {
                cout << "==> Game draw" << endl;
            }
        }

    private:
        char board[3][3];

        bool checkForWin() {
            for (int i = 0; i < 3; i++) {
                if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
                    return true;
                }
            }

            for (int j = 0; j < 3; j++) {
                if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
                    return true;
                }
            }

            if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
                return true;
            }

            if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
                return true;
            }

            return false;
        }
        
        bool check_tie() {
            for(int i=0; i<3; i++) {
                for(int j=0; j<3; j++) {
                    if(board[i][j] != 'X' && board[i][j] != 'O') {
                        return false;
                    }
                }
            }
            return true;
        }

        void displayBoard() {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << board[i][j];
                        if (j < 2){
                            cout << " | " ;
                        }
                }
                cout << endl;
                if (i < 2){
                    cout << "----------" << endl;
                }
            }
        }
};

int main() {
    TicTacToe game;
    game.run();
    return 0;
}
