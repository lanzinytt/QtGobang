int const BOARD_SIZE = 15;

void initBoard(int board[BOARD_SIZE][BOARD_SIZE]){
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

bool isValidMove(int board[BOARD_SIZE][BOARD_SIZE], int row, int col){
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        return false;
    }
    if (board[row][col] != 0) {
        return false;
    }
    return true;
}

void makeMove(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int player){
    board[row][col] = player;
}


bool isGameOver(int board[BOARD_SIZE][BOARD_SIZE]){
    // check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE - 3; j++) {
            if (board[i][j] == board[i][j+1] && board[i][j] == board[i][j+2] && board[i][j] == board[i][j+3]) {
                return true;
            }
        }
    }
    // check columns
    for (int i = 0; i < BOARD_SIZE - 3; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == board[i+1][j] && board[i][j] == board[i+2][j] && board[i][j] == board[i+3][j]) {
                return true;
            }
        }
    }
    // check diagonals
    for (int i = 0; i < BOARD_SIZE - 3; i++) {
        for (int j = 0; j < BOARD_SIZE - 3; j++) {
            if (board[i][j] == board[i+1][j+1] && board[i][j] == board[i+2][j+2] && board[i][j] == board[i+3][j+3]) {
                return true;
            }
        }
    }
    for (int i = 0; i < BOARD_SIZE - 3; i++) {
        for (int j = 3; j < BOARD_SIZE; j++) {
            if (board[i][j] == board[i+1][j-1] && board[i][j] == board[i+2][j-2] && board[i][j] == board[i+3][j-3]) {
                return true;
            }
        }
    }
    return false;
}