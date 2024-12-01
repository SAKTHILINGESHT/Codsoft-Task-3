#include <iostream>
#include <vector>

using namespace std;


void printBoard(const vector<vector<char> >& board) {
    cout << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
    cout << endl;
}


bool checkWin(const vector<vector<char> >& board, char player) {
    
    for (int i = 0; i < 3; i++) {
      
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
      
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
   
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    
    return false;
}


bool checkDraw(const vector<vector<char> >& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')  
                return false;
        }
    }
    return true;
}


void getValidMove(vector<vector<char> >& board, char player) {
    int move;
    while (true) {
        cout << "Player " << player << ", enter your move (1-9): ";
        cin >> move;
        
     
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

      
        if (move < 1 || move > 9 || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
        } else {
            board[row][col] = player;
            break;
        }
    }
}


void playGame() {
    vector<vector<char> > board(3, vector<char>(3, ' ')); 
    char currentPlayer = 'X'; 

    while (true) {
        printBoard(board);  

        getValidMove(board, currentPlayer); 

     
        if (checkWin(board, currentPlayer)) {
            printBoard(board); 
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

       
        if (checkDraw(board)) {
            printBoard(board); 
            cout << "It's a draw!" << endl;
            break;
        }

        
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

   
    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;
    if (playAgain == 'y' || playAgain == 'Y') {
        playGame(); 
    }
}

int main() {
    playGame(); 
    return 0;
}
