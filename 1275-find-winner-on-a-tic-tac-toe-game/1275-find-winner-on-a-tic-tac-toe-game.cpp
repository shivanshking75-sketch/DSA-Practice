class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int movesPerformed = moves.size();

        fillBoard(moves);

        if (isWinner(0) || isWinner(1)) {
            return (isWinner(0)) ? "A" : "B";
        }

        if (pendingMoves(movesPerformed)) {
            return "Pending";
        }

        return "Draw";
    }

private:
    const int rows = 3;
    const int cols = 3; 
    const int totalMoves = rows * cols;
    const int totalPlayers = 2;

    vector<vector<int>> board = vector<vector<int>>(rows, vector<int>(cols, -1));

    void fillBoard(vector<vector<int>>& moves) {
        int playerToken = 0;

        for (vector<int>& move: moves) {
            int r = move[0];
            int c = move[1];

            board[r][c] = playerToken;

            playerToken = (playerToken + 1) % totalPlayers;
        }
    }

    bool pendingMoves(int movesPerformed) {
        return movesPerformed != totalMoves;
    }

    bool isWinner(int playerId) {
        return (winnerInRows(playerId) || winnerInColumns(playerId) || winnerInDiagonals(playerId));
    }

    bool winnerInRows(int playerId) {
        for (int r = 0; r < rows; r++) {
            if (winnerInRow(board[r], playerId)) {
                return true;
            }
        }

        return false;
    }

    bool winnerInRow(vector<int>& row, int playerId) {
        for (int playerToken: row) {
            if (playerToken != playerId) {
                return false;
            }
        }
            
        return true;
    }

    bool winnerInColumns(int playerId) {
        for (int c = 0; c < cols; c++) {
            if (winnerInColumn(c, playerId)) {
                return true;
            }
        }

        return false;
    }

    bool winnerInColumn(int c, int playerId) {
        for (int r = 0; r < rows; r++) {
            if (board[r][c] != playerId) {
                return false;
            }
        }
        
        return true;
    }

    bool winnerInDiagonals(int playerId) {
        return (winnerInMajorDiagonal(0, 0, playerId) || winnerInMinorDiagonal(0, cols - 1, playerId));
    }

    bool winnerInMajorDiagonal(int r, int c, int playerId) {
        while (r < rows && c < cols) {
            if (board[r][c] != playerId) {
                return false;
            }

            r += 1;
            c += 1;
        }

        return true;
    }

    bool winnerInMinorDiagonal(int r, int c, int playerId) {
        while (r < rows && c >= 0) {
            if (board[r][c] != playerId) {
                return false;
            }

            r += 1;
            c -= 1;
        }

        return true;
    }
};